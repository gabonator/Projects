set -e
mkdir -p temp
#TODO: av, bumpy
for fullpath in ./ref/av*.txt; do
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