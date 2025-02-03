#include <stdio.h> // plik nagłówkowy obsługujący operacje wejścia i wyjścia

int main() // wywołanie funkcji
{
    int liczba = 42;  // definiowanie zmiennej

    // wyświetlenie liczb w formacie zmiennoprzecinkowym
    printf("Zmiennoprzecinkowa (1 miejsce po przecinku): %.1f\n", (float)liczba);
    printf("Zmiennoprzecinkowa (3 miejsce po przecinku): %.3f\n", (float)liczba);

    // wyświetlenie liczby w formacie napisowym (jako int)
    printf("Liczba jako int: %d", &liczba);

    // okienko wygasa po naciśnięciu enter
    getchar();
    return 0;
}
