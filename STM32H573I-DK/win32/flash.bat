set PATH=C:\ST\STM32CubeIDE_1.14.0\STM32CubeIDE\plugins\com.st.stm32cube.ide.mcu.externaltools.openocd.win32_2.3.0.202305091550\tools\bin\

openocd.exe -s openocd -f app.cfg ^
  -c "init" ^
  -c "reset init" ^
  -c "flash erase_address 0x08000000 0x00006000" ^
  -c "flash write_image build/GPIO_IOToggle.elf" ^
  -c "reset" ^
  -c "exit"
