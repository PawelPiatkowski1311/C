#include <stdio.h>

int main() {
	int macierz[3][3];
	printf("Podaj elementy macierzy:\n\n");
	printf("| a1 a2 a3 |\n");
	printf("| a4 a5 a6 |\n");
	printf("| a7 a8 a9 |\n\n");
	for (int wiersz = 0; wiersz <= 2; wiersz++) {
		for (int kolumna = 0; kolumna <= 2; kolumna++) {
			printf("a%d: ", kolumna + wiersz * 3 + 1);
			scanf_s("%d", &macierz[wiersz][kolumna]);
		}
	}
	printf("\n");
	for (int wiersz = 0; wiersz <= 2; wiersz++) {
		printf("| ");
		for (int kolumna = 0; kolumna <= 2; kolumna++) {
			printf("%d ", macierz[wiersz][kolumna]);
		}
		printf("|\n");
	}
	getchar();
	getchar();
	return 0;
}