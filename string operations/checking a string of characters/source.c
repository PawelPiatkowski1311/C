#include <stdio.h>
#include <string.h>		// obs³uga operacji na ci¹gach znaków oraz wejœcia - wyjœcia
#include <stdbool.h>	// obs³uga zmiennej bool

size_t dlugosc;	// size_t, poniewaz funkcja strlen, zwraca dane tego typu

bool znajduje_sie_w(char znak, char* wsk);

int main() {
	char lancuch[255];
	char znak;
	bool wynik;
	printf("Podaj lancuch: ");
	fgets(lancuch, sizeof(lancuch), stdin);
	char* wsk = lancuch;
	dlugosc = strlen(lancuch);
	for (int i = 0; i < dlugosc - 1; i++) {
		printf("Podaj znak, aby sprawdzic, czy znajduje on sie w lancuchu: ");
		scanf_s("%c%*c", &znak, 1);	// zapis %c%*c usuwa znak nowej linii "\n", ktora zostaje w buforze bo nacisnieciu enter - zatwierdzeniu
		wynik = znajduje_sie_w(znak, wsk);
		if (wynik == true) puts("Prawda");
		else puts("Falsz");
	}
	return 0;
}

bool znajduje_sie_w(char znak, char* wsk) {
	for (int i = 0; i < dlugosc - 1; i++) {	// dlugosc -1, poniewaz funkcja fgets dodaje znak nowej linii do ci¹gu, co jest niepozadane
		if (*wsk == znak) {
			return true;
		}
		wsk++;
	}
	return false;
}