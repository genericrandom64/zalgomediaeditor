/*

The purpose of this software is to provide a LIGHTWEIGHT and SIMPLE media editor
that runs quickly and exports directly to the clipboard.

Copyright Zalgo 2020.
This software is licensed to the public with the GNU General Public License v3.
by Rohan and Yashas of Zalgo.

*/
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
// custom libs
#include "zgutil.c"
#include "zgimgutil.c"
#include "zme-sdl.c"

char opt[10]; // selected options from input

char input; // input image path
char output; // output image path
void *idata; // image data of input file
void *odata; // image data of output file

int iwidth, iheight; // input width/height
int owidth, oheight; // output width/height
int depth; // bit-depth (?)
int optcount;

// Usage: zme option input output arguments

int main(int argc, char *argv[]) {

    carraycp(opt, *argv); // Store all command arguments in global variable
    if (strcmp(&opt[1],"r") == 0) {
        int n;
        input = opt[2]; output = opt[3]; owidth = (int) opt[4]; oheight = (int) opt[5];
        idata = open_image(input);
        idata = resize(idata, n, n, owidth, oheight);
        save_image(output,owidth,oheight,odata,n);
    }
    if (strcmp(argv[1],"sdl") == 0) {

        startsdl(argv[2]);
    }
    return 0;
}


void options() {

}





