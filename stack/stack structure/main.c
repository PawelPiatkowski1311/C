#include <stdio.h>
#include <stdlib.h>            // obs³uga malloc

// Inicjalizacja struktury
struct els {
    int data;                // Zmienna przechowuj¹ca dane
    struct els* bottom;        // WskaŸnik przechowuj¹cy adres kolejnego pola
};

// Inicjalizacja wskaŸników globalnych
struct els* top = NULL;        // WskaŸnik top ze wzglêdu na brak pól struktury stosu ma przypisan¹ wartoœæ NULL
struct els* temp = NULL;

// Deklaracja prototypów funkcji
void dodaj(int i);
void usun();
void wyswietl();
int czyPusty();

int main() {
    // Komunikacja
    printf("Podaj jedna z instrukcji:\n");
    printf("d - aby dodac napis do stosu\n");
    printf("u - aby usunac napis ze stosu\n");
    printf("w - aby wyswietlic zawartosc stosu\n");
    printf("x - aby zakonczyc\n");
    char instrukcja;        // Info od u¿ytkownika
    int i;                // Zmienna do przechowywania wartoœci wprowadzonej przez u¿ytkownika
    while (1) {
        scanf_s("%c", &instrukcja, 1);
        switch (instrukcja) {
        case 'd':            //dodawanie
            printf("Podaj liczbe: ");
            scanf_s("%d", &i);
            dodaj(i);
            printf("dodano!\n");
            break;
        case 'u':            //usuwanie
            usun();
            break;
        case 'w':            //wyswietlanie
            wyswietl();
            break;
        case 'x':            //wyjscie
            return 0;
            break;
        default:            //nieznana instrukcja
            break;
        }
    }
}

// Dodanie elementu stosu
void dodaj(int i) {
    temp = (struct els*)malloc(sizeof(struct els));    // Przypisanie wskaŸnika alokowanego bloku pamiêci typu struktury els o rozmiarze pola struktury do zmiennej globalnej temp
    if (temp) {                                            // Sprawdzenie, czy wskaŸnika dla wartoœci NULL
        temp->data = i;                                    // Ustawienie wartoœci wprowadzonej przez u¿ytkownika do elementu stosu
        temp->bottom = top;                                // W nowo powsta³ym elemencie wskaŸnik bottom zostaje ustawiony na ostatni elementu stosu
        top = temp;                                        // WskaŸnik top wskazuje na nowo dodany element
    }
}

// Usuniêcie elementu stosu
void usun() {
    if (czyPusty() != 0) {
        temp = top;                                    // Adres we wskaŸniku top zostaje skopiowany do wskaŸnika temp, oryginalny wskaŸnik top bêdzie jeszcze potrzebny
        top = top->bottom;                            // Ustawienie top na adres znajduj¹cy siê w kolejnym elemencie
        printf("usunieto: %d\n", temp->data);            // Wydrukowanie wartoœci usuniêtego elementu
        free(temp);                                    // Zwolnienie bloku pamiêci wskazywanego przez wskaŸnik temp
    }
    else {
        printf("stos jest pusty\n");
    }
}

// Wyœwietlenie elementów stosu
void wyswietl() {
    if (czyPusty() != 0) {
        temp = top;                                    // Adres wskaŸnika top zostaje skopiowany do temp, top musi wskazywaæ na ostatni element stosu
        while (temp != NULL) {                        // Pêtla powtarzaæ siê bêdzie dopóki wszystkie elementy stosu nie zostan¹ wypisane
            printf("%d ", temp->data);                // Wypisanie wartoœci elementu
            temp = temp->bottom;                    // Ustawienie wskaŸnika temp na adres kolejnego elementu stosu
        }
        printf("\n");
    }
    else printf("stos jest pusty\n");
}

// Sprawdzenie, czy stos jest pusty
int czyPusty() {                        // Zwrócone zostanie 0 jeœli stos jest pusty, w przeciwnym wypadku 1
    if (top == NULL) return 0;
    else return 1;
}