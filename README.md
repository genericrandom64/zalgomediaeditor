# The Zalgo Media Editor
The official Zalgo Media Editor Git repository.

The Zalgo Media Editor is a light, general-purpose image editor. It currently resizes and displays images, with additional features in development. 

# Dependencies:

- the STB library (make)
- SDL2 / SDL2_image (make, runtime)

(Dependencies may change in the future.)

# COMPILING THE ZME

Compile with:
Linux (Tested with Majaro) - `gcc main.c -o zme-linux -lm -I/usr/include/SDL2 -D_REENTRANT -L/usr/lib -pthread -lSDL2 -lSDL2_image`

MacOS - `gcc main.c -o zme-darwin -L/usr/local/lib -lSDL2 -I/usr/local/include/SDL2 -D_THREAD_SAFE -lSDL2_image`

Windows - (WIP)

# USING THE ZME

Usage:
zme [r c sdl] input.png output.png [additional arg(s)]

Options:

- r [height width]: Resize an image.

example: `zme r vacation.png vacation-240p.png 320 240`



- c: Crop an image. (Not implemented)

example: (To be determined)



- sdl [path-to-image]: Displays an image. 

example: `zme sdl corroded-batteries.png`

**THIS FEATURE IS NOT COMPLETE. It will eventually be a graphical version of the CLI. Until then, the image viewing feature is available as [imgview.](https://github.com/genericrandom64/imgview)**
