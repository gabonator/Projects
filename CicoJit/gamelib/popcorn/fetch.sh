curl 'https://image.dosgamesarchive.com/games/arkclone-box.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-site' \
  --compressed -o popcorn.zip
unzip popcorn.zip -d dos

curl https://raw.githubusercontent.com/w4kfu/unEXEPACK/master/unpack.c -o unpack.c
gcc unpack.c -o unpack
./unpack dos/ARKCLONE/POPCORN.EXE dos/ARKCLONE/POPCORN.EXE
mv dos/ARKCLONE/* dos/
rm -rf dos/ARKCLONE

rm popcorn.zip unpack unpack.c