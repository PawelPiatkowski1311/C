#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

double sinWartosc;
double cosWartosc;
double tgWartosc;
int oblicz(double);

int main(double alfa) {
	printf("Podaj kat: ");
	scanf_s("%lf", &alfa);
	oblicz(alfa);
	printf("Wartosci funkcji trygonometrycznych dla kata %g wynosza: \nsin: %g\ncos: %g\ntg: %g", alfa, sinWartosc, cosWartosc, tgWartosc);
	getchar();
	getchar();
	return 0;
}

int oblicz(double stopnie) {
	double rad = stopnie * M_PI / 180;
	sinWartosc = sin(rad);
	cosWartosc = cos(rad);
	tgWartosc = tan(rad);
	return 0;
}