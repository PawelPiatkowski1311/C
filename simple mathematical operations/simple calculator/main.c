#include <stdio.h>

int main() {

    // Zdefiniowanie zmiennych
    float a;
    float b;
    char o;
    float wynik;

    // Pobranie danych od u¿ytkownika
    printf("Podaj pierwsza liczbe: ");
    scanf_s("%f", &a);
    printf("Podaj druga liczbe: ");
    scanf_s("%f", &b);
    printf("Wybierz operator (+ - / *): ");
    scanf_s(" %c", &o, 1);

    // Instrukcja warunkowa
    switch (o) {
    case '+':
        wynik = a + b;
        printf("%g + %g = %g", a, b, wynik);
        break;
    case '-':
        wynik = a - b;
        printf("%g - %g = %g", a, b, wynik);
        break;
    case '/':
        wynik = a / b;
        printf("%g / %g = %g", a, b, wynik);
        break;
    case '*':
        wynik = a * b;
        printf("%g * %g = %g", a, b, wynik);
        break;
    default:
        printf("\nPodany znak jest nieobslugiwany");
    }
    getchar();
    getchar();
    return 0;
}