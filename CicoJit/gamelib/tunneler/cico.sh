cico=/Users/gabrielvalky/Documents/git/Projects/CicoJit/cicodis/cicodis/cicodis
${cico} $PWD/dos/TUNNELER.EXE -load 01ed -ctx start -segofscomment -negative 52000 -recursive \
  -indirect 0947:135d,08e1:03a4,08e1:0489,08e1:017a,0947:01bf,0947:01f0,08c0:006a \
> tunneler.clean

cp tunneler.clean tunneler.cpp
patch tunneler.cpp tunneler.patch
sed -E \
    -e 's/memoryASet16\(([^,]+), ([^,]+), (.+)\);/memory16(\1, \2) = \3;/' \
    -e 's/memoryAGet16\(([^,]+), ([^,]+)\)/memory16(\1, \2)/g' \
    -e 's/memoryASet\(([^,]+), ([^,]+), (.+)\);/memory(\1, \2) = \3;/' \
    -e 's/memoryAGet\(([^,]+), ([^,]+)\)/memory(\1, \2)/g' \
    -e 's/MemAuto/MemData/g' \
    -e 's/DirAuto/DirForward/g' \
  tunneler.cpp > tunneleropt.clean
cp tunneleropt.clean tunneleropt.cpp

patch tunneleropt.cpp tunneleropt.patch


