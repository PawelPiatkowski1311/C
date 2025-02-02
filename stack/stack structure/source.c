#include <stdio.h>
#include <stdlib.h>            // obs�uga malloc

// Inicjalizacja struktury
struct els {
    int data;                // Zmienna przechowuj�ca dane
    struct els* bottom;        // Wska�nik przechowuj�cy adres kolejnego pola
};

// Inicjalizacja wska�nik�w globalnych
struct els* top = NULL;        // Wska�nik top ze wzgl�du na brak p�l struktury stosu ma przypisan� warto�� NULL
struct els* temp = NULL;

// Deklaracja prototyp�w funkcji
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
    char instrukcja;        // Info od u�ytkownika
    int i;                // Zmienna do przechowywania warto�ci wprowadzonej przez u�ytkownika
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
    temp = (struct els*)malloc(sizeof(struct els));    // Przypisanie wska�nika alokowanego bloku pami�ci typu struktury els o rozmiarze pola struktury do zmiennej globalnej temp
    if (temp) {                                            // Sprawdzenie, czy wska�nika dla warto�ci NULL
        temp->data = i;                                    // Ustawienie warto�ci wprowadzonej przez u�ytkownika do elementu stosu
        temp->bottom = top;                                // W nowo powsta�ym elemencie wska�nik bottom zostaje ustawiony na ostatni elementu stosu
        top = temp;                                        // Wska�nik top wskazuje na nowo dodany element
    }
}

// Usuni�cie elementu stosu
void usun() {
    if (czyPusty() != 0) {
        temp = top;                                    // Adres we wska�niku top zostaje skopiowany do wska�nika temp, oryginalny wska�nik top b�dzie jeszcze potrzebny
        top = top->bottom;                            // Ustawienie top na adres znajduj�cy si� w kolejnym elemencie
        printf("usunieto: %d\n", temp->data);            // Wydrukowanie warto�ci usuni�tego elementu
        free(temp);                                    // Zwolnienie bloku pami�ci wskazywanego przez wska�nik temp
    }
    else {
        printf("stos jest pusty\n");
    }
}

// Wy�wietlenie element�w stosu
void wyswietl() {
    if (czyPusty() != 0) {
        temp = top;                                    // Adres wska�nika top zostaje skopiowany do temp, top musi wskazywa� na ostatni element stosu
        while (temp != NULL) {                        // P�tla powtarza� si� b�dzie dop�ki wszystkie elementy stosu nie zostan� wypisane
            printf("%d ", temp->data);                // Wypisanie warto�ci elementu
            temp = temp->bottom;                    // Ustawienie wska�nika temp na adres kolejnego elementu stosu
        }
        printf("\n");
    }
    else printf("stos jest pusty\n");
}

// Sprawdzenie, czy stos jest pusty
int czyPusty() {                        // Zwr�cone zostanie 0 je�li stos jest pusty, w przeciwnym wypadku 1
    if (top == NULL) return 0;
    else return 1;
}