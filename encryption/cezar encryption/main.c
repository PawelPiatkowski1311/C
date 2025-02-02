#include <stdio.h>
#include <string.h>
#define MAX 255

int main() {
	char napis[MAX];
	char szyfr[MAX];
	char instrukcja;
	size_t dlugosc;
	int ascii;
	printf("Podaj instrukcje: \n");
	printf("s - szyfrowanie tekstu\n");
	printf("r - rozszyfrowanie tekstu\n");
	printf("x - wyjscie z programu\n");
	while (1) {
		scanf_s("%c", &instrukcja, 1);
		switch (instrukcja) {
		case 's':
			printf("Podaj tekst do zakodowania: ");
			getchar();
			fgets(napis, sizeof(napis), stdin);
			dlugosc = strlen(napis) - 1;
			for (int i = 0; i < dlugosc; i++) {
				ascii = napis[i];
				ascii += 3;
				if (ascii > 122) ascii -= 26; // odjêcie iloœci liter w alfabecie pozwala na zawijanie alfabetu
				napis[i] = (char)ascii;
			}
			printf("Tekst zaszyfrowany: %s", napis);
			break;
		case 'r':
			printf("Podaj szyfr: ");
			getchar();
			fgets(szyfr, sizeof(szyfr), stdin);
			dlugosc = strlen(szyfr) - 1;
			for (int i = 0; i < dlugosc; i++) {
				ascii = szyfr[i];
				ascii -= 3;
				if (ascii < 97) ascii += 26; // odjêcie iloœci liter w alfabecie pozwala na zawijanie alfabetu
				szyfr[i] = (char)ascii;
			}
			printf("Rozszyfrowany tekst: %s", szyfr);
			break;
		case 'x':
			return 0;
		default:
			printf("Nieznane polecenie!");
			break;
		}
	}
	return 0;
}