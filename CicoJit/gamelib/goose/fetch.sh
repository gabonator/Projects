curl 'https://online.oldgames.sk/api/getrom/8807' -H 'sec-fetch-site: same-origin' --compressed -o goose.zip
unzip -o -d dos -j goose.zip \
  "Goose/GOOSE.EXE" \
  "Goose/BIRD1.X" \
  "Goose/BIRD2.X" \
  "Goose/BLOX.X" \
  "Goose/INTRO.X" \
  "Goose/NEWBIRD.X" \
  "Goose/PODZ1.X" 
rm goose.zip
