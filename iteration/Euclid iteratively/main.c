#include <stdio.h>

int main() {
	int a;
	int b;
	int temp;
	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj b: ");
	scanf_s("%d", &b);
	while (a % b != 0) {
		temp = b;
		b = a % b;
		a = temp;
	}
	printf("NWD wynosi: %d", b);
	getchar();
	getchar();
	return 0;
}