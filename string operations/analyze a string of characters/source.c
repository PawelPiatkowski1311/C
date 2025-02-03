#include <stdio.h>
#include <string.h>		// obs�uga �a�cuch�w znak�w
#include <stdbool.h>	// obs�uga zmiennej bool
#define SIZE 255		// maksymalna d�ugo�� �a�cucha

void zlicz_wystapienia(char* tekst, int* litery, int* cyfry);
int zwroc_ilosc_wystapien(int* litery, int* cyfry, int znak);

size_t dlugosc;	// zmienna globalna d�ugo�ci znak�w �a�cucha

int main() {
	char lancuch[SIZE];
	int litery[2][SIZE];
	int cyfry[2][SIZE];
	char* tekst = lancuch;
	char znak;
	printf("Podaj tekst: ");
	fgets(tekst, SIZE, stdin);
	dlugosc = strlen(tekst) - 1;
	printf("Podaj znak do sprawdzenia: ");
	scanf_s("%c", &znak, 1);
	zlicz_wystapienia(tekst, litery, cyfry);
	printf("Zliczona ilosc wystepowania znaku: %d", zwroc_ilosc_wystapien(litery, cyfry, znak));
	getchar();
	getchar();
	return 0;
}

void zlicz_wystapienia(char* tekst, int* litery, int* cyfry) {
	int (*wierszLitery)[SIZE] = litery;	// zainicjowanie wska�nika do wskazywania na wiersze
	int* wierszLitery0 = wierszLitery;	// przypisanie adresu do wska�nika
	int* wierszLitery1 = wierszLitery + 1;	// przypisanie adresu o 1 wi�kszego, co oznacza na wskazywanie drugiego wiersza
	int (*wierszCyfry)[SIZE] = cyfry;
	int* wierszCyfry0 = wierszCyfry;
	int* wierszCyfry1 = wierszCyfry + 1;
	int kolumnaLitery = 0;	// wyliczanie element�w
	int kolumnaCyfry = 0;
	int* wsk;	// wska�nik element�w
	bool set;	// zmienna do ignorowania instrukcji
	for (int i = 0; i < dlugosc; i++) {
		set = true;

		// Sprawdzenie liter
		if (*tekst >= 97 && *tekst <= 122) {	// W tabeli ASCII ma�e literki s� przypisane do liczb z zakresu od 97 do 122
			for (int j = 0; j <= i; j++) {		// Aby zaoszcz�dzi� zasoby, p�tla wykonywana jest nie wi�cej ni� mo�e by� element�w w tabeli
				wsk = wierszLitery1;			// Ustawienie wska�nika na drugi wiersz tabeli
				wsk += j;						// Przesuni�cie wska�nika do j elementu tabeli

				// Sprawdzenie, czy dany znak wyst�puje ju� w tabeli
				if (*wsk == *tekst) {			// Je�eli ju� pojawi� si� ten sam znak z �a�cucha, dodana zostaje liczba 1 zamiast tworzony kolejny element
					wsk = wierszLitery0;		// Ustawienie wska�nika na pierwszy wiersz
					wsk += j;					// Przesuni�cie wska�nika do sprawdzanego elementu
					*wsk += 1;					// Dodanie 1 do ilo�ci wyst�powania znaku
					set = false;				// Ustawienie zmiennej set do false, aby nie dodawa� kolejnego elementu tabeli
					break;						// Je�eli znaleziony zosta� znak w tabeli, p�tla zostaje przerwana
				}
			}
			if (set == true) {					// Je�eli nie znaleziono danego znaku w tabeli utworzony zostanie nowy element
			wsk = wierszLitery1;				// Ustawienie wska�nika na drugi wiersz tabeli
			wsk += kolumnaLitery;				// Przesuni�cie wska�nika do niezapisanej kolumny
			*wsk = *tekst;						// Przypisanie do danego elementu, znaku
			wsk = wierszLitery0;				// Ustawienie wska�nika na pierwszy wiersz tabeli
			wsk += kolumnaLitery;				// Przesuni�cie wska�nika do niezapisanej kolumny
			*wsk = 1;							// Ustawienie liczby wyst�powania znaku na 1
			kolumnaLitery++;					// Inkrementacja zmiennej
			}
		}

		// Sprawdzenie cyfr
		if (*tekst >= 48 && *tekst <= 57) {		// W tabeli ASCII cyfry s� przypisane do liczb z zakresu od 48 do 57
			for (int j = 0; j <= i; j++) {
				wsk = wierszCyfry1;
				wsk += j;
				if (*wsk == *tekst) {
					wsk = wierszCyfry0;
					wsk += j;
					*wsk += 1;
					set = false;
					break;
				}
			}
			if (set == true) {
				wsk = wierszCyfry1;
				wsk += kolumnaCyfry;
				*wsk = *tekst;
				wsk = wierszCyfry0;
				wsk += kolumnaCyfry;
				*wsk = 1;
				kolumnaCyfry++;
			}
		}
		tekst++;
	}
}

int zwroc_ilosc_wystapien(int* litery, int* cyfry, int znak) {
	int (*wierszLitery)[SIZE] = litery;
	int* wierszLitery0 = wierszLitery;
	int* wierszLitery1 = wierszLitery + 1;
	int (*wierszCyfry)[SIZE] = cyfry;
	int* wierszCyfry0 = wierszCyfry;
	int* wierszCyfry1 = wierszCyfry + 1;
	int* wsk;
	int licznik = 0;
	for (int i = 0; i < dlugosc; i++) {
		wsk = wierszLitery1;
		wsk += i;
		if (*wsk == znak) {
			wsk = wierszLitery0;
			wsk += i;
			licznik += 1 * *wsk;
		}
		wsk = wierszCyfry1;
		wsk += i;
		if (*wsk == znak) {
			wsk = wierszCyfry0;
			wsk += i;
			licznik += 1 * *wsk;
		}
	}
	return licznik;
}