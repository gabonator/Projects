curl 'https://www.retrogames.cz/dos/zip/ArcadeVolleyball.zip' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  --compressed -o av.zip
unzip av.zip -d dos
rm av.zip