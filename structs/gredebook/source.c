#include <stdio.h>
#include <stdlib.h>     // obs�uga malloc
#include <malloc.h>     //
#define MAX 255         // umowna maksymalna dlugosc nazwiska

// struktura studenci
struct studenci {
	char nazwisko[MAX];
	struct tm* data;
	int indeks;
	int ocenaPE;
	int ocenaAISD;
	int ocenaNP;
};

// struktura przechowuj�ca date
struct tm
{
	int dzien;
	int miesiac;
	int rok;
};

// inicjalizacja wska�nik�w 
struct studenci* array;     // wska�nik g��wny, s�u�y do wskazywania adres�w ka�dej struktury
struct studenci* temp;      // przechowuje adres pierwszego elementu struktury, aby bez problemu funkcja wy�wietl mog�a si� odnosi� do element�w
void wyswietl(egzemplarz);

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
	array = (struct studenci*)malloc(n * sizeof(struct studenci));		// przypisanie do wska�nika array zaalokowanego bloku pami�ci
	temp = array;														// ten sam adres przypisany zostaje r�wnie� do zmiennej pomocniczej temp, dzi�ki czemu b�dzie mo�na bez problemu odnosi� sie do ka�dego elementu
	if (array) {														// program wykonuje si� pod warunkiem, je�li array nie wskazuje na NULL, co oznacza brak dost�pnej pami�ci
		for (int i = 0; i < n; i++) {
			printf("Podaj nazwisko studenta: ");
			getchar();
			fgets(nazwiskoLocal, sizeof(nazwiskoLocal), stdin);
			nazwiskoLocal[strcspn(nazwiskoLocal, "\n")] = 0;			// usuni�ty zostaje znak nowej linii, kt�ry dodaje funkcja fgets
			strcpy_s(array->nazwisko, MAX, nazwiskoLocal);				// przypisanie �a�cucha znak�w do zmiennej nazwisko struktury studenci
			printf("Podaj date urodzenia:\n");
			printf("Dzien: ");
			scanf_s("%d", &dzienLocal);
			printf("Miesiac: ");
			scanf_s("%d", &miesiacLocal);
			printf("Rok: ");
			scanf_s("%d", &rokLocal);
			array->data = (struct tm*)malloc(sizeof(struct tm));		// program musi dla ka�dego studenta osobno zaalokowa� blok pami�ci dla struktury obs�uguj�cej date
			if (array->data) {											// je�li wska�nik nie wskazuje na NULL program wykonuje si� dalej
				array->data->dzien = dzienLocal;
				array->data->miesiac = miesiacLocal;
				array->data->rok = rokLocal;
			}
			array->indeks = i + 1;										// do i zostaje dodane 1, poniewa� p�tla odlicza zmienn� i od 0, a program odlicza� indeksy b�dzie od liczby 1
			printf("Podaj ocene z przedmiotu Podstawy elektroniki: \n");
			scanf_s("%d", &ocenaPELocal);
			printf("Podaj ocene z przedmiotu Algorytmy i struktury danych: \n");
			scanf_s("%d", &ocenaAISDLocal);
			printf("Podaj ocene z przedmiotu Narzedzia programistyczne: \n");
			scanf_s("%d", &ocenaNPLocal);
			array->ocenaPE = ocenaPELocal;
			array->ocenaAISD = ocenaAISDLocal;
			array->ocenaNP = ocenaNPLocal;
			array++;													// inkrementacja wska�nika, oznacza odnoszenie si� do kolejnego pola struktury
			printf("\n");
		}
		printf("Podaj egzemplarz do wyswietlenia: ");
		scanf_s("%d", &egzemplarz);
		wyswietl(egzemplarz);
		return 0;
	}
}

void wyswietl(egzemplarz) {
	array = temp;														// do array przypisany zostaje pocz�tkowy adres zaalokowanego bloku pami�ci
	array += egzemplarz - 1;											// egzemplarz - 1, poniewa� pierwszy adres pierwszego elementu struktury to jednocze�nie adres zaalkowanego bloku pami�ci.
	printf("Nazwisko: %s\n", array->nazwisko);
	printf("Data urodzenia: %02d.%02d.%d\n", array->data->dzien, array->data->miesiac, array->data->rok);
	printf("Nr indeku: %d\n", array->indeks);
	printf("Oceny:\n");
	printf("Podstawy elektroniki: %d\n", array->ocenaPE);
	printf("Algorytmy i struktury danych: %d\n", array->ocenaAISD);
	printf("Narzedzia programistyczne: %d\n", array->ocenaNP);
}