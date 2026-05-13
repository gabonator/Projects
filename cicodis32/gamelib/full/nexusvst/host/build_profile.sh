COMPILER=/Volumes/ctng/home/x-tools/arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++
$COMPILER -pg -O2 -D OPT_10062e20xx -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_57.elf
