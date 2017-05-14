#include "game_utils.h"

uint16_t rgb_to_16(char r, char g, char b) {

	uint16_t rgb16 = 0;
	rgb16 |= (r * 31 / 255) << 11;
	rgb16 |= (g * 63 / 255) << 5;
	rgb16 |= (b * 31 / 255); 

	return rgb16;
}
