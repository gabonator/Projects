set -e

./cicodis.elf input/synsoemu.txt > host/synsoemu.cpp
patch host/synsoemu.cpp input/synsoemu.patch

./cicodis.elf input/nexus.txt > host/nexus.cpp
patch host/nexus.cpp input/nexus.patch

mkdir -p res
mv *.bin res
# only needed: Nexus_txt.dll Nexus_data.dll, Nexus_rdata.dll, SYNSOEMU_data.dll, SYNSOEMU_rdata.dll
