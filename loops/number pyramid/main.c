#include <stdio.h>

int main() {
    int wiersze;
    int liczba = 1;
    int i;
    int j;
    printf("Podaj ilosc wierszy: ");
    scanf_s("%d", &wiersze);
    for (i = 1; i <= wiersze; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", liczba);
            liczba++;
        }
        printf("\n");
    }
    getchar();
    getchar();
    return 0;
}