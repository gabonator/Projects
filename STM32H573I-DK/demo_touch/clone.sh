git clone --recursive https://github.com/STMicroelectronics/STM32CubeH5.git
# should be at 66f1a02802658fd01a404e770252b5ffc63986dd

mkdir -p STM32
mkdir -p STM32/BSP/Components
mkdir -p STM32/CMSIS/Core/Include
mkdir -p STM32/CMSIS/Include
mkdir -p STM32/STM32H5xx_HAL_Driver/Inc
mkdir -p STM32/STM32H5xx_HAL_Driver/Src
mkdir -p STM32/Utilities
mkdir -p STM32/CMSIS/Device/ST/STM32H5xx/Include/

cp -r STM32CubeH5/Drivers/BSP/Components/Common STM32/BSP/Components/
cp -r STM32CubeH5/Drivers/BSP/Components/ft6x06 STM32/BSP/Components/
cp -r STM32CubeH5/Drivers/BSP/Components/st7789h2 STM32/BSP/Components/
cp -r STM32CubeH5/Drivers/BSP/STM32H573I-DK STM32/BSP/
cp -r STM32CubeH5/Drivers/CMSIS/Core/Include/ STM32/CMSIS/Core/Include
cp -r STM32CubeH5/Drivers/STM32H5xx_HAL_Driver/Inc/ STM32/STM32H5xx_HAL_Driver/Inc
cp -r STM32CubeH5/Drivers/STM32H5xx_HAL_Driver/Src/ STM32/STM32H5xx_HAL_Driver/Src
cp -r STM32CubeH5/Utilities/lcd STM32/Utilities/
cp -r STM32CubeH5/Utilities/Fonts STM32/Utilities/
cp STM32CubeH5/Drivers/CMSIS/Device/ST/STM32H5xx/Include/system_stm32h5xx.h STM32/CMSIS/Device/ST/STM32H5xx/Include/

cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/Application/User/sysmem.c STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Src/system_stm32h5xx.c STM32
cp STM32CubeH5/Drivers/CMSIS/Include/core_cm33.h STM32/CMSIS/Include
cp STM32CubeH5/Drivers/CMSIS/Include/cmsis_version.h STM32/CMSIS/Include
cp STM32CubeH5/Drivers/CMSIS/Include/cmsis_compiler.h STM32/CMSIS/Include
cp STM32CubeH5/Drivers/CMSIS/Include/cmsis_gcc.h STM32/CMSIS/Include
cp STM32CubeH5/Drivers/CMSIS/Device/ST/STM32H5xx/Include/stm32h573xx.h STM32/CMSIS/Device/ST/STM32H5xx/Include
cp STM32CubeH5/Drivers/CMSIS/Device/ST/STM32H5xx/Include/stm32h5xx.h STM32/CMSIS/Device/ST/STM32H5xx/Include
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/CEC/CEC_DataExchange_Device_1/Inc/ft6x06_conf.h STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Inc/stm32h5xx_hal_conf.h STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/STM32H573IIKXQ_FLASH.ld STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/Application/Startup/startup_stm32h573iikxq.s STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Inc/stm32h573i_discovery_conf.h STM32

patch STM32/stm32h5xx_hal_conf.h ./stm32h5xx_hal_conf.patch 

exit 0
mkdir -p CMSIS/Core/Include
mkdir -p STM32H5xx_HAL_Driver/Inc
mkdir -p STM32H5xx_HAL_Driver/Src
mkdir -p STM32H5xx_HAL_Driver/Inc/Legacy/
cp -r STM32CubeH5/Drivers/CMSIS/Core/Include/ CMSIS/Core/Include
cp -r STM32CubeH5/Drivers/STM32H5xx_HAL_Driver/Inc/ STM32H5xx_HAL_Driver/Inc
cp -r STM32CubeH5/Drivers/STM32H5xx_HAL_Driver/Src/ STM32H5xx_HAL_Driver/Src
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/Application/Startup/startup_stm32h573iikxq.s STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/Application/User/syscalls.c .
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/Application/User/sysmem.c .
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Src/main.c .
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Inc/main.h .
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Src/stm32h5xx_hal_msp.c STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Src/stm32h5xx_it.c STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Src/system_stm32h5xx.c STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Inc/stm32h5xx_hal_conf.h STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Inc/stm32h5xx_it.h STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/Inc/stm32h573i_discovery_conf.h STM32
cp STM32CubeH5/Drivers/CMSIS/Device/ST/STM32H5xx/Include/stm32h573xx.h STM32
cp STM32CubeH5/Drivers/CMSIS/Device/ST/STM32H5xx/Include/stm32h5xx.h STM32
cp STM32CubeH5/Drivers/CMSIS/Include/core_cm33.h STM32
cp STM32CubeH5/Drivers/CMSIS/Include/cmsis_version.h STM32
cp STM32CubeH5/Drivers/CMSIS/Include/cmsis_compiler.h STM32
cp STM32CubeH5/Drivers/CMSIS/Include/cmsis_gcc.h STM32
cp STM32CubeH5/Drivers/CMSIS/Device/ST/STM32H5xx/Include/system_stm32h5xx.h STM32
cp STM32CubeH5/Drivers/STM32H5xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h STM32H5xx_HAL_Driver/Inc/Legacy/
cp STM32CubeH5/Drivers/BSP/STM32H573I-DK/stm32h573i_discovery.h STM32
cp STM32CubeH5/Drivers/BSP/STM32H573I-DK/stm32h573i_discovery.c STM32
cp STM32CubeH5/Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_conf.h STM32
cp STM32CubeH5/Drivers/BSP/STM32H573I-DK/stm32h573i_discovery_errno.h STM32
cp STM32CubeH5/Projects/STM32H573I-DK/Examples/GPIO/GPIO_IOToggle/STM32CubeIDE/STM32H573IIKXQ_FLASH.ld .
