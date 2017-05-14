#include <stdio.h>
#include <stdlib.h>

#include "mzapo_phys.h"
#include "mzapo_regs.h"
#include "mzapo_parlcd.h"

#include "game_utils.h"
#include "game_unit.h"
#include "game_level.h"

#define MAIN_UNIT_PATH  	"./content/units/pacman/pacman_right.bmp"
#define MAIN_UNIT_WIDTH 	16
#define MAIN_UNIT_HEIGHT	16

#define LEVEL_FILE_PATH 	"./content/levels/labyrinth_mask.txt"
#define LEVEL_WIDTH 		30
#define LEVEL_HEIGHT 		20

#define SCREEN_WIDTH  		480
#define SCREEN_HEIGHT 		320


void draw_screen_matrix(unsigned char *parlcd_mem_base, uint16_t *screen_matrix);

int main() {
	unsigned char *parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);
	unsigned char *level_matrix = (unsigned char *) malloc(LEVEL_WIDTH * LEVEL_HEIGHT);
	uint16_t *screen_matrix = (uint16_t *) malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint16_t));
	
	uint16_t *unit_matrix = load_image(MAIN_UNIT_PATH, MAIN_UNIT_WIDTH, MAIN_UNIT_HEIGHT);
	
	
	read_level(LEVEL_FILE_PATH, level_matrix);
	add_level_as_background(level_matrix, screen_matrix);
	add_unit_to_screen(screen_matrix, unit_matrix, 16, 16);
	
	parlcd_hx8357_init(parlcd_mem_base);
	draw_screen_matrix(parlcd_mem_base, screen_matrix);
	
	
	free(level_matrix);
	free(screen_matrix);
	free(unit_matrix);

    return 0;
}

void draw_screen_matrix(unsigned char *parlcd_mem_base, uint16_t *screen_matrix) {
	int i, j;
	
	parlcd_write_cmd(parlcd_mem_base, 0x2c);
	for (i = 0; i < SCREEN_HEIGHT ; i++) {
		for (j = 0; j < SCREEN_WIDTH ; j++, screen_matrix++) {
			parlcd_write_data(parlcd_mem_base, *screen_matrix);
		}
	}
}
