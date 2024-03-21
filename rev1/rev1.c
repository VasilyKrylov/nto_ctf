#include <stdio.h>
#include <stdlib.h>

int main() {
	int gen_mas[256];
	for (int i = 0; i < 256; ++i) {
	        unsigned long tmp_i = (unsigned long)i;
		for (int j = 0; j < 8; ++j) {
	 		if ((tmp_i & 1) == 0) {
				tmp_i = tmp_i >> 1;
			} else {
				tmp_i = tmp_i >> 1 ^ 0xedb88320;
			}
		}
		gen_mas[i] = (int)tmp_i;
	}
	for (int i = 0; i < 256; ++i) {
		//printf("%d %p\n", i, gen_mas[i]);
	}

	int data[14] = {0xEDCFE1F3, 0x646BCD23, 0x50F9AD57, 0xF299B1E1, 0xC6A9B6E4, 0x3280614C, 0x93772B02, 0xAB2C3A43, 0x2A0D936A, 0x1BFA14D4, 0x255D6F2F, 0xC447F66B, 0x5AD96CF5, 0xE964AD12};
	for (int i = 0; i < 256; ++i) {
		for (int j = 0; j < 256; ++j) {
			unsigned int mask = 0xffffffff;
			mask = gen_mas[(i ^ mask) & 0xff] ^ mask >> 8;
			mask = gen_mas[(j ^ mask) & 0xff] ^ mask >> 8;
			mask = ~mask;
			for (int k = 0; k < 14; ++k) {
				if (mask == data[k]) {
					printf("ok %d %c%c\n", k, i, j);
				} else {
					//printf("shit %p %p", data[k], mask);
				}
			}
		}
	}
}
