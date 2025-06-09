# Youtube review

[![Cicoparser: Ultimate game modding](https://img.youtube.com/vi/WtAVcQEU48s/0.jpg)](https://www.youtube.com/watch?v=WtAVcQEU48s "Cicoparser: Ultimate game modding")

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
| Alley cat | IBM / Bill Williams | 1984 | asm | cga | [native](gamelib/alleycat/cicorun) - difficult timing loops, not suitable for porting into web | |
| Tetris | Spectrum Holobyte | 1987 | asm | cga, ega | [native](gamelib/tetris/cicorun/)  - not really fun, no web port | |
| Xenon2 | Bitmap brothers | 1990 | asm | ega | [native](gamelib/xenon2/cicorun/)  - tons of indirect calls | |
| | | | | | [wasm](gamelib/xenon2/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/xenon2/wasm/build/index.html) | Touch / arrow keys, space |
| Titus the fox | Eric Zmyro | 1992 | asm | ega | [native](gamelib/fox/cicorun) - had to hack copy protection first | |
| | | | | | [wasm](gamelib/fox/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/fox/wasm/build/fox.html) | arrow keys, space |
| | | | | | [wasm HD port](gamelib/fox/wasmhd) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/fox/wasmhd/fox.html) | arrow keys, space (A, B - demo]  |
| Arcade Volleyball | Compute! | 1987 | Turbo C | cga | [native](gamelib/arcadevolleyball/cicorun) - just proof of concept for porting higher languages | |
| Bumpy | Lorciel | 1992 | Turbo C++ | ega | [native](gamelib/bumpy/cicorun)  | |
| | | | | | [javascript port](gamelib/bumpy/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/bumpy/js/bumpy.html) - replays | arrow keys, space |
| | | | | | [wasm](gamelib/bumpy/wasm/build) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/bumpy/wasm/build/bumpy.html) | arrow keys, space |
| Tunneler | Geoffrey Silverton | 1991 | Pascal | ega+ | [native](gamelib/tunneler/cicorun)  | |
| | | | | | [javascript port](gamelib/tunneler/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/tunneler/js/tunneler.html) | asdf, arrow keys |
| | | | | | [wasm port](gamelib/tunneler/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/tunneler/wasm/build/tunneler.html) | asdf, arrow keys |
| | | | | | [wasm port + network multiplayer](gamelib/tunneler/netplay) - docker file | |
| Dynablaster | Hudson | 1990 | asm | vga | [native](gamelib/dynablaster/cicorun) | |
| | | | | | [javascript port](gamelib/dynablaster/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/dynablaster/js/dynablaster.html) | |
| | | | | | [wasm port](gamelib/dynablaster/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/dynablaster/wasm/build/dynablaster.html) | |
| CD-Man | Creative Dimensions | 1989 | asm | hi ega | [native](gamelib/cdman/cicorun) | |
| | | | | | [wasm port](gamelib/cdman/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/cdman/wasm/build/cdman.html) | arrow keys, (D - demo) |
| Prehistorik | Titus | 1991 | Turbo C | ega | [native](gamelib/prehistorik/cicorun) | |
| | | | | | [javascript port](gamelib/prehistorik/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/prehistorik/js/index.html) | arrow keys, virtual joystick, change URL to change level |
| Arkanoid | Taito | 1989 | asm | ega | [native](gamelib/arkanoid/cicorun) | |
| | | | | | [javascript port](gamelib/arkanoid/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/arkanoid/js/index.html) | arrow keys, change URL to change level |
| Cervi | Vlada Chvatil | 1993 | Borland Pascal | ega | [native](gamelib/cervi/cicorun) - egavga.bgi experiment, no web port | |
| Lemmings | DMA Design | 1991 | asm | ega | [native](gamelib/lemmings/cicorun) | |
| | | | | | [wasm port](gamelib/lemmings/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/lemmings/wasm/build/index.html) | mouse |
| Rick Dangerous 2 | Core Design | 1990 | asm | ega | [native](gamelib/rick2/cicorun) | |
| | | | | | [wasm port + time warping](gamelib/rick2/wasmwarp) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/rick2/wasmwarp/rick2.html) | arrow keys, space, left shift |
| | | | | | [wasm port](gamelib/rick2/wasm) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/rick2/wasm/build/rick2.html) | arrow keys, space |
| | | | | | [video streamer](gamelib/rick2/stream) | |


