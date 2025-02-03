#include <stdio.h>

int main() {
    int a, b, c, d;
    int ilosc = 0;
    printf("Podaj liczbe a: ");
    scanf_s("%d", &a);
    printf("Podaj liczbe b: ");
    scanf_s("%d", &b);
    printf("Podaj liczbe c: ");
    scanf_s("%d", &c);
    printf("Podaj liczbe d: ");
    scanf_s("%d", &d);
    if (a > 0) {
        ilosc += 1;
    }
    if (b > 0) {
        ilosc += 1;
    }
    if (c > 0) {
        ilosc += 1;
    }
    if (d > 0) {
        ilosc += 1;
    }
    if (ilosc > 2) {
        printf("Liczb nieujemnych jest wiecej");
    }
    else {
        printf("Liczb ujemnych jest wiecej");
    }
    getchar();
    getchar();
    return 0;
}