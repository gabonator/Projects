#!/bin/bash
set -e
cd "$(dirname "$0")"

mkdir -p wasm

EXPORTED="['_nexus_init','_nexus_load_preset','_nexus_midi','_nexus_process','_nexus_out_l','_nexus_out_r']"

mkdir -p wasm/res
cp res_reloc/Nexus_rdata.bin res_reloc/Nexus_data.bin \
   res_reloc/SYNSOEMU_rdata.bin res_reloc/SYNSOEMU_data.bin wasm/res/

emcc --std=c++17 -D WASM -O2 \
    deviation1/main.cpp \
    --no-entry \
    -s EXPORTED_FUNCTIONS="${EXPORTED}" \
    -s EXPORTED_RUNTIME_METHODS="['HEAPU8','HEAPF32']" \
    -s INITIAL_MEMORY=268435456 \
    -s ALLOW_MEMORY_GROWTH=0 \
    -s STACK_SIZE=65536 \
    -s NO_EXIT_RUNTIME=1 \
    -s MODULARIZE=1 \
    -s EXPORT_NAME=NexusModule \
    -o wasm/nexus.js \
    2>&1
