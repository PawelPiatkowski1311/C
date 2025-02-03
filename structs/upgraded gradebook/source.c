#include <stdio.h>
#include <stdlib.h>     // obs�uga malloc
#include <malloc.h>     //
#include <stdbool.h>
#include <string.h>
#define MAX 255         // umowna maksymalna dlugosc nazwiska

// struktura studenci
struct studenci {
	char nazwisko[MAX];
	struct tm* data;
	int indeks;
	int ocenaPE;
	int ocenaAISD;
	int ocenaNP;
	struct studenci* prev;
	struct studenci* next;
};

// struktura przechowuj�ca date
struct tm
{
	int dzien;
	int miesiac;
	int rok;
};

// inicjalizacja wska�nik�w 
struct studenci* head = NULL;
struct studenci* tail = NULL;
struct studenci* wsk;     // wska�nik g��wny, s�u�y do wskazywania adres�w ka�dej struktury
void wyswietl(struct studenci* wsk);
void wyswietlListe();
void usuwanie(int i);
void wyszukiwanie(char* nazwiskoSearch);
void sortowanie();
void najwyzszaOcena();
void najwyzszaSredniaOcen();
int czyPusty();
int compare(const void* arg1, const void* arg2);

int main() {
	int n;

	// zmienne Local s�u�y� b�d� do przechowywania danych na czas ich wprowadzania
	char nazwiskoLocal[MAX];
	int dzienLocal;
	int miesiacLocal;
	int rokLocal;
	int ocenaPELocal;
	int ocenaAISDLocal;
	int ocenaNPLocal;

	int egzemplarz;			// zmienna przechowywa� b�dzie nr elementu struktury, kt�ry b�dzie mia� by� wy�wietlony
	printf("Podaj n: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		wsk = (struct studenci*)malloc(sizeof(struct studenci));		// przypisanie do wska�nika array zaalokowanego bloku pami�ci
		printf("Podaj nazwisko studenta: ");
		getchar();
		fgets(nazwiskoLocal, sizeof(nazwiskoLocal), stdin);
		nazwiskoLocal[strcspn(nazwiskoLocal, "\n")] = 0;			// usuni�ty zostaje znak nowej linii, kt�ry dodaje funkcja fgets
		strcpy_s(wsk->nazwisko, MAX, nazwiskoLocal);				// przypisanie �a�cucha znak�w do zmiennej nazwisko struktury studenci
		printf("Podaj date urodzenia:\n");
		printf("Dzien: ");
		scanf_s("%d", &dzienLocal);
		printf("Miesiac: ");
		scanf_s("%d", &miesiacLocal);
		printf("Rok: ");
		scanf_s("%d", &rokLocal);
		wsk->data = (struct tm*)malloc(sizeof(struct tm));		// program musi dla ka�dego studenta osobno zaalokowa� blok pami�ci dla struktury obs�uguj�cej date
		if (wsk->data) {											// je�li wska�nik nie wskazuje na NULL program wykonuje si� dalej
			wsk->data->dzien = dzienLocal;
			wsk->data->miesiac = miesiacLocal;
			wsk->data->rok = rokLocal;
		}
		wsk->indeks = i + 1;										// do i zostaje dodane 1, poniewa� p�tla odlicza zmienn� i od 0, a program odlicza� indeksy b�dzie od liczby 1
		printf("Podaj ocene z przedmiotu Podstawy elektroniki: \n");
		scanf_s("%d", &ocenaPELocal);
		printf("Podaj ocene z przedmiotu Algorytmy i struktury danych: \n");
		scanf_s("%d", &ocenaAISDLocal);
		printf("Podaj ocene z przedmiotu Narzedzia programistyczne: \n");
		scanf_s("%d", &ocenaNPLocal);
		wsk->ocenaPE = ocenaPELocal;
		wsk->ocenaAISD = ocenaAISDLocal;
		wsk->ocenaNP = ocenaNPLocal;
		wsk->next = NULL;
		if (czyPusty() != 0)			// Je�li kolejka jest niepusta,
		{								// element dodany zostanie na koniec kolejki adjusting the last node's next pointer to point
			wsk->prev = tail;			// Wska�nik adresu poprzedniego elementu kolejki ustawiony jest, na element znajduj�cy si� w ogonie
			tail->next = wsk;			// Wska�nik adresu nast�pnego elementu ustawiony jest na nowo dodany element
		}
		else {							// Je�li kolejka jest pusta,
			wsk->prev = NULL;			// wska�nik adresu poprzedniego elementu kolejki ustawiony jest na NULL
			head = wsk;					// do g�owy przypisany zostaje nowo dodany element
		}
		tail = wsk;						// Na koniec do ogona przypisany zostaje nowo dodany element
		printf("\n");
	}
	printf("Podaj jedna z instrukcji:\n");
	printf("e - aby wyswietlic wybrany egzemplarz\n");
	printf("l - aby wyswietlic liste studentow\n");
	printf("u - aby usunac studenta o podanym indeksie\n");
	printf("n - aby wyszukac studenta wedlug nazwiska\n");
	printf("s - aby posortowac liste studentow alfabetycznie\n");
	printf("m - aby znalezc z studenta z najwyzsza ocena z danego przedmiotu\n");
	printf("a - aby znalezc studenta z najwyzsza srednia ocen\n");
	char instrukcja;        // Info od u�ytkownika
	int i;
	char nazwiskoSearch[MAX];
	while (1) {
		scanf_s("%c", &instrukcja, 1);
		switch (instrukcja) {
		case 'e':            // wyswietlanie
			printf("Podaj egzemplarz do wyswietlenia: ");
			scanf_s("%d", &egzemplarz);
			wsk = head;
			for (int i = 0; i < egzemplarz - 1; i++) {
				wsk = wsk->next;
			}
			wyswietl(wsk);
			break;
		case 'l':            // wyswietlanie
			wyswietlListe();
			break;
		case 'u':            // usuwanie
			printf("Podaj indeks: ");
			scanf_s("%d", &i);
			usuwanie(i);
			break;
		case 'n':            // wyszukiwanie
			printf("Podaj nazwisko: ");
			getchar();
			fgets(nazwiskoSearch, sizeof(nazwiskoSearch), stdin);
			nazwiskoSearch[strcspn(nazwiskoSearch, "\n")] = 0;
			wyszukiwanie(nazwiskoSearch);
			break;
		case 's':            // sortowanie
			sortowanie();
			break;
		case 'm':            // najwyzsza ocena
			najwyzszaOcena();
			break;
		case 'a':            // najwyzsza srednia
			najwyzszaSredniaOcen();
			break;
		default:			 //nieznana instrukcja
			break;
		}
	}
	return 0;
}

