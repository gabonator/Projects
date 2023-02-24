set -e
arm-none-eabi-objdump -z -b binary --adjust-vma=0x0800c000 -marm -Mforce-thumb -D ../common/LPMiniMK3-407.bin > input.s
node convert.js > output.s
arm-none-eabi-gcc -masm-syntax-unified -mcpu=cortex-m4 -mlittle-endian -mfpu=fpv4-sp-d16 -mthumb -Ttext=0x800c000 -c output.s -o output
arm-none-eabi-objcopy -O binary ./output output.bin
dd if=output.bin of=output_part.bin bs=1 count=66727 skip=$((0x0800c000))
rm output.bin output

rm input.s output_part.bin
mv output.s decompiled.s
../common/bintosyx /minimk3 444 ./output_part.bin recompiled.syx
exit 0

arm-none-eabi-objdump -z -b binary --adjust-vma=0x0800c000 -marm -Mforce-thumb -D output_part.bin > input2.s
diff input.s input2.s > diff
