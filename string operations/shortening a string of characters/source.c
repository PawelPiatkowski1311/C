#include <stdio.h>
#include <string.h>

char* skracaj(char* wsk, int rozmiar);

int main() {
	char tab[255];
	int rozmiar;
	puts("Podaj lancuch znakow:");
	fgets(tab, sizeof(tab), stdin);
	char* wsk = tab;
	puts("Podaj rozmiar:");
	scanf_s("%d", &rozmiar);
	puts(skracaj(wsk, rozmiar));
	getchar();
	getchar();
	return 0;
}

char* skracaj(char* wsk, int rozmiar) {
	for (int i = strlen(wsk); i + 1 > rozmiar; i--) {
		wsk[i] = NULL;
	}
	return wsk;
}