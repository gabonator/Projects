grep -E 'memoryASet16\(ds, (r16\[si\] \+ 50|r16\[di\] \+ 50|0x8252|0x6f0c),' js/keen1.js \
| grep -oE '0x[0-9a-fA-F]{4}\);' \
| sed 's/0x//; s/);//' \
| sort -u \
| awk '
BEGIN {
  printf "{\"id\": \"jumpTable\", \"addr\": \"01ed:4d26\", callsNear:["
}
{
  printf "%s\"01ed:%s\"", (NR>1?", ":""), $0
}
END {
  print "]}"
}'