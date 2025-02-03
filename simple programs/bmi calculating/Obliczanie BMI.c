#include <stdio.h> // plik nagłówkowy obsługujący operacje wejścia i wyjścia
#include <math.h> // plik nagłówkowy obsługujący operacje matematyczne

int main() // wywołanie funkcji
{

    //definiowanie zmiennych
    int wzrost;
    int waga;
    float wzrostMetry;
    float bmi;

    // wyświetlanie komunikatów oraz wprowadzanie danych
    printf("Podaj wzrost [cm]: ");
    scanf("%d", &wzrost);
    printf("Podaj wage [kg]: ");
    scanf("%d", &waga);
    
    // operacje matematyczne
    wzrostMetry = wzrost / 100.00f; // przeliczanie wzrostu z cm na metry
    bmi = waga / pow(wzrostMetry, 2); // obliczanie BMI

    // wyświetlenie wyniku
    printf("Twoje BMI wynosi: %.2f", bmi);

    // okienko wygasa po naciśnięciu enter
    getchar();
    getchar();
    return 0;
}
