grep -E 'memoryASet16\(ds, r16\[si\] \+ 34|r16\[di\] \+ 34),' js/keen1.js \
| grep -oE '0x[0-9a-fA-F]{4}\);' \
| sed 's/0x//; s/);//' \
| sort -u \
| awk '
BEGIN {
  printf "{\"id\": \"jumpTable\", \"addr\": \"01ed:4ee1\", callsNear:["
}
{
  printf "%s\"01ed:%s\"", (NR>1?", ":""), $0
}
END {
  print "]}"
}'