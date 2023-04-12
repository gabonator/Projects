unzip rick1.zip -d dos
exit 0
curl 'https://www.retrogames.cz/dos/zip/RickDangerous.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed -o rickdangerous.zip
unzip rickdangerous.zip -d dos
rm rickdangerous.zip
