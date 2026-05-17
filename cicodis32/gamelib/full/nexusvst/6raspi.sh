PATH=$PATH:/Volumes/ctng/home/x-tools/arm-unknown-linux-gnueabihf/bin/

if true; then
arm-unknown-linux-gnueabihf-g++ host/main_raspimidi.cpp host/nexus.cpp \
  -static-libstdc++ -static-libgcc \
  -I ../host \
  -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 \
  -Iraspi-sysroot/usr/include \
  -Lraspi-sysroot/usr/lib/arm-linux-gnueabihf \
  -lasound -lpthread -ldl -lm -O2 -o nexus_midi23.elf
  exit 0
fi


exit 0
COMPILER=/Volumes/ctng/home/x-tools/arm-unknown-linux-gnueabihf/bin/arm-unknown-linux-gnueabihf-g++
#$COMPILER -pg -O2 -D MONO -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0x  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_01.elf 
#$COMPILER -pg -O2 -D MONO -D OPT_10056490 -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0x  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_02.elf 
#$COMPILER -pg -O2 -D MONO -D OPT_10056490 -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_03.elf # bad
#$COMPILER -O2 -D MONO -D OPT_10056490 -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_04.elf # bad
#$COMPILER -O2 -D MONO -D OPT_10056490 -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0x  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_05.elf
#$COMPILER -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_06.elf # Average replacing time: 2916.26 ms

#$COMPILER -static-libstdc++ -static-libgcc -fprofile-generate=/home/pi/gabo/validtest -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_11pg.elf 
#mv "#Users#gabrielvalky#Documents#git#Projects#cicodis32#gamelib#full#nexusvst#nexus_11pg.elf-main.gcda" nexus_11pg.elf-main.gcda
#mv "#Users#gabrielvalky#Documents#git#Projects#cicodis32#gamelib#full#nexusvst#nexus_11pg.elf-nexus.gcda" nexus_11pg.elf-nexus.gcda
#$COMPILER -pg -static-libstdc++ -static-libgcc -fprofile-use -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_11pg.elf 
#mv nexus_11pg.elf nexus_11pg_outpg.elf 

# nexus_11pg_out.elf  Average replacing time: 2452.22 ms
# nexus_07pgopt.elf   Average replacing time: 2522.59 ms

#$COMPILER -pg -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_08.elf
# test 62e20

#$COMPILER -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_14.elf
#$COMPILER -pg -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_23.elf
#$COMPILER -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_24.elf   # Average replacing time: 2246.85 ms

$COMPILER -O2 -D MONO -D OPT_10015160 -D OPT_1004c750 -D OPT_10056490 -D OPT_10059ed0 -D OPT_1005fc90 -D OPT_10062e20 -D OPT_10066dc0xxx -D OPT_1006b050 -D OPT_1006d830 -D OPT_1006df90 -D OPT_1006ff60 -D OPT_100c90d2 -D RASPI -D NDEBUG --std=c++17 host/main_test.cpp host/nexus.cpp -o nexus_26t.elf   # Average replacing time: 2246.85 ms

exit 0
#$COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90z -D OPT_1006ff60z -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_43.elf
#$COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90z -D OPT_1006ff60z -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2z -D OPT_10015160z -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_44.elf
#$COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90z -D OPT_1006ff60z -D OPT_10066dc0 -D OPT_1006df90z -D OPT_1006d830z -D OPT_100c90d2z -D OPT_10015160z -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_45.elf
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90z -D OPT_1006ff60z -D OPT_10066dc0z -D OPT_1006df90z -D OPT_1006d830z -D OPT_100c90d2z -D OPT_10015160z -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_46.elf # good
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90z -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_47.elf #bad
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90z -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830x -D OPT_100c90d2x -D OPT_10015160x -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_48.elf #bad 
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90z -D OPT_1006ff60 -D OPT_10066dc0x -D OPT_1006df90x -D OPT_1006d830x -D OPT_100c90d2x -D OPT_10015160x -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_49.elf #good
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90z -D OPT_1006ff60 -D OPT_10066dc0X -D OPT_1006df90X -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_50.elf #good
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0X -D OPT_1006df90X -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_51.elf #good
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0  -D OPT_1006df90X -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_52.elf #bad
#$COMPILER -pg -O2 -D OPT_1004c750z -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0X -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_53.elf #good
# $COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0X -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_54.elf # good final!

#  $COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_56.elf
#  $COMPILER -pg -O2 -D OPT_10062e20x -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_59.elf

# $COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0X -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_60.elf # GOOD

# debug
$COMPILER -pg -O2 -D MONO -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0x  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_65.elf 

# release
#$COMPILER -pg -O2 -D MONO -D OPT_10059ed0 -D OUT_10062e20 -D OPT_1004c750 -D OPT_1005fc90  -D OPT_1006ff60 -D OPT_10066dc0x  -D OPT_1006df90  -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_65.elf 


#$COMPILER --version
#exit 0
#$COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90 -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_32pg.elf
###$COMPILER -pg -O2 -D OPT_1004c750 -D OPT_1005fc90 -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_42.elf
#$COMPILER -O2 -static-libstdc++ -static-libgcc -fprofile-generate=/home/pi/gabo/test2 -D OPT_1004c750 -D OPT_1005fc90 -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_41pgo.elf
#$COMPILER -O2 -fprofile-use -fprofile-correction -D OPT_1004c750 -D OPT_1005fc90 -D OPT_1006ff60 -D OPT_10066dc0 -D OPT_1006df90 -D OPT_1006d830 -D OPT_100c90d2 -D OPT_10015160 -D RASPI -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_41pgo.elf
# OPT_1005fc90 adds noise


exit 0
gcc (Raspbian 8.3.0-6+rpi1) 8.3.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
