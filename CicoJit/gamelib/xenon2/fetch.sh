rm -rf dos
curl 'https://online.oldgames.sk/api/getrom/10183' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed -o xenon.zip
unzip xenon.zip -d dos/
mv dos/XENON2/* dos/
rm xenon.zip