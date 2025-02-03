#include <stdio.h>

double min(double x, double y) {
	if(x < y) {
		return x;
	}
	else
	{
		return y;
	}
}
int main() {
	double x, y;
	printf("Podaj x: ");
	scanf_s("%lf", &x);
	printf("Podaj y: ");
	scanf_s("%lf", &y);
	double wynik = min(x, y);
	printf("Wartosc mniejsza z podanych liczb to: %g", wynik);
	getchar();
	getchar();
	return 0;
}