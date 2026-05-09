cp ../host/nexus.cpp nexus.cpp
python3 analyse4.py nexus.cpp --external-balances ./fpu_balances.json > analyse.txt
python3 extract.py nexus.cpp nexusopt_10015160_a.cpp sub_10015160
# sub_10016ed0
#python3 extract.py nexus.cpp nexusopt_10015160_a.cpp sub_10016ed0
python3 build_nexus_opt.py ./nexusopt_10015160_a.cpp ./nexusopt_10015160_b.cpp --sigs sigs.json
cp nexusopt_10015160_b.cpp nexusopt_10015160.cpp
python3 rename.py nexusopt_10015160.cpp
python3 forward.py nexusopt_10015160.cpp
patch nexusopt_10015160.cpp nexusopt_10015160.patch
rm *.bak nexusopt_10015160_*.cpp analyse.txt