void wyswietl(struct studenci* wsk) {
	printf("Nazwisko: %s\n", wsk->nazwisko);
	printf("Data urodzenia: %02d.%02d.%d\n", wsk->data->dzien, wsk->data->miesiac, wsk->data->rok);
	printf("Nr indeku: %d\n", wsk->indeks);
	printf("Oceny:\n");
	printf("Podstawy elektroniki: %d\n", wsk->ocenaPE);
	printf("Algorytmy i struktury danych: %d\n", wsk->ocenaAISD);
	printf("Narzedzia programistyczne: %d\n", wsk->ocenaNP);
}

void wyswietlListe() {
	int i = 1;
	wsk = head;
	if (czyPusty() != 0) {
		while (wsk != NULL) {
			printf("%d. %s\n", i, wsk->nazwisko);
			wsk = wsk->next;
			i++;
		}
	}
	else printf("lista student�w jest pusta!");
}

void usuwanie(int i) {
	struct studenci* temp;
	struct studenci* temp2;
	wsk = head;
	do {
		if (wsk->indeks == i) {
			if (czyPusty() != 0) {			// Je�li kolejka jest niepusta
				printf("Egzemplarz studenta: %s zostaje usuniety\n", wsk->nazwisko);	// Wydrukowana zostaje liczba zapisana w elemencie, kt�ry zostaje usuni�ty
				temp = wsk->next;
				temp2 = wsk->prev;
				if (wsk->next) temp->prev = wsk->prev;
				else tail = wsk->prev;
				if (wsk->prev) temp2->next = wsk->next;
				else head = wsk->next;
				free(wsk->data);
				free(wsk);
				break;
			}
			else {							// Je�li kolejka jest pusta
				printf("kolejka jest pusta!\n");
			}
		}
		wsk = wsk->next;
	} while (wsk->next != NULL);
}

void wyszukiwanie(char* nazwisko) {
	wsk = head;
	do {
		if (strcmp(wsk->nazwisko, nazwisko) == 0) {
			wyswietl(wsk);
			break;
		}
		wsk = wsk->next;
	} while (wsk != NULL);
}

// funkcja nieuko�czona
void sortowanie() {
	int i = 0;
	struct studenci* temp;
	struct studenci* array = (struct studenci*)malloc(i * sizeof(struct studenci));
	struct studenci* temp2;
	int size = sizeof(array) / sizeof(array[0]);
	wsk = head;
	temp2 = array;
	while (wsk != NULL) {
		array = wsk;
		array++;
		i++;
	}
	array = temp2;
	//qsort(array, size, sizeof(struct studenci* ), compare);
	for (int j = 0; j < size; j++) {
		// koniec
	}
}

// funkcja nieuko�czona
void najwyzszaOcena() {
	wsk = head;
	struct studenci* temp;
	while (wsk != NULL) {
		wsk = wsk->next;
	}
}

// funkcja nieuko�czona
void najwyzszaSredniaOcen() {
	printf("");
}

int czyPusty() {
	if (head == NULL) return 0;	// Je�eli kolejka jest pusta zwr�cone zostanie 0
	else return 1;					// w przeciwnym wypadku 1
}

/*int compare(const void* arg1, const void* arg2) {
	return strcasecmp(*(const char**)arg1, *(const char**)arg2);
}*/