#include <stdio.h>

int n;
int pierwsza(n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return n + pierwsza(n-1);
	}
}

int main() {
	printf("Podaj n: ");
	scanf_s("%d", &n);
	int wynik = pierwsza(n);
	printf("Suma %d pierwszych liczb naturalnych wynosi: %d", n, wynik);
	getchar();
	getchar();
	return 0;
}