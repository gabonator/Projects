# STM32H573I-DK quick example

## Terrible software package

STM32H573I-DK is the development kit for evaluation of STM32H573 MCU. In order to compile even simple example which just toggles onboard LEDs, you need to clone [STM32CubeH5 MCU Firmware Package](https://github.com/STMicroelectronics/STM32CubeH5) which contains example projects for all STM32H5 based evaluation boards (NUCLEO-H563ZI, NUCLEO-H503RB, STM32H573I-DK). [Official documentation](https://www.st.com/en/evaluation-tools/stm32h573i-dk.html#documentation) will point you to a PDF document which recommends installing software called [STM32Cube](https://www.st.com/en/ecosystems/stm32cube.html) MCU Package. I had to watch some youtube video to understand how to use this terrible UX unfriendly piece of software. Hoping that it is the only package which is necessary to build and flash some code. I was wrong, STM32Cube is just used to export project files for some ancient Eclipse based IDE called [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html). Clearly this setup is definitelly not suitable for modern software development. Especially java based editor full of visual glitches and poor user response. So I built some simple example, and checked the console output to find out how to compile the code with all dependencies. For flashing you can either use `STM32_Programmer_CLI.exe` which part of the mentioned packages or OpenOcd (official openocd repo does not support this MCU, you need to build from https://github.com/STMicroelectronics/OpenOCD). I prefer the second option since you do not need to install any proprietary code from ST.

## Minimal setup

Following set of batch scripts can be used to build and flash simple blink demo for STM32H573I-DK, using arm-eabi toolchain and openocd. No need to install STM32CubeMX or STM32CubeIDE.

- win32/clone.bat - clones STM32CubeH5 repository and extracts the `STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\` example code with all dependencies, after running this script you can delete the cloned repository
- win32/build.bat - builds the code with arm toolchain, download one here: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads
- win32/flash.bat - flashes the code to STM32H573I-DK over USB (OpenOCD + STLINK V3), needs OpenOCD installed
- osx/clone.bat - clones the repo on osx/linux
- osx/build.bat - builds the code on osx/linux
- osx/install_openocd.sh - stm32 fork of openocd building instructions
- win32/flash.bat - flashes the code using stm32 fork of openocd
- openocd.zip - scripts required by OpenOcd

## Advanced examples
- demo_touch - C++ demo using LCD and touch screen

## Notes
- when building larger code, you will need to erase the eeprom by altering `flash erase_address 0x08000000 0x00006000` command in flashing script. To erase whole eeprom you can use `flash erase_sector 0 0 last` but it takes about 3 seconds to finish