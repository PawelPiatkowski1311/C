#include <stdio.h> // plik nagłówkowy obsługujący operacje wejścia i wyjścia 
#include <math.h> // plik nagłówkowy obsługujący operacje matematyczne

int main() // wywołanie funkcji
{
    // definiowanie zmiennych
    int wiekLata;
    int wiekSekundy;

    // wyświetlenie komunikatu oraz pobranie danych
    printf("Podaj wiek w latach: ");
    scanf("%d", &wiekLata);

    // operacja matematyczna - iloczyn wieku w latach oraz ilości sekund w jednym roku, przypisanie wyniku do zmiennej wiekSekundy
    wiekSekundy = wiekLata * 3.156f * pow(10,7);

    // wyświetlenie komunikatu wraz z wynikiem
    printf("%d lat to inaczej %d sekund",(int)(wiekLata),(int)(wiekSekundy));

    // okienko wygasa po naciśnięciu enter
    getchar();
    getchar();
    return 0;
}