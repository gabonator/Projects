#input=/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/goose/goose.cov
input=$1
exec=$(cat ${input} | grep 'info: executable' | awk '{print $4}')
args=$(cat ${input} | grep 'info: arguments' | awk '{for(i=4;i<=NF;i++) printf $i " "; print ""}')
basename=$(basename ${exec})
out=${1%.*}.cov
#out=coverage.cov
cat <<EOF > makecov.js
var id = process.argv[2]
var filename = process.argv[3]
var fs = require("fs")
var prefix = \`\${id} = (() => { var code="\`;
var suffix = \`"; return Uint8Array.from(atob(code), c => c.charCodeAt(0));})();\`;
console.log(prefix + fs.readFileSync(filename).toString("base64") + suffix);
EOF
node makecov.js cicoData ${exec} > ${out}
rm makecov.js
echo 'cicoArgs = `'"${args}"'`' >> ${out}
echo 'cicoText = `' >> ${out}
cat ${input} >> ${out}
echo '`' >> ${out}
