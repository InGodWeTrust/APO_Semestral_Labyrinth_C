#include "game_unit.h"


void add_unit_to_screen(uint16_t *screen_matrix, uint16_t *unit_matrix, int x_pos, int y_pos) {
	int i, j;
	
	for (i = 0; i < MAIN_UNIT_HEIGHT; i++) {
		for (j = 0; j < 30; j++, unit_matrix++) {
			*(screen_matrix + i*SCREEN_WIDTH + j) = 0x0000;
		}
		for (j = 30; j < 40; j++, unit_matrix++) {
			*(screen_matrix + i*SCREEN_WIDTH + j) = 0xffff;
		}
	}
}
