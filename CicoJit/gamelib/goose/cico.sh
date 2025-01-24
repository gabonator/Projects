args="$PWD/dos/GOOSE.EXE \
  -simplestack -ctx -recursive start,sub_133d7+sync \
  -jumptable 1000:104e 1000:105a 35 callwords bx"
coverage="-asm -coverage -reloc -tree"

# coverage
../../cicodis/cicodis/cicodis ${coverage} ${args} > goose.cpp
../../cicocov/coverage.sh goose.cpp
echo '<script src="goose.cov"></script>' > coverage.html
cat ../../cicocov/coverage.html >> coverage.html
mv coverage.html coverage
mv goose.cov coverage

# main
../../cicodis/cicodis/cicodis ${args} > goose.cpp

# js
sed -E \
    -e 's/memoryASet16\(([^,]+), ([^,]+), (.+)\);/memory16(\1, \2) = \3;/' \
    -e 's/memoryAGet16\(([^,]+), ([^,]+)\)/memory16(\1, \2)/g' \
    -e 's/memoryASet\(([^,]+), ([^,]+), (.+)\);/memory(\1, \2) = \3;/' \
    -e 's/memoryAGet\(([^,]+), ([^,]+)\)/memory(\1, \2)/g' \
    -e 's/MemAuto/MemData/g' \
    -e 's/DirAuto/DirForward/g' \
  goose.cpp > gooseopt.clean
cp gooseopt.clean gooseopt.cpp
patch gooseopt.cpp gooseopt.patch

