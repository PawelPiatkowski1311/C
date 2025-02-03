#include <stdio.h>
#include <math.h> // Biblioteka operacji matematycznych

// Zmienne zapisane, przed funkcją main, po to, aby nie były one nadpisywane w przypadku wprowadzenia nieprawidłowego znaku
char figura;
int a;
double pole;
int main() {
    printf("Wybierz figure, wpisz odpowiadajaca litere: \nKwadrat: k\nProstokat: p\nTrojkat: t\n>>");
    scanf_s("%c", &figura, 1);
    if (figura == 'k' || figura == 'K') {
        printf("Podaj bok a: ");
        scanf_s("%d", &a);
        pole = pow(a, 2);
    }
    else if (figura == 'p' || figura == 'P') {
        int b;
        printf("Podaj bok a: ");
        scanf_s("%d", &a);
        printf("Podaj bok b: ");
        scanf_s("%d", &b);
        pole = a * b;
    }
    else if (figura == 't' || figura == 'T') {
        int b;
        int c;
        int p; // Połowa obwodu
        printf("Podaj bok a: ");
        scanf_s("%d", &a);
        printf("Podaj bok b: ");
        scanf_s("%d", &b);
        printf("Podaj bok c: ");
        scanf_s("%d", &c);
        p = (a + b + c) / 2; // Obliczenie pola obwodu i podzielenie go przez 2
        pole = sqrt(p*(p-a)*(p-b)*(p-c));
    }
    else { // Obsługa błędu
        printf("Wprowadzony znak jest nieprawidlowy\n");
        getchar();
        main();
        return 0;
    }
    printf("Pole figury wynosi: %g", pole);
    getchar();
    getchar();
    return 0;
}