#include <stdio.h>

int main()
{
    int n;
    printf("enter n: ");
    scanf_s("%d", &n);
    int i = 2;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0) {
            printf("not the first");
            getchar();
            getchar();
            return 0;
        }
    }
    printf("first");
    getchar();
    getchar();
    return 0;
}