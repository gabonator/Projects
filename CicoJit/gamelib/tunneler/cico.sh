cico=/Users/gabrielvalky/Documents/git/Projects/CicoJit/cicodis/cicodis/cicodis
${cico} $PWD/dos/TUNNELER.EXE -load 01ed -ctx start -segofscomment -recursive \
  -indirect 0947:135d,08e1:03a4,08e1:0489,08e1:017a,0947:01bf,0947:01f0,08c0:006a \
> tunneler.clean

cp tunneler.clean tunneler.cpp
patch tunneler.cpp tunneler.patch


