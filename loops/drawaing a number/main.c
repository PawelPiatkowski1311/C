#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a = 1;
    int iloscProb = 0;
    srand(time(0));
    do {
        a = (rand() % 6) + 1;
        iloscProb++;
        printf("Wylosowana liczba: %d\n", a);
    }
    while (a != 6);
    printf("Udalo sie za %d razem", iloscProb);
    getchar();
    getchar();
    return 0;
}