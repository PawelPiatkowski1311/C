#include <stdio.h> // plik nagłówkowy obsługujący operacje wejścia i wyjścia

int main() // wywołanie funkcji
{
    int ascii; // definiowanie zmiennej

    // wyświetlenie komunikatu oraz pobranie danych
    printf("Wpisz kod ASCII: ");
    scanf("%d", &ascii);

    // wyświetlenie właściwego symbolu
    printf("%c",(char)(ascii));

    // okienko wygasa po naciśnięciu enter
    getchar();
    getchar();
    return 0;
}