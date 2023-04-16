curl 'https://cors.archive.org/cors/ROCKFORD/ROCKFORD.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: cross-site' \
  --compressed -o rockford.zip
#unzip rockford.zip -d dos