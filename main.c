#include <stdio.h>
#include <stdlib.h>

#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "mzapo_parlcd.h"

#define LEVEL_FILE_PATH "./content/levels/labyrinth_mask.txt"
#define LEVEL_WIDTH 	30
#define LEVEL_HEIGHT 	20

#define SCREEN_WIDTH  	480
#define SCREEN_HEIGHT 	320

typedef unsigned char byte;

void read_level(char *filename, byte *level_matrix);
void add_level_as_background(byte *level_matrix, uint16_t* screen_matrix);
void draw_screen_matrix(byte *parlcd_mem_base, uint16_t *screen_matrix);

int main() {
	byte *parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
	byte *level_matrix = (byte *) malloc(LEVEL_WIDTH * LEVEL_HEIGHT);
	uint16_t *screen_matrix = (uint16_t *) malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint16_t));
	
	read_level(LEVEL_FILE_PATH, level_matrix);
	add_level_as_background(level_matrix, screen_matrix);
	
	parlcd_hx8357_init(parlcd_mem_base);
	draw_screen_matrix(parlcd_mem_base, screen_matrix);
	
	
	free(level_matrix);
	free(screen_matrix);

    return 0;
}

void read_level(char *filename, byte *level_matrix) {
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

void add_level_as_background(byte *level_matrix, uint16_t* screen_matrix) {
	int i, j;
	
	int height_ratio = SCREEN_HEIGHT / LEVEL_HEIGHT;
	int width_ratio = SCREEN_WIDTH / LEVEL_WIDTH;
	
	for (i = 0; i < SCREEN_HEIGHT; i++) {
		for (j = 0; j < SCREEN_WIDTH; j++) {
			if (*(level_matrix + (i / height_ratio) * LEVEL_WIDTH + (j / width_ratio))) {
				*screen_matrix = 0x003366;
			} else {
				*screen_matrix = 0xFFFF;	
			} 
			screen_matrix++;
		}
	}
}

void draw_screen_matrix(byte *parlcd_mem_base, uint16_t *screen_matrix) {
	int i, j;
	
	parlcd_write_cmd(parlcd_mem_base, 0x2c);
	for (i = 0; i < SCREEN_HEIGHT ; i++) {
		for (j = 0; j < SCREEN_WIDTH ; j++) {
			parlcd_write_data(parlcd_mem_base, *screen_matrix);
			screen_matrix++;
		}
	}
}
