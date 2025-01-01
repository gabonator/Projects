cicodis=/Users/gabrielvalky/Documents/git/Projects/CicoJit/cicodis/cicodis/cicodis
#${cicodis} $(pwd)/dos/COSMO1.EXE 198b:0325 -asm -load 01ed && exit 0
${cicodis} $(pwd)/dos/COSMO1.EXE start -reloc -indirect 01ed:19f,01ed:dec,01ed:f80,18af:1dd,1813:f,198b:137,198b:165,17c0:f4,1a7c:8,198b:325,198b:367,02f1:1265,02f1:e6a3,02f1:e664,02f1:e562,02f1:e654,02f1:e64c,02f1:1031 -load 01ed -recursive -segofscomment -ctx -terminator 01ed:1c7 -stackguard > cosmo.clean
cp cosmo.clean cosmo.cpp
patch cosmo.cpp cosmo.patch