| Game | Author | Year | Language | Video | Port | Controls |
|------|--------|------|----------|-------|------|----------|
| Star Goose | Logotron | 1988 | asm | ega | [native](gamelib/goose/cicorun) | |
| | | | | | [javascript port](gamelib/goose/js) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/js/goose.html) | |
| | | | | | [wasm port + time warping](gamelib/goose/wasmwarp) - [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/wasmwarp/build/goose.html) | |
| | | | | | [Complete game replay](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/goose/wasmwarp/build/goose.html?demo=1) | |
| Captain Comic | | | | | [Play online!](https://rawgit.valky.eu/gabonator/Projects/refs/heads/master/CicoJit/gamelib/captaincomic/wasm/build/comic.html) | |
| PopCorn | | | | | [native](gamelib/popcorn/cicorun) | |
| Rick Dangerous 1 | | | | | [native](gamelib/rick1/cicorun) | |
| Rockford | | | | | [native](gamelib/rockford/cicorun) | |

# Video narration

All of it began some 11 years ago when I reverse engineered my first MSDOS games, it was done
using IDA disassembler and a program I called CicoParser. It wasn't really easy to use and
compatible only with a small set of games. 

As a result, you would get a highly portable and efficient C++ code which you could run on almost 
any computer, mobile phone or even a resource-constrained microcontroller board like these two.

This project just sat on the shelf with occasional updates,

until I watched the movie Tetris from 2023, where Taron Egerton is excitedly playing 
Tetris and asking what language it is written in. ... I got even more curious about the 
answer than him, so I decided to refresh this project and find some clues.

## tetris
I know the answer now, but instead of going too much into technical details, lets just 
enjoy this showcase of game modding with new version of cicoparser

## xenon
Remember this space shooter game? Was it too difficult for you to reach the second level? Just with a 
few click you can finally see what's there! Code of the game is fully under our control,
so lets get some power ups to make it more fun! Yeah, thats it, much better now. But that's
nothing compared to what you will see next! Look at those crazy flying cats, do you know what movie
they are from? Let me know in the comments and the first correct answer will get some present from me!
This is how pure gaming joy looks like! 
Lets see what we have next

## fox
Titus the fox, from 1992. Another game running in a web browser. Note that there is no smooth scrolling,
since this game was designed on a poor 16 MHz PC which was simply not powerful enough for that.
Actually if you would run this game in DosBox you wouldn't notice any difference, so the question is;
why did I put so much effort on a converter which can reverse engineer 30 years old games?

## foxhd 
Aand, here we are. With just a few changes in the code and with the help of HTML5 we got this.
Hi resolution animations, smooth scrolling, parallax, even the music track was remastered.
Game layout was split into a few layers. Top one holds animated gifs of light and toxic steam
from the sewer. Second one contains the game characters, enemies, objects or everything non
static. Game map was upscaled with external tool and split into three images which create a nice
parallax effect. Last layer is just the sky. Low let's watch it in reverse. Gif animations
are blended with lighten mode to make them look transparent. Game characters and objects is
the only part rendered from the game, backgrounds are rendered by HTML and their horizontal
position is just moved by the player position.

This is a demonstration how you can make remastered HD versions of old games while keeping the game
mechanics untouched. Again, you can play this game in your browser and easily switch between levels. 
How cool is that!?

## av
Previous games were written in pure assembly,
so when you look at their disassembly, it is fairly easy to read and every instruction gives sense
and does something visible, but this one is in Turbo-C. Higher languages introduce common
runtime routines and teaching cicoparser to work with them was a tough task, even when the
game itself looks pretty ancient. Adding support for Turbo-C opened door to port whole bunch of 
more "recent" games.

## bumpy
Innocently looking game, but with mind bending puzzles. Game was modified to be controlled
externally, so I can instantly switch between the levels. To add a community element, 
everytime someone finishes a level, the key stroke sequence is sent to my server to keep track of
best solution for each puzzle. All of these solutions can be later replayed at your browser 
as you can see now.
If you wonder how such sequence looks like, here it is. ... Just a bunch of pairs of 
numbers where one is the timestamp and second encodes pressed buttons. The more complicated a
level is, the longer the path is That's all it takes to replay the level. 

## bumpy seq

But if it is too difficult for you, you can ask Chat GPT for help. In this case
game is running at much higher frame rate so that the AI has more time to observe 
the game mechanics. Lets
start with a few simple queries so the AI can learn how to survive the game and learn
the game objective. After a while Chat GPT is trained to quickly solve this puzzle.
Chat GPT lite with interactive interface is available only to closed group of developers,
ask for evaluation access at chatgpt.com (JOKE!)

## tunneler
Lets switch to multiplayer games. Tuneller was written in Pascal and uses undocumented
video graphics mode. Surprisingly it is much easier to emulate than regular EGA that
games of this era use. Objective of this game is simple - find and destroy your opponent 
by diggig holes in this huge map. By reverse engineering the game I reconstruct whole map
which you can see on the bottom. To make it even more fun I have included an maze in
the map.

## tunneler multiplayer
By sharing the key stroke sequence as we have seen in Bumpy with another player in real 
time we are getting a network multiplayer game. This game was written back in the days when 
the internet was still a new thing, so with cicoparser you can do really amazing things!
There is no limitation on how many users can be connected, in this case there are two
players and one observer, all of them have opened the same URL and all instances are
perfectly synchronized.
if you want to see what's under the hood, Docker file with the server is available on my
github.

## explanation
Now the boring part! I will try to briefly explain how this work. If you are not interested, 
just skip to the next chapter. 

Cicoparser takes executable of a MS-DOS application and with the help of Capstone disassembler 
it turns it into c++ source code. But this single file is not sufficient to run the game.
You will need to provide few more files, which tells the game how to map the keboard, 
how to emulate the video adapter and cpu.

Produced code is just a simple subset of C++ and can be easily transformed into javascript,
again by passing few more files you will get a working game which you can put online and
play directly in the web browser.

The most feasible target, by my opinion, is web assembly. Even in the web browser it provides
almost native speed, while keeping the CPU load very low. By the way, Web assembly modules
are very simple to integrate since they have very clean interface.

Internally most of the games require less than 1MB of RAM, but they need some limited access
to the file system. I usually embed all game resources as base64 strings into single huge javascript
file.

...

Regarding the interface, for each frame, you will pass the list of pressed keys
on input and you will instantly get framebuffer on the output

Now, lets say, that there is another player playing the same game. Instead of 
sending the keystrokes into the webassembly, it goes through a cloud service
which merges data from all playes and sends it back. Everyone would see exactly
the same.

But unfortunately, it takes some time to send data back and forth. So
every player runs two instances of the game - one is the realtime which is directly controlled
by the user. And the second one is synchronized with the cloud server to the very last bit of memory.
They are identical, but delayed by a few frames against the realtime instance

Then periodically the synchronized instance copies its state to the realtime and
missing frames are appended. For the remote player we need to predict which keys 
might have been pressed until we will get another update from the cloud, and for the 
local user we keep track of what and when he pressed.

And this is exactly how any cicoparser game can be turned into online multiplayer with a few clever tricks.

## dynablaster
Note that dynablaster is the only VGA game you will see in this video. And in the web port I
have included a nice mod which allows you to control all four players by keyboard.
In the original version it was limited to two players and two more could play on joysticks

But if you prefer playing games with your friends at the same keyboard, here is a nice mod for
Dynablaster. In the original version two of the players could play on keyboard and two on joysticks. 
This web version was modified so that you can control all 4 players just by keyboard.

## cdman
I tried to port this game into swift and objective C to see if it would be 
playable on phone. Since the game itself didn't have any mouse support and the player
was controlled solely by keyboard, I had to add a simple path finding algorithm that would
work with touch input.

By clicking or tapping on the map Pacman automatically goes there by following the shortest 
possible path. If you wonder how this was done, watch this animation. Map with obstacles and
pacman coordinates is extracted from the game memory. We will start traversing the map at
the point where we clicked until all reachable blocks are marked.
Then we do a little trick, let's swap the direction of all arrows. Now every map cell shows
you which direction to go; to reach the target. And now let's see it in action! Pure magic!

## prehistorik
Another popular game from early 90s. This time no special modding was done. Just watch the URL.
By altering it you can jump between levels and screens. The top panel shows you extracted values
from game memory such as: score, lives, health and remaining time

## arkanoid
Cicoparser does the heavy lifting and transforms more than 99% the game instructions into C, but 
there are still some places which needs to be fixed by hand. At least with current version. 
Sometimes the machine code programmers use strange tricks which are very difficult to implement 
in C or C++. Like in this case, they use context switching mechanism and they are dropping multiple 
stack entries to exit from three nested functions instantly. 
This is what they do after you finish the level and I gave up trying to find some workaround how
to emulate this behaviour.

## cervi
Another challenge was Pascal with borland's graphics "BGI" drivers. These applications load external
driver into memory and call routines from it. Again, this is something that cicoparser doesn't 
support for now. 
This game looks like you could code it in one afternoon, but it is special for me; at one 
creative team building at previous job we even made
a gaming console to play old games like that. I remember playing "Cervi" at every coffee break
every day! (Our boss wasn't exactly happy to see that, but these are the little things that
help to build friendly and more productive workplace) 
Great thing about this is, that up to 6 players can play the game at the same time!
And if there could be 10 players, I am sure we would squeeze in front of this machine and enjoy
this massive mulitplayer game! This really brings memories back. Thank you Brano for these photos!

## lemmings 
In this game, you lead 50 or more small creatures into a portal. There might be various obstacles 
which you need to dig through or climb. Booby traps and limited amount of special tools makes this 
game pretty difficult in higher levels, and of course you need to save them before the time runs out!

At first I was thinking as a mod I will create custom rules to finish the level - like
for example you need to sink in water at least 5 players, reach the highest point of the level and
explode there. But then I decided that I will make a painting program from it :) Playing lemmings
while drawing custom level makes it a completely different experience.

