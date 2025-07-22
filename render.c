#include <stdio.h>
#include <stdlib.h>

#include "font4x6.h"

void usage(char *exec) {
    printf("Usage: %s <char_code>\n", exec);
    printf("       <char_code> Decimal character code between 0 and 127\n");
}

void render(char *bitmap) {
    int x,y;
    int set;
    int mask;
    for (y=0; y < 6; y++) {
        for (x=0; x < 4; x++) {
            set = bitmap[y] & 1 << x;
            printf("%c", set ? 'X' : ' ');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int ord;
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }
    ord = atoi(argv[1]);
    if (ord > 127 || ord < 0) {
        usage(argv[0]);
        return 2;
    }
    char *bitmap = font4x6_basic[ord];

    render(bitmap);
    return 0;
}
