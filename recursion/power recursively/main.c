#include <stdio.h>

int a;
int potega(n) {
	if (n == 0) {
		return 1;
	}
	else
	{
		return a * potega(n - 1);
	}
}
int main() {
	int n;
	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj n: ");
	scanf_s("%d", &n);
	int wynik = potega(n);
	printf("Potega %d z %d wynosi: %d", a, n, wynik);
	getchar();
	getchar();
	return 0;
}