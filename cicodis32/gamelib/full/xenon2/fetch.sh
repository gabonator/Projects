rm -rf dos

curl --url 'https://online.oldgames.sk/api/getrom/764' -H 'sec-fetch-site: same-origin' --output xenon.zip

unzip xenon.zip -d dos/
mv dos/XENON2/* dos/
rm xenon.zip