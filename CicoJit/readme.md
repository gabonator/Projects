# CicoJit

Cicojit was an experimental project which translates MSDOS binaries into C++ code on the fly during the program execution while building a source code of complete application. Similar to QEMU or Rosetta, but instead of translating basic blocks (sequence of instruction between branches), CicoJit tries to translate whole methods to produce human readable code. Cruical part is the CicoDis disassembler which uses Capstone to turn sequence of instructions into human readable C code. CicoJit was extremely slow and later I focused on improving the CicoDis component, running CicoDis with recursive mode enabled converts most of the application in single run and it does it very quickly. Command line interface was extended to help CicoJit to process indirect jumps. CLI also allows setting the base address to debug the application side by side with DosBox. 

# CicoDis

CicoDis became a powerful standalone tool for converting whole applications into C++ code. At first this was just a proof of concept to test if Capstone disassembler can be used for porting old games into C++. While working at Tachyum I got more familiar with QEMU which uses exactly this open source component for a serious and high performance translation of "foreign" applications into the native code. This allows you to run x86 applications on modern ARM based computers at pretty decent speed. Whole converter is written as a single ugly cpp file. The aim was to do a quick and dirty job to verify feasibility of this idea. Having a tool (even ugly one) which reliably converts 10 or more games into C++ was a prerequiste for a following step. That step would be designing a nice and well organized converter which produces exactly the same input. But as always, due to lack of free time, I decided to finalize this project at this point. 

# Documentation

No documentation available, see the **cico.sh** for each game in the library to understand how to use CicoParserDis command line interface

# Building

See the [cicodemo](cicodemo) folder, there is a batch file which runs in Windows, and a docker file for Linux. For iOS just use the shell scripts in game library. You will need to install capstone (`brew install capstone`) and sdl2 (`brew install sdl2`)

# What it does                                                                                                       
It converts EXE file into C++ code, by providing `cicoctx.h` header file, these two can be built into a object file. By adding a layer which emulates video and cpu you will get a running game. In `cicorun` folders I usually keep a working SDL2 application, for publishing I generate either javascript port of the game, or WebAssembly

# Demo

| Game | Author | Year | Language | Video | Port | Controls |
|------|--------|------|----------|-------|------|----------|
| Alley cat | IBM / Bill Williams | 1984 | asm | cga | [native](gameslib/alleycat/cicorun/) - difficult timing loops, not suitable for porting into web | |
| Tetris | Spectrum Holobyte | 1987 | asm | cga, ega | [native](gameslib/tetris/cicorun/)  - not really fun, no web port | |
| Xenon2 | Bitmap brothers | 1990 | asm | ega | [native](gameslib/xenon2/cicorun/)  - tons of indirect calls | |
| | | | | | [wasm](gameslib/xenon2/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/xenon2/wasm/build/index.html)  | Touch / arrow keys, space |
| Titus the fox | Eric Zmyro | 1992 | asm | ega | [native](gameslib/fox/cicorun) - had to hack copy protection first | |
| | | | | | [wasm](gameslib/fox/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/fox/wasm/build/fox.html) | arrow keys, space |
| | | | | | [wasm HD port](gameslib/fox/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/fox/wasmhd/build/fox.html) | arrow keys, space (A, B - demo]  |
| Arcade Volleyball | Compute! | 1987 | Turbo C | cga | [native](gameslib/arcadevolleyball/cicorun) - just proof of concept for porting higher languages | |
| Bumpy | Lorciel | 1992 | Turbo C++ | ega | [native](gameslib/bumpy/cicorun)  | |
| | | | | | [javascript port](gameslib/bumpy/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/bumpy/js/bumpy.html) - replays | arrow keys, space |
| | | | | | [wasm](gameslib/bumpy/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/bumpy/wasm/build/bumpy.html) | arrow keys, space |
| Tunneler | Geoffrey Silverton | 1991 | Pascal | ega+ | [native](gameslib/tunneler/cicorun)  | |
| | | | | | [javascript port](gameslib/tunneler/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/tunneler/js/tunneler.html) | asdf, arrow keys |
| | | | | | [wasm port](gameslib/tunneler/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/tunneler/wasm/build/tunneler.html) | asdf, arrow keys |
| | | | | | [wasm port + network multiplayer](gameslib/tunneler/netplay) - docker file | |
| Dynablaster | Hudson | 1990 | asm | vga | [native](gameslib/dynablaster/cicorun) | |
| | | | | | [javascript port](gameslib/dynablaster/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/dynablaster/js/dynablaster.html) | |
| | | | | | [wasm port](gameslib/dynablaster/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/dynablaster/wasm/build/dynablaster.html) | |
| CD-Man | Creative Dimensions | 1989 | asm | hi ega | [native](gameslib/cdman/cicorun) | |
| | | | | | [wasm port](gameslib/cdman/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/cdman/wasm/build/dynablaster.html) | arrow keys, (D - demo]  |
| Prehistorik | Titus | 1991 | Turbo C | ega | [native](gameslib/prehistorik/cicorun) | |
| | | | | | [javascript port](gameslib/prehistorik/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/prehistorik/js/index.html) | arrow keys |

more TBD
