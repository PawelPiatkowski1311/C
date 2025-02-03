#include <stdio.h>

int main() {
    int n;
    int i = 1;
    printf("Podaj liczbe N: ");
    scanf_s("%d", &n);
    while (i <= n) {
        if (i%2==1) {
            printf("%d ", i);
        }
        i++;
    }
    getchar();
    getchar();
    return 0;
}