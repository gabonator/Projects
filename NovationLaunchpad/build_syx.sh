set -e
mkdir -p build
cd build
arm-none-eabi-g++ -fno-exceptions -fno-rtti -fno-common -Wno-psabi -Os -g -mcpu=cortex-m4 -mlittle-endian \
  -DSTM32F401xC -I../stm32lib -I../stm32lib/STM32F4xx_StdPeriph_Driver/inc/ \
  -mfpu=fpv4-sp-d16 -mthumb -nostartfiles -ffunction-sections -T ../common/code.lds ../source/main.cpp -o code.elf

arm-none-eabi-objdump -S -marm -d ./code.elf > code.s
arm-none-eabi-nm ./code.elf > code.txt
arm-none-eabi-objcopy -j .text -O binary ./code.elf code.bin
arm-none-eabi-objcopy -j .data -O binary ./code.elf code.dat
cp ../common/LPMiniMK3-407.bin .
node ../common/combine.js
../common/bintosyx /minimk3 444 ./final.bin final.syx
rm code.txt code.elf code.bin code.dat final.bin code.s LPMiniMK3-407.bin 
#flash with (up up down down left right left right): https://fw.mat1jaczyyy.com/firmware