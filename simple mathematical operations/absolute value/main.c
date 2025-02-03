#include <stdio.h>

int main() {
    int n;
    printf("Podaj liczbe calkowita: ");
    scanf_s("%d", &n);
    if (n < 0) {
        n = -n;
    }
    printf("Wartosc bezwzgledna: %d", n);
    getchar();
    getchar();
    return 0;
}