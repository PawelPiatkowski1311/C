#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void obliczenia(int*, double*);
void minMax(int, int, double, double);

int main() {
	int calkowite[10];
	double zmiennoprzecinkowe[10];
	srand(time(0));
	for (int i = 0; i < 10; i++) {
		calkowite[i] = (rand() % 101);
		zmiennoprzecinkowe[i] = (rand() % 101 / 100.0);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d ", calkowite[i]);
	}
	printf("\n");
	for (int i = 0; i < 10; i++) {
		printf("%g ", zmiennoprzecinkowe[i]);
	}
	int* wskaznikC = calkowite;
	double* wskaznikZ = zmiennoprzecinkowe;
	obliczenia(wskaznikC, wskaznikZ);
	getchar();
	getchar();
	return 0;
}

void obliczenia(int* c, double* z) {
	double suma = 0;
	for (int i = 0; i < 10; i++) {
		suma += *c;
		suma += *z;
		c++;
		z++;
	}
	printf("\n\nSuma wynosi: %g\n\n", suma);
	printf("Tablica liczb calkowitych:\n");
	c -= 6;
	int c1 = *c;
	printf("5 element: %d\n", *c);
	c += 5;
	int c2 = *c;
	printf("10 element: %d\n\n", *c);
	printf("Tablica liczb zmiennoprzecinkowych:\n");
	z -= 6;
	double z1 = *z;
	printf("5 element: %g\n", *z);
	z += 5;
	double z2 = *z;
	printf("10 element: %g\n\n", *z);
	minMax(c1, c2, z1, z2);
}

void minMax(int c1, int c2, double z1, double z2) {
	printf("Wartosci min / max tablicy liczb calkowitych: \n");
	if (c1 < c2) {
		printf("MIN: %d\n", c1);
		printf("MAX: %d\n", c2);
	}
	else {
		printf("MIN: %d\n", c2);
		printf("MAX: %d\n", c1);
	}
	printf("\nWartosci min / max tablicy liczb zmiennoprzecinkowych: \n");
	if (z1 < z2) {
		printf("MIN: %g\n", z1);
		printf("MAX: %g\n", z2);
	}
	else {
		printf("MIN: %g\n", z2);
		printf("MAX: %g\n", z1);
	}
}

