#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* tablica_wykonaj(int elem, int wart);
void wyswietl_tab(const int tab[], int n);

int main(void) {
	int* wt;
	int rozmiar;
	int wartosc;
	printf("Podaj liczbe elementow tablicy: ");
	scanf_s("%d", &rozmiar);
	while (rozmiar > 0)
	{
		printf("Podaj wartosc: ");
		scanf_s("%d", &wartosc);
		wt = tablica_wykonaj(rozmiar, wartosc);
		if (wt)
		{
			wyswietl_tab(wt, rozmiar);
			free(wt);
		}
		printf("Podaj liczbe elementow (<1 - koniec): ");
		scanf_s("%d", &rozmiar);
	}
	printf("Dziekuje za uwage.\n");
	getchar();
	getchar();
	return 0;
}int* tablica_wykonaj(int elem, int wart) {	int* temp;	int* wsk;	wsk = (int*)malloc(elem * sizeof(int));	temp = wsk;	for (int i = 0; i < elem; i++) {		*wsk = wart;		wsk++;	}	return temp;}void wyswietl_tab(const int tab[], int n) {	for (int i = 0; i < n; i++) {		printf("%d ", tab[i]);	}	printf("\n");}