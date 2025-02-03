#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int komunikacja();
char* konwersja(int);

int main() {
	komunikacja();
	getchar();
	getchar();
	return 0;
}

// Zdefiniowanie funkcji komunikacja
int komunikacja() {
	int a;
	printf("Podaj liczbe całkowitą w postaci dziesietnej: ");
	int czyLiczba = scanf_s("%d", &a);

	// Sprawdzenie czy podana wartość jest liczbą
	if (czyLiczba == 1) {
		char* wynik = konwersja(a);
		printf("Reprezentacja binarna z liczby %d wynosi: %s", a, wynik);
		return 0;
	}
	else {
		printf("Wprowadzona wartosc jest bledna");
		return 0;
	}
}

// Zdefiniowanie adresu funkcji konwersja
char* konwersja(int a) {
	bool czyUjemna;
	int resztaZDzielenia;
	static char wartoscBinarna[255] = "\0";
	static char wynik[255] = "\0";
	char temp[255] = "\0";
	int aWejsciowe = a;
	int n = 0;

	// Stwierdzenie czy liczba jest ujemna, oraz przypisanie do a wartości bezwzględnej
	if (a < 0) {
		czyUjemna = true;
		a *= -1;
	}
	else {
		czyUjemna = false;
	}

	// Konwersja liczby dziesiętnej na binarną przy użyciu systemu egipskiego
	do {
		resztaZDzielenia = a % 2;
		a = a / 2;
		sprintf_s(wartoscBinarna, 255, "%d" , resztaZDzielenia);
		strcat_s(temp, 255, wartoscBinarna);
	} while ((float)a / 2 != 0);

	// Instrukcja znaleziania ujemnej liczby binarnej
	if (czyUjemna == true) {

		// Odwrócenie bitów
		for (size_t i = 0, dlugoscTablicy = strlen(temp); i < dlugoscTablicy; i++) {
			if (temp[i] == '1') {
				temp[i] = '0';
			}
			else {
				temp[i] = '1';
			}
		}

		// Dopisanie jedynek do otrzymanej liczby
		for (size_t nowaDlugoscTablicy = strlen(temp), poczatkowaDlugoscTablicy = nowaDlugoscTablicy;
			nowaDlugoscTablicy < 2 * (poczatkowaDlugoscTablicy + (4 - poczatkowaDlugoscTablicy % 4)) || nowaDlugoscTablicy % 4 != 0;
			nowaDlugoscTablicy = strlen(temp)) {
			strcat_s(temp, 255, "1");
		}

		// Dodanie 1 bitu do otrzymanego wyniku
		if (temp[0] == '0') {
			temp[0] = '1';
		}
		else
		{
			int is = 0;
			for (is; temp[is + 1] != '0'; is++) {
				temp[is] = '0';
			}
			temp[is] = '0';
			temp[is + 1] = '1';
		}
	}
	else {
		while (strlen(temp) % 4 != 0) {
			strcat_s(temp, 255, "0");
		}
	}

	// Zapisanie otrzymanego ciągu znaków w odwrotnej (docelowej) kolejności oraz dodanie odstępów co 4 bity
	for (size_t i = 0, dlugoscTablicy = strlen(temp), element = i; i < dlugoscTablicy - 1; element++) {
		do {
			wynik[element] = temp[dlugoscTablicy - 1 - i];
			i++;
			element++;
		} while (i % 4 != 0 && i < dlugoscTablicy);
		if (temp[i] == '1' || temp[i] == '0' && dlugoscTablicy > 4) {
			wynik[element] = ' ';
		}
	}
	return wynik;
}