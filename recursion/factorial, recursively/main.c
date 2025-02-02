#include <stdio.h>

// Funkcja silnia
int silnia(n) {
	// Instrukcje warunkowe do obliczania silni
	if (n == 0) { // Jezeli n = 0, wynik bedzie rowny 0
		return 0;
	} 
	else if (n == 1) { // "Punkt odniesienia", gdy zostanie spelniony ten warunek, funkcje, ktore sie wykonuja zaczynaja od liczby 1
		return 1;
	}
	else { // Mnozenie liczby n * n-1
		return n * silnia(n - 1);
	}
}
int main() {
	// Inicjalizacja zmiennej n
	int n;

	// Wczytanie danych
	printf("Podaj n: ");
	scanf_s("%d", &n);

	// Przypisanie zwroconej wartosci do zmiennej wynik, wywolanie funkcji silnia
	int wynik = silnia(n);

	// Wyswietlenie wyniku
	printf("%d", wynik);
	getchar();
	getchar();
	return 0;
}