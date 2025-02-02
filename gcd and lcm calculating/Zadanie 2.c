#include <stdio.h>

int main()
{
    int a, b;
    printf("Podaj a: ");
    scanf_s("%d", &a);
    printf("Podaj b: ");
    scanf_s("%d", &b);
    int n = a;
    int nwd = b;
    int temp;
    while (n % nwd != 0) {
        temp = nwd;
        nwd = n % nwd;
        n = temp;
    }
    int nww = (a * b) / nwd;
    printf("NWD: %d\n", nwd);
    printf("NWW: %d\n", nww);
    getchar();
    getchar();

    return 0;
}
