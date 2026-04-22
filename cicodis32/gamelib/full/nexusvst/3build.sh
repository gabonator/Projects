#cp nexus.cpp host/nexus.cpp
#patch host/nexus.cpp nexus.patch

#cp synsoemu.cpp host/synsoemu.cpp 
#patch host/synsoemu.cpp synsoemu.patch

g++ --std=c++17 host/main.cpp host/nexus.cpp -o nexus.elf

#g++ -D NDEBUG --std=c++17 host/main.cpp host/nexus.cpp -o nexus_emu.elf