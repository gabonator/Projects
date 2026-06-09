set -e

./cicodis.elf input/nexus_reloc.txt > host_reloc/nexus.cpp
#cp host_reloc/nexus.cpp host_reloc/nexus_clean.cpp
patch host_reloc/nexus.cpp input/nexus_reloc.patch

./cicodis.elf input/synsoemu_reloc.txt > host_reloc/synsoemu.cpp
#cp host_reloc/synsoemu.cpp host_reloc/synsoemu_clean.cpp
patch host_reloc/synsoemu.cpp input/synsoemu_reloc.patch

