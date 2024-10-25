curl -s "https://ia804707.us.archive.org/33/items/tetris-dos-files-en_20230112/Tetris_DOS_Files_EN.zip" -o Tetris_DOS_Files_EN.zip
unzip -d dos -j Tetris_DOS_Files_EN.zip \
  "Tetris_DOS_Files_EN/Game Files/BKGR0" \
  "Tetris_DOS_Files_EN/Game Files/BKGR1" \
  "Tetris_DOS_Files_EN/Game Files/BKGR2" \
  "Tetris_DOS_Files_EN/Game Files/BKGR3" \
  "Tetris_DOS_Files_EN/Game Files/BKGR4" \
  "Tetris_DOS_Files_EN/Game Files/BKGR5" \
  "Tetris_DOS_Files_EN/Game Files/BKGR6" \
  "Tetris_DOS_Files_EN/Game Files/BKGR7" \
  "Tetris_DOS_Files_EN/Game Files/BKGR8" \
  "Tetris_DOS_Files_EN/Game Files/BKGR9" \
  "Tetris_DOS_Files_EN/Game Files/HIGH" \
  "Tetris_DOS_Files_EN/Game Files/SLC" \
  "Tetris_DOS_Files_EN/Game Files/TBKGR0" \
  "Tetris_DOS_Files_EN/Game Files/TETRIS.TTL" 
unzip tetris.zip -d dos
rm Tetris_DOS_Files_EN.zip 