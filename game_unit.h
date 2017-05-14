#ifndef GAME_UNIT_H
#define GAME_UNIT_H

typedef struct movable_unit {
	unit_orientation orientation,
	unit_type type,
	int x_pos,
	int y_pos
}

typedef enum unit_type {
	MAIN_UNIT = 0,
	HUNTER_UNIT = 1
}

typedef enum unit_orientation {
	LEFT 		= 	0,
	LEFT_DOWN 	= 	1,
	LEFT_UP 	= 	2,
	
	RIGHT 		= 	3,
	RIGHT_DOWN 	= 	4,
	RIGHT_UP 	= 	5
}

#endif

