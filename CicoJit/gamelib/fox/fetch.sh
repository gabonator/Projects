curl 'https://www.retrogames.cz/dos/zip/Titus.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed --output titus.zip

unzip -o -d dos -j titus.zip \
  "FONTS.SQZ" \
  "LEVEL0.SQZ" \
  "LEVEL1.SQZ" \
  "LEVEL2.SQZ" \
  "LEVEL3.SQZ" \
  "LEVEL4.SQZ" \
  "LEVEL5.SQZ" \
  "LEVEL6.SQZ" \
  "LEVEL7.SQZ" \
  "LEVEL8.SQZ" \
  "LEVEL9.SQZ" \
  "LEVELA.SQZ" \
  "LEVELB.SQZ" \
  "LEVELC.SQZ" \
  "LEVELE.SQZ" \
  "LEVELG.SQZ" \
  "LEVELJ.SQZ" \
  "MENU.SQZ" \
  "MENUEGA.SQZ" \
  "SPREXP.SQZ" \
  "TITRE.SQZ" \
  "TITREEGA.SQZ" \
  "TITUS.SQZ"

unzip -o unpacked.zip -d dos
rm titus.zip