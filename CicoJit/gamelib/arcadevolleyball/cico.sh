arch -arm64 g++ -std=c++17 ../../cicodis/cicodis/main.cpp -I/opt/homebrew/Cellar/capstone/4.0.2/include/ -L/opt/homebrew/Cellar/capstone/4.0.2/lib -lcapstone.4 -lc++ -o cicodis
./cicodis $PWD/dos/av.exe -load 01ed -ctx -recursive -stackguard -labels sub_753d,loc_7574 start,043e:1d7,1ed:3e92,1ed:402e,043e:000,08e6:1d2,08e6:0000,01ed:017d,043e:00e3,08e6:0282,01ED:6809,043e:0286,08e6:0273,043E:0297,08E6:00DC,043E:0050,08E6:007F,043E:0398,043E:0482,043E:0231,08E6:0222,043E:006C,043e:0072,08e6:0079,043E:006C,08E6:01C8,043e:03d2,08e6:02b2,08E6:0156,043e:035c,08e6:01b4,043e:00000548,043e:02b3,08e6:0126,043e:0248,043e:0084,08e6:0114,043e:00000538,043e:00000538,043E:000007F1,043e:07fe,08E6:00000140 -recursive > av.cpp
rm cicodis
patch av.cpp av.patch
diff av.cpp cicorun/av.cpp