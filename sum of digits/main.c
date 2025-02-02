#include <stdio.h>

int main()
{
    int a;
    do {
        printf("Podaj a: ");
        scanf_s("%d", &a);
    } while (!(a > 1000));
    int cyfra;
    int suma = 0;
    while (a > 0) {
        cyfra = a % 10;
        a = (a - cyfra) / 10;
        suma += cyfra;
    }
    printf("Suma cyfr wynosi: %d ", suma);
    getchar();
    getchar();
    return 0;
}