curl "https://www.retrogames.cz/dos/zip/Rick2.zip" -o rick2.zip
unzip -o rick2.zip -d dos
rm rick2.zip
cd dos
dd conv=notrunc if=VGA.DRV of=MAIN.EXE bs=1 count=4480 seek=$((0x600))
