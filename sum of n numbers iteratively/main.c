#include <stdio.h>

int main()
{
    int n;
    int suma = 0;
    printf("Podaj n: ");
    scanf_s("%d", &n);
    for (n; n > 0; n--) {
        suma += n;
    }
    printf("Suma n pierwszych liczb naturalnych wynosi: %d", suma);
    getchar();
    getchar();
    return 0;
}