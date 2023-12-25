/Users/gabrielvalky/Documents/git/ext/OpenOCD/src/openocd -s openocd -f app.cfg \
  -c "init" \
  -c "reset init" \
  -c "flash erase_address 0x08000000 0x0000e000" \
  -c "flash write_image build/GPIO_IOToggle.elf" \
  -c "reset" \
  -c "exit"
