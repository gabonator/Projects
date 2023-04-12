arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
#/Users/gabrielvalky/Documents/git/Projects/CicoJit/gamelib/_xenon/dos/XENON2/XENON2.EXE -ctx -recursive start,14311,14759
#./cicodis dos/XENON2/XENON2.EXE -ctx -recursive start,14311,14759
./cicodis dos/XENON2/XENON2.EXE -ctx -assume_ds 2853 -recursive  1f29:16fc
#1f29:131e
#10ed9
#1f29:0202
#1f29:1f3c,2000:0cbb
#1f29:1319,1f29:12fd
#1f29:0147
#1f29:0117
#1f29:0137 -asm
#1f2ba

#./cicodis dos/XENON2/XENON2.EXE -ctx -recursive -assume_ds 2853 start,14311,14759,137df,172c4,1758f,1655b,10853,10761,17520,170f1,16eef,141e2,1480b,1714a,108b9,10f2b,137ca,11e61,128df,12ab2,13aa7,12a6e,16d22,13a39,1308c,139ee,1091f,10897,13998,141fb,11f4d,13835,13b76,16a0a,125a8,16aad,13bdf,16696,169d0,166a6,16bca,12ad0,16e2c,171dd,12a48,1714d,169c8,13246,13a99,17569,18ca7,17f32,17f79,18e01,189ae,188a9,18c3e,17dde,16284,19f02,19f9a,19fe6,19f4e,121e9,1246d,128b8,14f96,12aa4,180ca,1866d,18114,18126,180f5,187d5,18783,14311,14759,137df,172c4,1758f,1655b,10853,10761,17520,170f1,16eef,141e2,1480b,1714a,108b9,10f2b,137ca,11e61,128df,12ab2,13aa7,12a6e,16d22,13a39,1308c,139ee,1091f,10897,13998,141fb,11f4d,13835,13b76,16a0a,125a8,16aad,13bdf,16696,169d0,166a6,16ac7,16bca,12ad0,16e2c,171dd,12a48,1714d,169c8,13246,13a99,17569,18ca7,17f32,17f79,18e01,189ae,188a9,18c3e,17dde,16284,19f02,19f9a,19fe6,19f4e,121e9,1246d,128b8,14f96,12aa4,180ca,1866d,18114,18126,180f5,187d5,18783 > xenon.cpp
#patch etetris.cpp tetris.patch 
#diff etetris.cpp cicorun/etetris.cpp
rm cicodis
