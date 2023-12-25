# arch -arm64 zsh
brew install automake
brew install autoconf
git clone https://github.com/STMicroelectronics/OpenOCD.git
cd OpenOcd
git apply ../raggedright.patch
./bootstrap
./configure
make
src/openocd