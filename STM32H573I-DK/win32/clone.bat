git clone --recursive https://github.com/STMicroelectronics/STM32CubeH5.git
rem should be at 66f1a02802658fd01a404e770252b5ffc63986dd

mkdir STM32
mkdir CMSIS\Core\Include
mkdir STM32H5xx_HAL_Driver\Inc
mkdir STM32H5xx_HAL_Driver\Src
mkdir STM32H5xx_HAL_Driver\Inc\Legacy\
copy STM32CubeH5\Drivers\CMSIS\Core\Include CMSIS\Core\Include
copy STM32CubeH5\Drivers\STM32H5xx_HAL_Driver\Inc STM32H5xx_HAL_Driver\Inc\
copy STM32CubeH5\Drivers\STM32H5xx_HAL_Driver\Src STM32H5xx_HAL_Driver\Src\
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\STM32CubeIDE\Application\Startup\startup_stm32h573iikxq.s STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\STM32CubeIDE\Application\User\syscalls.c .
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\STM32CubeIDE\Application\User\sysmem.c .
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Src\main.c .
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Inc\main.h .
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Src\stm32h5xx_hal_msp.c STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Src\stm32h5xx_it.c STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Src\system_stm32h5xx.c STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Inc\stm32h5xx_hal_conf.h STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Inc\stm32h5xx_it.h STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\Inc\stm32h573i_discovery_conf.h STM32
copy STM32CubeH5\Drivers\CMSIS\Device\ST\STM32H5xx\Include\stm32h573xx.h STM32
copy STM32CubeH5\Drivers\CMSIS\Device\ST\STM32H5xx\Include\stm32h5xx.h STM32
copy STM32CubeH5\Drivers\CMSIS\Include\core_cm33.h STM32
copy STM32CubeH5\Drivers\CMSIS\Include\cmsis_version.h STM32
copy STM32CubeH5\Drivers\CMSIS\Include\cmsis_compiler.h STM32
copy STM32CubeH5\Drivers\CMSIS\Include\cmsis_gcc.h STM32
copy STM32CubeH5\Drivers\CMSIS\Device\ST\STM32H5xx\Include\system_stm32h5xx.h STM32
copy STM32CubeH5\Drivers\STM32H5xx_HAL_Driver\Inc\Legacy\stm32_hal_legacy.h STM32H5xx_HAL_Driver\Inc\Legacy\
copy STM32CubeH5\Drivers\BSP\STM32H573I-DK\stm32h573i_discovery.h STM32
copy STM32CubeH5\Drivers\BSP\STM32H573I-DK\stm32h573i_discovery.c STM32
copy STM32CubeH5\Drivers\BSP\STM32H573I-DK\stm32h573i_discovery_conf.h STM32
copy STM32CubeH5\Drivers\BSP\STM32H573I-DK\stm32h573i_discovery_errno.h STM32
copy STM32CubeH5\Projects\STM32H573I-DK\Examples\GPIO\GPIO_IOToggle\STM32CubeIDE\STM32H573IIKXQ_FLASH.ld .

powershell -command "Expand-Archive ..\openocd.zip ."