## rick2
Many of these "old fashion games" require very precise timing and character movement. This may get
a bit annoying, especially if you are just a casual player and you need to restart whole level just 
because of small mistake at it's end. So I was thinking, 
can we slow down the gameplay? Yes we can
Can we stop it completely? Yes we can
Can we reverse the time and travel back? Hmmm, let's try it

Similarly as with the multiplayer game, here we have two game instances running. One is realtime
and second is a few seconds delayed, If you press left shift, alarm clock will appear, the game will slow
down and slowly start reversing. During reversing, you copy the delayed version into the realtime
one and apply missing keystrokes. But the trick is, that we apply everytime less and less keystrokes.
This makes an illusion that you are travelling back in time.
After you release shift key, the game continues as usual

...

And if you will think twice about what I said, you will wonder, how fast can the game run. If 
we can simulate 1000 frames or so in just few milliseconds? Those 1000 frames represent the 
delay between realtime and delayed instance and when we are travelling back, we need to reset
the realtime instance back and simulate 999 frames, render it and do the same with 998 frames again in
following frame.
To see how quickly we are running, I've made this little test 

...

what you see right now is the sequence of keys for Rick2 to finish the game completely. The last
frame number is 48000, so that is a pretty long recorded sequence. Now, instead 
of playing the game, we will pass proper list of keys for each frame to the game engine and
dump the framebuffer into STDOUT. This will allow us to feed ffmpeg video encoder with the
actual gameplay. While encoder is crunching on our data, lets see what was printed at the beginning.
We run the game three times in a row and check how long it took. Can you see it? Below 1.5 seconds on
a 4 years old Macbookair M1, thats incredible. And if you do the math, that means the game
was running at 30 000 frame per seconds!! That's completely crazy!
And check this, ffmpeg finished the encoding and we have this nice long video of the complete rick2
gameplay. So lets now enjoy the final fight with the boss!

