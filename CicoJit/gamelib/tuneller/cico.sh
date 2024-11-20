cico=/Users/gabrielvalky/Documents/git/Projects/CicoJit/cicodis/cicodis/cicodis
${cico} $PWD/dos/TUNNELER.EXE -reloc -stackguard -load 01ed -ctx start -segofscomment -recursive \
  -indirect 0947:135d,08e1:03a4,08e1:0489 \
> tunneler.clean

cp tunneler.clean tunneler.cpp
patch tunneler.cpp tuneller.patch


