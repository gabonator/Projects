curl 'https://www.retrogames.cz/dos/zip/Captain_Comic.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed -o Captain_Comic.zip
unzip Captain_Comic.zip -d dos
curl https://raw.githubusercontent.com/w4kfu/unEXEPACK/master/unpack.c -o unpack.c
gcc unpack.c -o unpack
./unpack dos/comic.exe dos/comic.exe
rm Captain_Comic.zip unpack unpack.c