...

If you would like to try cicoparser by yourself, go to the project home. Go to the games library
and you will find there all the games I have ported so far. Lets try Rick1 for example, here
you see a bunch of shell scripts. Fetch downloads the game from public sources. A folder "DOS"
with the game will appear. "cico.sh" converts the game and applies a patch with some extra
changes. In this case we can enable or disable some options to make the game easier to play.
The result is stored in this cpp file. The final step is the "run" script which will compile
the game and run. This works nicely on Mac if you have SDL2 and Capstone disassmbler installed.
Don't worry, you can install them with just a two commands in the terminal.

For those who prefer windows or linux, I have prepared two demo scripts. For windows it is 
a regular batch file that does everything automatically. It download portable version of
mingw compiler, capstone disassembler, download the cicoparser code which is just a single C++
file, then it download Star goose game, converts and runs the game. As a bonus it also creates
Webassembly port.
For linux, the docker file is less generous, it does basically the same, just without the webassembly
port

...

Porting a game with cicoparser isn't always straightforward. But I've made a tool which helps
me with that. As we have seen before - fetch download the game, we have there single EXE file
and few game resources. If you look inside the executable, you will see the famous "MZ" header.
Coverage scripts uses cicoparser to generate C++ source code of the game, but including a lot
of extra information which we can visualize with this HTML file.

