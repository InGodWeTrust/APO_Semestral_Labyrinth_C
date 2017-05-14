#include "game_unit.h"


void add_unit_to_screen(uint16_t *screen_matrix, uint16_t *unit_matrix, int x_pos, int y_pos) {
    int i, j;

    for (i = x_pos; i < MAIN_UNIT_HEIGHT; i++) {
        for (j = y_pos; j < 30; j++, unit_matrix++) {
            *(screen_matrix + i * SCREEN_WIDTH + j) = *unit_matrix;
        }
    }
}
