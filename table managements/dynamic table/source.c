#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	int n;
	int suma = 0;
	int* liczby;
	int* temp;
	printf("Podaj n: ");
	scanf_s("%d", &n);
	liczby = (int*)malloc(n * sizeof(int));
	temp = liczby;
	if (liczby) {
		for (int i = 1; i <= n; i++) {
			printf("%d. ", i);
			scanf_s("%d", liczby);
			liczby++;
		}
	}
	else printf("Pamiec nie zostala przydzielona");
	liczby = temp;
	for (int i = 0; i < n; i++) {
		suma += *liczby;
		liczby++;
	}
	free(temp);
	printf("Suma %d podanaych liczb wynosi: %d", n, suma);
	getchar();
	getchar();
	return 0;
}