Right now we are looking into the guts of the EXE fail. Every block represents 128 bytes of the
file. Green bubbles are identified functions, purple is data segment, gray filled blocks are
zero filled empty blocks. 
Clicking on the first block reveals the first bytes of the EXE file, and how cicoparser transformed
them into C++. 
This light green bubble spanning over two blocks is the entry function - or the code which gets
executed as first. On the right you see the disassembly, on the left there is the C code.
As a bonus there is the call tree and hex dump.

This brown bubble  marks the jump table. Usually it is referenced by surrounding code.
Here you can see something what is called "an indirect jump" or "a complete nightmare of porting". 
On the left you can see that it was nicely transformed into a switch statement. Unfortunately, 
this is something what is difficult to do automatically, and you need to guide cicoparser a little
to get similar result.
For an indirect jump, you need to mark the address of the instruction, then you need to provide
the starting address of the jump table, type of entries and their number.
So these are the commandline switches we need to pass to cicoparser to properly turn indirect
jump into a nice switch. 
Coverage tool also marks blocks which are not completely covered in dashed line. We can
see here a chunk of bytes which is definitely a code, but unfortunately it was not referenced
anywhere. This might be code referenced by some indirect jump, or maybe a forgotten debugging 
code, or probably something related to redefining the player keys. After all it doesn't seem
important for the port, since I was able to finish the game even without these small uncovered
gaps of code.

So to conclude this very time consuming and non profit project, here are some bullet points:
- In general cicoparser can be used to port some 16 bit real mode applications,
it does not do it automatically. But as a reward you have the source code which you can 
freely modify.
- Currently if produces C++ code which can be executed as native application or used to
build webassembly module, Generated code can be also easily transformed into javascript
- Coverage tool helps to identify jump table and code "gaps"
- C++ or wasm ports have very simple interface and integration into AI frameworks or as a
mini game inside some 3d shooter game is also possible
- This video shows that regrading modding, you can go completely crazy
- Since we have quite optimized C++ code, the game runs very quickly on modern computers
- This speed is very important for training AI agents, with dosbox which runs in real time
 would be unimaginable 
- And if you need lightweight code without any dependencies that produces hours long temporally
coherent video for testing video encoders or testing a machine stability, this is what
you have been looking for!

So thats all my friends, I hope you liked it. And don't forget to tell me what game you
would like to see ported in the comments.
