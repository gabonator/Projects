set -e
mkdir -p temp
#TODO: av, bumpy
#TODO: fetch
#for fullpath in ./ref/*.txt; do
for fullpath in ./ref/keen1.txt ./ref/keen4.txt ./ref/rick1.txt ./ref/rick2.txt ./ref/wormsfull.txt ./ref/goose.txt ./ref/fox.txt ./ref/mm2.txt; do
  filename="$(basename $fullpath)"
  project="${filename%.txt}"
  echo "Processing $project"
  (
    cd ref
    ../cicodis ${project}.txt > ../temp/code
    rm -f *.bin
  )
  if [ -e "ref/${project}.patch" ]; then
    patch temp/code ref/${project}.patch
  fi
  git diff --color=always --no-index ref/${project}.cpp temp/code
# | cat || true
done