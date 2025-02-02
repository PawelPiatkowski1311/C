#include <stdio.h>

int main() {
	// Inicjacja zmiennych
	int d[] = {9,7,5,3,2}; // Tablica liczb do posortowania
	int n = sizeof(d) / sizeof(d[0]); // Liczba element�w
	int temp; // Zmienna tymczasowa
	for (int i = 0; i < n - 1 ; i++) { // P�tla powtarzaj�ca si� o ilo�� element�w
		for (int j = 0; j < n - i - 1; j++) { // P�tla z ka�dym wykonaniem powtarzaj�ca si� o 1 raz mniej
			if (d[j] > d[j+1]) { // Je�eli j element tablicy jest wi�kszy od j+1 elementu tablicy, to zwr�c prawd�

				// Zamiana element�w miejscami
				temp = d[j + 1];
				d[j + 1] = d[j];
				d[j] = temp;
			}
		}
	}

	// Drukowanie kolejnych, posortowanych element�w tablicy
	for (int i = 0; i < n; i++) {
		printf("%d ", d[i]);
	}
	return 0;
}