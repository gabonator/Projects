./cicodis.elf input/nexus.txt > nexus.cpp
./cicodis.elf input/synsoemu.txt  > synsoemu.cpp
mkdir -p res
mv *.bin res
# only needed: Nexus_data.dll, Nexus_rdata.dll, SYNSOEMU_data.dll, SYNSOEMU_rdata.dll
