#set -e

./cicodis.elf input/nexus_reloc.txt > host_reloc/nexus.cpp
cp host_reloc/nexus.cpp host_reloc/nexus_clean.cpp
patch host_reloc/nexus.cpp input/nexus_reloc.patch

exit 0
./cicodis.elf input/nexus_reloc.txt > host_reloc/nexus.cpp
cp host_reloc/nexus.cpp host_reloc/nexus_clean.cpp
patch host_reloc/nexus.cpp input/nexus_reloc_new.patch
git diff --no-index host_reloc/nexus_clean.cpp host_reloc/nexus.cpp > host_reloc/nexus_reloc_new2.patch
exit 0
#z ./cicodis.elf input/synsoemu_reloc.txt > host_reloc/synsoemu.cpp
#z patch host_reloc/synsoemu.cpp input/synsoemu_reloc.patch

#./cicodis.elf input/nexus_reloc0.txt > host_reloc/nexus0.cpp
#./cicodis.elf input/nexus_reloc.txt > host_reloc/nexus1.cpp
#git diff --no-index host_reloc/nexus0.cpp host_reloc/nexus1.cpp > host_reloc/nexus01.patch

cp host_reloc/nexus0.cpp  host_reloc/nexus0clean.cpp
patch host_reloc/nexus0.cpp input/nexus_reloc.patch
patch host_reloc/nexus0.cpp input/nexusnotext_reloc.patch
patch host_reloc/nexus0.cpp host_reloc/nexus01.patch
git diff --no-index host_reloc/nexus0clean.cpp host_reloc/nexus0.cpp > host_reloc/nexus_reloc_new.patch

exit 0
patch host_reloc/nexus.cpp input/nexus_reloc.patch
patch host_reloc/nexus.cpp input/nexusnotext_reloc.patch
rm host_reloc/*.orig

mkdir -p res_reloc
mv *.bin res_reloc

exit 0

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
