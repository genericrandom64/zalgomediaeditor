//
// 8/14/20.
//

#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "lib/stb_image_resize.h"

/* compile with gcc main.c -o zme

The purpose of this software is to provide a LIGHTWEIGHT and SIMPLE media editor
that runs quickly and exports directly to the clipboard.

 Copyright Zalgo 2020.
 This software is licensed to the public with the GNU General Public License v3.
 by Rohan and Yashas of Zalgo.

 */
unsigned char *idata;
char *odata, *opt;
char image, *img, *out;
int iw, ih, n, fw, fh;

void resize() {
    stbir_resize(idata, iw, ih, 0, odata, fw, fh, 0, STBIR_TYPE_UINT8, n, STBIR_ALPHA_CHANNEL_NONE, 0,STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,STBIR_FILTER_BOX, STBIR_FILTER_BOX,STBIR_COLORSPACE_SRGB, 0); // convert image to new size
    printf("Saving... ");
    stbi_write_png(out, fw, fh, n, odata, 0); // save to file
    printf("Freeing memory... ");
    stbi_image_free(idata); // seems to be to clear memory used from the malloc? need to check
    stbi_image_free(odata);
    return;
}

void crop() {
    stbi_write_png(out, fw, fh, n, odata, 0); // save to file
    stbi_image_free(idata); // frees input img memory
    stbi_image_free(odata); // frees output img memory
    return;
}

void option(char *opt) {
    if(strcmp(opt, "r") == 0) { // just seeing what makes the compiler shut up    (lol)
        printf("\033[1;32mResizing image... ");
        resize(image);
        printf("Done.\033[0m\n");
        return;
    } else {
        printf("\033[1;31mInvalid option: %s!\033[0m\nUsage: zme OPTION [IN OUT] ARGUMENT(S)\n", opt);
    }
    if(strcmp(opt, "c") == 0) {
        printf("Not yet implemented.");
        return;
    }
    if(strcmp(opt, "help") == 0) {
        printf("");
        return;
    }
}

void start_gui() {

}

void sample_gui() {
    printf("\033[1;32mreached sample_gui()\033[0m\n");
}

int main(int argc, char *argv[]) {
    printf("\033[1;32m--- The Zalgo Media Editor ---\033[0m\n     By Rohan and Yashas\n\n");
    if (!argv[1]) {
        sample_gui();
        //start_gui();
    } else {
        // Loading Pictures to Get Wide, High and Color Channel Information
        out = argv[3];
        img = argv[2];
        idata = stbi_load(img, &iw, &ih, &n, 0);
        fw = atoi(argv[4]); // convert args 3 and 4 to int for height and width
        fh = atoi(argv[5]);
        odata = (unsigned char *) malloc(fw * fh * n);

        option(argv[1]); // SEMICOLONS (lol)
    }
    return 0;
}
