curl 'https://www.retrogames.cz/dos/zip/prehist.zip' \
  --compressed -o prehist.zip
unzip prehist.zip -d dos
# pklite
unzip -o unpacked.zip -d dos
rm prehist.zip
