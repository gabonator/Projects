cico=/Users/gabrielvalky/Documents/git/Projects/CicoJit/cicodis/cicodis/cicodis
#${cico} $PWD/dos/CERVII.EXE -load 01ed -segofscomment -asm a08:d86 && exit 0
${cico} $PWD/dos/CERVII.EXE -load 01ed -segofscomment -ctx start -recursive -terminator 01ed:4676 \
 -indirect 0a08:060c,09a6:035a,09a6:0470,09a6:043f,0655:00b7,0655:00d0,0655:0055,0655:a3 > cervi.clean
cp cervi.clean cervi.cpp
patch cervi.cpp cervi.patch
