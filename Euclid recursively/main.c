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
		temp = a;
		a = b;
		return nwd(temp % b);
	}
}

int main() {
	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj b: ");
	scanf_s("%d", &b);
	int wynik = nwd(b);
	printf("NWD wynosi: %d", wynik);
	getchar();
	getchar();
	return 0;
}