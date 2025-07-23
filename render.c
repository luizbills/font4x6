#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "font4x6.h"

void usage(char *exec) {
    printf("Usage: %s <char_code>\n", exec);
    printf("       <char_code> Decimal character code between 0 and 127\n");
}

void render(char *bitmap, int x) {
    for (int y=0; y < 4; y++) {
            if ( bitmap[x] & 1 << y) {
		//print a white box
                printf("\033[47m  \033[0m");
            } else {
		//print a black box
                printf("\033[40m  \033[0m");
            }

    }
}

int main(int argc, char **argv) {

	int ord;
	if (argc != 2) {
		usage(argv[0]);
		return 1;
	}
	int len = strlen(argv[1]);
	for(int j = 0; j < 6 ; j ++){
	    for (int i =0; i<len; i++){
		
			ord = (int)argv[1][i];
		    	if (ord > 127 || ord < 0) {
				usage(argv[0]);
				return 2;
		    	}
		    	uint8_t *bitmap = font4x6_basic[ord];
		    	render(bitmap, j);

	} 
	printf("\n");
	}
	return 0;

}
