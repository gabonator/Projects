mkdir res
cp dos/VGA* res/
cp dos/LEVEL* res/
cp dos/GROUND* res/
cp dos/MAIN.DAT res/
cp dos/ODDTABLE.DAT res/
#node ../../cicojs/conv.js lemmings.cpp lemmings.js
node ../../cicojs/fsbuild.js res resources.js
