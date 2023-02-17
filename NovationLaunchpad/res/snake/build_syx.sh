set -e
arm-none-eabi-g++ -fno-exceptions -fno-rtti -fno-common -Wno-psabi -Os -g -mcpu=cortex-m4 -mlittle-endian \
  -mfpu=fpv4-sp-d16 -mthumb -nostartfiles -ffunction-sections -T code.lds code.cpp -o code.elf
arm-none-eabi-objdump -S -marm -d ./code.elf > code.s
arm-none-eabi-nm ./code.elf > code.txt
arm-none-eabi-objcopy -j .text -O binary ./code.elf code.bin
arm-none-eabi-objcopy -j .data -O binary ./code.elf code.dat
node combine.js
./bintosyx /minimk3 444 ./final.bin final.syx
rm code.txt code.elf code.bin code.dat final.bin code.s
#flash with (up up down down left right left right): https://fw.mat1jaczyyy.com/firmware