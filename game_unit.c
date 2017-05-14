#include "game_unit.h"


void add_unit_to_screen(uint16_t *screen_matrix, uint16_t *unit_matrix, int x_pos, int y_pos) {
    int i, j;

    for (i = y_pos; i < MAIN_UNIT_HEIGHT; i++) {
        for (j = x_pos; j < MAIN_UNIT_WIDTH; j++, unit_matrix++) {
            *(screen_matrix + i * SCREEN_WIDTH + j) = *unit_matrix;
        }
    }
}
