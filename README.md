# The Zalgo Media Editor
The official Zalgo Media Editor Git repository.


# Dependencies:

- the STB library (make)
- SDL2 / SDL2_image (make, runtime)

(Dependencies may change in the future.)

# COMPILING ZME

Compile with:
Linux (Tested with Majaro) - `gcc main.c -o zme-linux -lm -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib -pthread -lSDL2 -lSDL2_image`

MacOS - `gcc main.c -o zme-darwin -L/usr/local/lib -lSDL2 -I/usr/local/include/SDL2 -D_THREAD_SAFE -lSDL2_image`

Windows - (WIP)

# USING ZME

Usage:
zme [r c] input.png output.png [additional arg(s)]

Options:

- r: Resize an image. Additional args: height, width

example: `zme r vacation.png vacation-240p.png 320 240`



- c: Crop an image. (Not implemented)

example: (To be determined)
