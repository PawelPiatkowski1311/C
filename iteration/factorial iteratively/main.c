#include <stdio.h>

int main() {
	// inicjalizacja zmiennych
	int n, i;
	int silnia = 1;

	// Wczytanie danych
	printf("Podaj n: ");
	scanf_s("%d", &n);

	// Petla for - iloczyn liczb od 1 do n
	for (i = 1; i <= n; i++) {
		silnia *= i;
	}

	// Wynik
	printf("Silnia z %d wynosu: %d", n, silnia);
	getchar();
	getchar();
	return 0;
}