#include <stdio.h>

int n;
int b;
int temp;
int fibonacci(n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else
	{
		return fibonacci(n-1)+fibonacci(n-2);
	}
}

int main() {
	printf("Podaj n: ");
	scanf_s("%d", &n);
	int wynik = fibonacci(n);
	printf("%d elementem ciagu Fibonacciego jest: %d", n, wynik);
	getchar();
	getchar();
	return 0;
}