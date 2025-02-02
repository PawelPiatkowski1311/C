#include <stdio.h>

int main() {
	// Inicjacja zmiennych
	int a, n;
	int wynik = 1;
	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj n: ");
	scanf_s("%d", &n);
	for (n; n > 0; n--) {
		wynik = wynik * a;
	}
	printf("Potega wynosi: %d", wynik);
	getchar();
	getchar();
	return 0;
}