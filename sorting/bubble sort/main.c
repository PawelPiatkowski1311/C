#include <stdio.h>

int main() {
	// Inicjacja zmiennych
	int d[] = {9,7,5,3,2}; // Tablica liczb do posortowania
	int n = sizeof(d) / sizeof(d[0]); // Liczba elementów
	int temp; // Zmienna tymczasowa
	for (int i = 0; i < n - 1 ; i++) { // Pêtla powtarzaj¹ca siê o iloœæ elementów
		for (int j = 0; j < n - i - 1; j++) { // Pêtla z ka¿dym wykonaniem powtarzaj¹ca siê o 1 raz mniej
			if (d[j] > d[j+1]) { // Je¿eli j element tablicy jest wiêkszy od j+1 elementu tablicy, to zwróc prawdê

				// Zamiana elementów miejscami
				temp = d[j + 1];
				d[j + 1] = d[j];
				d[j] = temp;
			}
		}
	}

	// Drukowanie kolejnych, posortowanych elementów tablicy
	for (int i = 0; i < n; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}