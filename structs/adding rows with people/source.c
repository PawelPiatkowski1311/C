#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 255

struct zbiorka {
	char imie[MAX];
	char nazwa[MAX];
	int kwota;

};

int main() {
	int iloscOsob;
	char name[MAX];
	char nazwa[MAX];
	int kwota;
	puts("Podaj ilosc osob do dodania: ");
	scanf_s("%d", &iloscOsob);
	puts("Informacje: ");
	struct zbiorka element[MAX];
	for (int i = 0; i < iloscOsob; i++) {
		getchar();
		printf("Imie osoby: ");
		fgets(name, MAX, stdin);
		name[strcspn(name, "\n")] = 0;
		strcpy_s(element[i].imie, MAX, name);
		printf("Nazwa grupy: ");
		fgets(nazwa, MAX, stdin);
		nazwa[strcspn(nazwa, "\n")] = 0;
		strcpy_s(element[i].nazwa, MAX, nazwa);
		printf("Kwota: ");
		scanf_s("%d", &kwota);
		element[i].kwota = kwota;
	}
	for (int i = 0; i < iloscOsob; i++) {
		printf("Imie: %s, Grupa: %s; kwota: %d\n", element[i].imie, element[i].nazwa, element[i].kwota);
	}
	getchar();
	getchar();
	return 0;
}