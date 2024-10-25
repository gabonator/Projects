curl 'https://www.retrogames.cz/dos/zip/CCaves_1.zip' \
  -H 'authority: www.retrogames.cz' \
  -H 'accept: */*' \
  -H 'accept-language: en-GB,en-US;q=0.9,en;q=0.8,sk;q=0.7' \
  -H 'cache-control: no-cache' \
  -H 'cookie: _ga=GA1.2.1388511263.1677430014; __atssc=google%3B1; language=CZ; pocitadlo524DOS=1; _gid=GA1.2.1846228365.1682933480; _gat_gtag_UA_121663504_1=1; cas524DOS=1682933480; __atuvc=2%7C14%2C11%7C15%2C6%7C16%2C6%7C17%2C1%7C18; __atuvs=644f86e87aefd89f000; _awl=2.1682933481.5-0dfef564811ebfdc1ddb692627dbeb59-6763652d6575726f70652d7765737431-1' \
  -H 'pragma: no-cache' \
  -H 'referer: https://www.retrogames.cz/play_524-DOS.php' \
  -H 'sec-ch-ua: "Google Chrome";v="111", "Not(A:Brand";v="8", "Chromium";v="111"' \
  -H 'sec-ch-ua-mobile: ?0' \
  -H 'sec-ch-ua-platform: "macOS"' \
  -H 'sec-fetch-dest: empty' \
  -H 'sec-fetch-mode: cors' \
  -H 'sec-fetch-site: same-origin' \
  -H 'user-agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36' \
  --compressed -o crystal.zip
unzip crystal.zip -d dos