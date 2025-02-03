#include <stdio.h>
#include <stdlib.h>     // obs³uga malloc
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

// struktura przechowuj¹ca date
struct tm
{
	int dzien;
	int miesiac;
	int rok;
};

// inicjalizacja wskaŸników 
struct studenci* array;     // wskaŸnik g³ówny, s³u¿y do wskazywania adresów ka¿dej struktury
struct studenci* temp;      // przechowuje adres pierwszego elementu struktury, aby bez problemu funkcja wyœwietl mog³a siê odnosiæ do elementów
void wyswietl(egzemplarz);

int main() {
	int n;

	// zmienne Local s³u¿yæ bêd¹ do przechowywania danych na czas ich wprowadzania
	char nazwiskoLocal[MAX];
	int dzienLocal;
	int miesiacLocal;
	int rokLocal;
	int ocenaPELocal;
	int ocenaAISDLocal;
	int ocenaNPLocal;

	int egzemplarz;			// zmienna przechowywaæ bêdzie nr elementu struktury, który bêdzie mia³ byæ wyœwietlony
	printf("Podaj n: ");
	scanf_s("%d", &n);
	array = (struct studenci*)malloc(n * sizeof(struct studenci));		// przypisanie do wskaŸnika array zaalokowanego bloku pamiêci
	temp = array;														// ten sam adres przypisany zostaje równie¿ do zmiennej pomocniczej temp, dziêki czemu bêdzie mo¿na bez problemu odnosiæ sie do ka¿dego elementu
	if (array) {														// program wykonuje siê pod warunkiem, jeœli array nie wskazuje na NULL, co oznacza brak dostêpnej pamiêci
		for (int i = 0; i < n; i++) {
			printf("Podaj nazwisko studenta: ");
			getchar();
			fgets(nazwiskoLocal, sizeof(nazwiskoLocal), stdin);
			nazwiskoLocal[strcspn(nazwiskoLocal, "\n")] = 0;			// usuniêty zostaje znak nowej linii, który dodaje funkcja fgets
			strcpy_s(array->nazwisko, MAX, nazwiskoLocal);				// przypisanie ³añcucha znaków do zmiennej nazwisko struktury studenci
			printf("Podaj date urodzenia:\n");
			printf("Dzien: ");
			scanf_s("%d", &dzienLocal);
			printf("Miesiac: ");
			scanf_s("%d", &miesiacLocal);
			printf("Rok: ");
			scanf_s("%d", &rokLocal);
			array->data = (struct tm*)malloc(sizeof(struct tm));		// program musi dla ka¿dego studenta osobno zaalokowaæ blok pamiêci dla struktury obs³uguj¹cej date
			if (array->data) {											// jeœli wskaŸnik nie wskazuje na NULL program wykonuje siê dalej
				array->data->dzien = dzienLocal;
				array->data->miesiac = miesiacLocal;
				array->data->rok = rokLocal;
			}
			array->indeks = i + 1;										// do i zostaje dodane 1, poniewa¿ pêtla odlicza zmienn¹ i od 0, a program odliczaæ indeksy bêdzie od liczby 1
			printf("Podaj ocene z przedmiotu Podstawy elektroniki: \n");
			scanf_s("%d", &ocenaPELocal);
			printf("Podaj ocene z przedmiotu Algorytmy i struktury danych: \n");
			scanf_s("%d", &ocenaAISDLocal);
			printf("Podaj ocene z przedmiotu Narzedzia programistyczne: \n");
			scanf_s("%d", &ocenaNPLocal);
			array->ocenaPE = ocenaPELocal;
			array->ocenaAISD = ocenaAISDLocal;
			array->ocenaNP = ocenaNPLocal;
			array++;													// inkrementacja wskaŸnika, oznacza odnoszenie siê do kolejnego pola struktury
			printf("\n");
		}
		printf("Podaj egzemplarz do wyswietlenia: ");
		scanf_s("%d", &egzemplarz);
		wyswietl(egzemplarz);
		return 0;
	}
}

void wyswietl(egzemplarz) {
	array = temp;														// do array przypisany zostaje pocz¹tkowy adres zaalokowanego bloku pamiêci
	array += egzemplarz - 1;											// egzemplarz - 1, poniewa¿ pierwszy adres pierwszego elementu struktury to jednoczeœnie adres zaalkowanego bloku pamiêci.
	printf("Nazwisko: %s\n", array->nazwisko);
	printf("Data urodzenia: %02d.%02d.%d\n", array->data->dzien, array->data->miesiac, array->data->rok);
	printf("Nr indeku: %d\n", array->indeks);
	printf("Oceny:\n");
	printf("Podstawy elektroniki: %d\n", array->ocenaPE);
	printf("Algorytmy i struktury danych: %d\n", array->ocenaAISD);
	printf("Narzedzia programistyczne: %d\n", array->ocenaNP);
}