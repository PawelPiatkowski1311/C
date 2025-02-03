#include <stdio.h>

int main() {
	int a;
	int b;
	int suma;
	int* wskaznikA = &a;
	int* wskaznikB = &b;
	int* wskaznikSuma = &suma;
	printf("Podaj 2 liczby:\n");
	printf("A: ");
	scanf_s("%d", wskaznikA);
	printf("B: ");
	scanf_s("%d", wskaznikB);
	*wskaznikSuma = *wskaznikA + *wskaznikB;
	printf("%d + %d = %d", *wskaznikA, *wskaznikB, *wskaznikSuma);
}