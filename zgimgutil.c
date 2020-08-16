//
// 8/14/20
//

#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "lib/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "lib/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "lib/stb_image_resize.h"

void *resize(void *idata, int input_width, int input_height, int final_width, int final_height) {
    int n;
    unsigned char *odata = malloc(final_width * final_height * n);
    stbir_resize(idata, input_width, input_height, 0, odata, final_width, final_height, 0, STBIR_TYPE_UINT8, n, STBIR_ALPHA_CHANNEL_NONE, 0,STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP,STBIR_FILTER_BOX, STBIR_FILTER_BOX,STBIR_COLORSPACE_SRGB, 0); // convert image to new size
    stbi_image_free(idata); // Clears input image from memory
    return odata;
}

void save_image(char output_file, int final_width, int final_height, void *odata, int bitdepth) {
    stbi_write_png(&output_file, final_width, final_height, bitdepth, odata, 0); // save to file
    stbi_image_free(odata); // Clears image from memory
}

void *open_image(char path) {
    int n;
    void *idata = stbi_load(&path, &n, &n, &n, 0); // may be incorrect
    return idata;
}