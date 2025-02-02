#include <stdio.h>			
#include <stdlib.h>				// Plik nagłówkowy dla funkcji malloc 

// Struktury danych

typedef struct node				// Struktura "node" łącząca elementy kolejki
{
	int data;					// Zawiera zmienną data typu int;
	struct node* next;			// wskaźnik następnego elementu
	struct node* prev;			// oraz poprzedniego elementu
};

typedef struct Queue			// Struktura "Queue" zawierająca głowę i ogon kolejki
{
	struct node* head;
	struct node* tail;
};

// Prototypy funkcji

void dodaj(struct Queue* q, int item);	// Dodawanie elementu do końca kolejki
void usun(struct Queue* q);		// Usunięcie pierwszego elementu kolejki
void wyswietl(struct Queue* q);	// Wyświetlenie wszystkich elementów kolejki
int czyPusty(struct Queue* q);	// Sprawdzenie, czy kolejka zawiera elementy,
// jeśli tak, zwrócone zostanie 1, w przeciwnym
// wypadku 0

// Funkcje

int main()
{
	struct Queue* q;			// Deklaracja kolejki
	int i = '\0';
	char operacja;
	q = (struct Queue*)malloc(sizeof(struct Queue));	// Przypisanie alokacji bloku pamięci o rozmiarze struktury Queue dla zmiennej q
	q->head = NULL;				// Wskaźniki head
	q->tail = NULL;				// i tail wskazują na NULL
	printf("Podaj jedna z instrukcji: \n");
	printf("d - aby dodac napis z kolejki\n");
	printf("u - aby usunac napis z kolejki\n");
	printf("w - aby wyswietlic zawartosc kolejki\n");
	printf("x - aby zakonczyc\n");
	while (1) {					// Nieskończona pętla
		printf(">> ");
		scanf_s("%c", &operacja, 1);
		switch (operacja) {
		case 'd':
			printf("Podaj wartosc: ");
			scanf_s("%d", &i);
			getchar();
			dodaj(q, i);
			break;
		case 'u':
			usun(q);
			getchar();
			break;
		case 'w':
			wyswietl(q);
			getchar();
			break;
		case 'x':
			return 0;
		default:
			getchar();
			break;
		}
	}
}

void dodaj(struct Queue* q, int i)	// Funkcja utworzy nowy element
{									// i doda go na koniec kolejki
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));	// Przypisanie alokacji bloku pamięci o rozmiarze struktury node dla zmiennej temp
	temp->data = i;					// Do zmiennej data struktury node, przypisywana jest wprowadzona wartość
	temp->next = NULL;				// Następny element przyjmuje wartość NULL
	if (czyPusty(q) != 0)			// Jeśli kolejka jest niepusta,
	{								// element dodany zostanie na koniec kolejki adjusting the last node's next pointer to point
		temp->prev = q->tail;		// Wskaźnik adresu poprzedniego elementu kolejki ustawiony jest, na element znajdujący się w ogonie
		q->tail->next = temp;		// Wskaźnik adresu następnego elementu ustawiony jest na nowo dodany element
	}
	else {							// Jeśli kolejka jest pusta,
		temp->prev = NULL;			// wskaźnik adresu poprzedniego elementu kolejki ustawiony jest na NULL
		q->head = temp;				// do głowy przypisany zostaje nowo dodany element
	}
	q->tail = temp;					// Na koniec do ogonaa przypisany zostaje nowo dodany element
}

void usun(struct Queue* q) {		// Funkcja usuwająca pierwszy element kolejki
	if (czyPusty(q) != 0) {			// Jeśli kolejka jest niepusta
		struct node* temp;
		temp = (struct node*)malloc(sizeof(struct node));
		printf("%d\n", q->head->data);	// Wydrukowana zostaje liczba zapisana w elemencie, który zostaje usunięty
		temp = q->head->next;		// Do zmiennej temp przypisany zostaje wskaźnik adresu następnego elementu kolejki
		free(q->head);				// Element znajdujący się w głowie zostaje usunięty
		if (q->tail->prev != NULL) {
			temp->prev = NULL;
		}	// jeżeli poprzedni element ogona nie jest pusty to ustawiony zostaje wskaźnik prev jako NULL, do następnego elementu na jaki wskazywała głowa
		q->head = temp;				// Głowa przyjmuje następny element kolejki
	}
	else {							// Jeśli kolejka jest pusta
		printf("kolejka jest pusta!\n");
	}
}

void wyswietl(struct Queue* q) {	// Funkcja wyświetlająca wszystkie elementy kolejki
	if (czyPusty(q) != 0) {			// Jeżeli kolejka jest niepusta
		struct node* temp;
		temp = q->tail;				// Do zmiennej pomocniczej przypisany zostaje ogon
		while (temp != NULL) {
			printf("%d ", temp->data);	// Drukuj liczbe zawartą w elemencie kolejki
			temp = temp->prev;		// Do zmiennej pomocniczej przypisz poprzedni element kolejki
		}
		printf("\n");
	}
	else {							// Jeżeli kolejka jest pusta
		printf("kolejka jest pusta!\n");
	}
}

int czyPusty(struct Queue* q)
{
	if (q->head == NULL) return 0;	// Jeżeli kolejka jest pusta zwrócone zostanie 0
	else return 1;					// w przeciwnym wypadku 1
}