curl 'https://www.retrogames.cz/dos/zip/AlleyCat.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed -o alleycat.zip
unzip -d dos -j alleycat.zip
rm alleycat.zip