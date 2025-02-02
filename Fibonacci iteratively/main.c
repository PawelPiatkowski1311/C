#include <stdio.h>

int main() {
	int n, i;
	printf("Podaj N: ");
	scanf_s("%d", &n);
	int a = 0;
	int b = 1;
	for (i = 0; i <= n-2; i++) {
		int c = a + b;
		a = b;
		b = c;
	}
	if (n == 0) {
		b = 0;
	}
	printf("%d element ciagu Fibonacciego wynosi: %d", n, b);
	getchar();
	getchar();
	return 0;
}