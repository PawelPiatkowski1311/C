#include <stdio.h>

int a;
int b;
int temp;
int nwd(b) {
	if (a % b == 0) {
		return b;
	}
	else
	{
		temp = b;
		b = a % b;
		a = temp;
		return nwd(b); // do naprawy
	}
}

int main() {
	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj b: ");
	scanf_s("%d", &b);
	int wynik = nwd();
	printf("%d", wynik);
	getchar();
	getchar();
	return 0;
}