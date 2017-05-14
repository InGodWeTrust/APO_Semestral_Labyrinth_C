#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


uint16_t rgb_to_16(char r, char g, char b);

uint16_t *load_image(const char* img_addr, int width, int height);

#endif
