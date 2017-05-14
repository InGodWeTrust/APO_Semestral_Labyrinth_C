#include "game_level.h"

void read_level(char *filename, unsigned char *level_matrix) {
	int i, j;
	FILE *level_file = fopen(filename, "r+");
	
	for (i = 0; i < LEVEL_HEIGHT; i++) {
		for (j = 0; j < LEVEL_WIDTH; j++) {
			*level_matrix = getc(level_file) - '0';
			getc(level_file);
			level_matrix++;
		}
	}
	
	fclose(level_file);
}

void add_level_as_background(unsigned char *level_matrix, uint16_t* screen_matrix) {
	int i, j;
	
	int height_ratio = SCREEN_HEIGHT / LEVEL_HEIGHT;
	int width_ratio = SCREEN_WIDTH / LEVEL_WIDTH;
	
	for (i = 0; i < SCREEN_HEIGHT; i++) {
		for (j = 0; j < SCREEN_WIDTH; j++) {
			if (*(level_matrix + (i / height_ratio) * LEVEL_WIDTH + (j / width_ratio))) {
				*screen_matrix = rgb_to_16(0, 255, 0);
			} else {
				*screen_matrix = rgb_to_16(255, 255, 255);	
			}
			screen_matrix++;
		}
	}
}
