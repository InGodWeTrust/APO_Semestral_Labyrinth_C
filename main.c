#include <stdio.h>

#include "mzapo_phyz.h"
#include "mzapo_parlcd.h"

int main() {
	
	unsigned char *parlcd_mem_base;
	int i, j;
	unsigned c;

	parlcd_mem_base = map_phys_address(PARLCD_REG_BASE_PHYS, PARLCD_REG_SIZE, 0);

	if (parlcd_mem_base == NULL)
		exit(1);

	parlcd_hx8357_init(parlcd_mem_base);

	parlcd_write_cmd(parlcd_mem_base, 0x2c);
	for (i = 0; i < 320 ; i++) {
		for (j = 0; j < 480 ; j++) {
			c = 0;
			parlcd_write_data(parlcd_mem_base, c);
		}
	}

	parlcd_write_cmd(parlcd_mem_base, 0x2c);
	for (i = 0; i < 320 ; i++) {
		for (j = 0; j < 480 ; j++) {
		c = ((i & 0x1f) << 11) | (j & 0x1f);
		if (i < 10)
			c |= 0x3f << 5;
		if (j < 10)
			c |= 0x3f << 5;
		parlcd_write_data(parlcd_mem_base, c);
		}
	}
	
    printf("Hello, World!\n");
    return 0;
}
