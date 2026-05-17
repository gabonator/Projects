set -e

./cicodis.elf input/synsoemu.txt > host/synsoemu.cpp
patch host/synsoemu.cpp input/synsoemu.patch

./cicodis.elf input/nexus.txt > host/nexus.cpp
#cp host/nexus.cpp host/nexus_cleannew.cpp
patch host/nexus.cpp input/nexus.patch

(
  # opt tools do not work well with replaced constants
  cp host/nexus.cpp opttools/nexus.cpp

  cd host
  cp ../opttools/replace_fp_consts.py .
  python3 replace_fp_consts.py --apply --force-data-fp80
  rm replace_fp_consts.py
  cp processed/* .
  rm -rf processed
)

patch host/nexus.cpp input/nexusopts.patch

mkdir -p res
mv *.bin res
# only needed: Nexus_txt.dll Nexus_data.dll, Nexus_rdata.dll, SYNSOEMU_data.dll, SYNSOEMU_rdata.dll
