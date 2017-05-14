#include "game_utils.h"

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Rgb;


uint16_t rgb_to_16(char r, char g, char b) {

    uint16_t rgb16 = 0;
    rgb16 |= (r * 31 / 255) << 11;
    rgb16 |= (g * 63 / 255) << 5;
    rgb16 |= (b * 31 / 255);

    return rgb16;
}

uint16_t *load_image(const char *img_addr, int width, int height) {

    int i, j;
    Rgb rgb;
    uint16_t *result = (uint16_t *) malloc(sizeof(uint16_t) * height * width);
    FILE *inFile = fopen(img_addr, "rb");

    fseek(inFile, 54, SEEK_SET);

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&rgb, sizeof(Rgb), 1, inFile);
            printf("%i %i %i \n", rgb.red, rgb.green, rgb.blue);

            //Invert image
            int index = i * width + j;
            int new_index = index % width + (height - index/height - 1) * width;

            result[index] = rgb_to_16(rgb.red, rgb.green, rgb.blue);
        }
    }


    fclose(inFile);
    return result - height * width;
}
