rm -rf dos/VGA.DRV dos/CGA.DRV dos/Run.bat dos/SOUND.COM dos/RICK2.EXE
node ../../cicojs/conv.js rick2opt.cpp rick2.js
node ../../cicojs/fsbuild.js dos resources.js
