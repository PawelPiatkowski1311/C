#include <stdio.h>

int main() {
    int ascii = 32;
    int kolumna;
    while(ascii <= 255) {
        for (kolumna = 1; kolumna <= 16; kolumna++) {
            printf("%c ", ascii);
            ascii++;
        }
        printf("\n");
    }
    getchar();
    getchar();
    return 0;
}