#ifndef GAME_UNIT_H
#define GAME_UNIT_H

typedef struct movable_unit {
	char orientation,
	movale_unit_type unit_type,
	int x_pos,
	int y_pos
}

typedef enum movale_unit_type {
	MAIN_UNIT = 0,
	HUNTER_UNIT = 1
}

#endif

