#ifndef GAME_UNIT_H
#define GAME_UNIT_H

#include <stdint.h>

#define MAIN_UNIT_WIDTH 	16
#define MAIN_UNIT_HEIGHT	16
#define SCREEN_WIDTH  		480

typedef enum {
	LEFT 		= 	0,
	LEFT_DOWN 	= 	1,
	LEFT_UP 	= 	2,
	
	RIGHT 		= 	3,
	RIGHT_DOWN 	= 	4,
	RIGHT_UP 	= 	5
} unit_orientation ;

typedef enum {
	MAIN_UNIT = 0,
	HUNTER_UNIT = 1
} unit_type;

typedef struct {
	unit_orientation orientation;
	unit_type type;
	int x_pos;
	int y_pos;
} movable_unit;

void add_unit_to_screen(uint16_t *screen_matrix, uint16_t *unit_matrix, int x_pos, int y_pos);

#endif

