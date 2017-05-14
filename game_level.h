#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LEVEL_WIDTH 		30
#define LEVEL_HEIGHT 		20

#define SCREEN_WIDTH  		480
#define SCREEN_HEIGHT 		320

void read_level(char *filename, unsigned char *level_matrix);

void add_level_as_background(unsigned char *level_matrix, uint16_t* screen_matrix);

#endif
