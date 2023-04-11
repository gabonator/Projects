curl 'https://www.bestoldgames.net/download/games/nebulus/nebulus.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed -o nebulus.zip

unzip -d dos -j nebulus.zip \
  "Nebulus/NEBEGA.EXE" \
  "Nebulus/HISCORE.BIN"
rm nebulus.zip

curl https://raw.githubusercontent.com/w4kfu/unEXEPACK/master/unpack.c -o unpack.c
gcc unpack.c -o unpack
./unpack dos/NEBEGA.EXE dos/NEBEGA.EXE
rm unpack unpack.c