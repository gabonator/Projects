curl 'https://vfat.classicreload.com/msdos_Rockford_-_The_Arcade_Game_1987/Rockford_-_The_Arcade_Game_1987.zip' -H 'origin: https://classicreload.com' -o rockford.zip
unzip rockford.zip -d dos
mv dos/Rockford/* dos
rm -rf dos/Rockford
rm dos/ROCKFORD.EXE
unzip unpacked -d dos
rm rockford.zip