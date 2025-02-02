#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define M 7															// zdefiniowana liczba kraw�dzi
#define N 6															// zdefiniowana liczba wierzcho�k�w

struct edge {														// struktura kraw�dzi
	struct tabela* p1;
	struct tabela* p2;												// p1 oraz p2 zawieraj� adresy do wierzcho�k�w tabeli
	int weight;
};

struct tabela {														// struktura tabeli koszt�w poprzednik�w
	char p;
	int cost;
	char prev;
	bool seen;
};

char tab[N] = {'a','b','c','d','e','f'};							// zaindeksowane nazwy wierzcho�k�w

struct edge* inicjacjalizacja_grafu(struct tabela*);				// funkcja inicjalizuje graf, definiuj�c jego kraw�dzie
bool czy_przejrzane(struct tabela* wierzcholek);					// funkcja zwraca true, je�li wierzcho�ek nie zosta� przejrzany

int main() {
	int temp;
	int temp2;
	int u;
	struct tabela* wierzcholek;
	struct edge* krawedz;
	wierzcholek = (struct tabela*)malloc(N * sizeof(struct tabela));

	// krok 1 / 2
	for (int i = 0; i < N; i++) {									// ustawienie wszystkich parametr�w pocz�tkowych tabeli zgodnie z algorytmem djisktry
		wierzcholek[i].p = tab[i];
		wierzcholek[i].cost = INT_MAX;
		wierzcholek[i].prev = '0';
		wierzcholek[i].seen = false;
	}
	krawedz = inicjacjalizacja_grafu(wierzcholek);					// edgeLocal przyjmuje wska�nik do grafu

	// krok 3
	wierzcholek[0].cost = 0;

	// krok 4
	while (czy_przejrzane(wierzcholek)) {

		// krok 4.1
		for (u = 0; wierzcholek[u].seen == true; u++);				// ustawia u na nieprzejrzany element
		temp = wierzcholek[u].cost;									// do zmiennej tymczasowej przypisany zostaje koszt pierwszy od lewej
		for (int i = u; i < N - u; i++) {							// p�tla ma na celu sprawdzenie, kt�ry indeks zawiera najmniejszy koszt
			if (temp > wierzcholek[i].cost) {
				temp = wierzcholek[i].cost;
				u = i;
			}
		}

		// krok 4.2
		for (int i = 0; i < M; i++) {								// p�tla wyszukuje u wierzcho�ek w strukturze kraw�dzi
			if (krawedz[i].p1->p == tab[u]) {

				// krok 4.2.1
				if (krawedz[i].weight + wierzcholek[u].cost < krawedz[i].p2->cost) {	// je�li koszt przej�cia z u -> v + cost[u] jest mniejszy ni� cost[v]
					krawedz[i].p2->cost = krawedz[i].weight + wierzcholek[u].cost;
					krawedz[i].p2->prev = wierzcholek[u].p;
				}
			}
		}

		// krok 4.3
		wierzcholek[u].seen = true;										// seen[u] zostaje ustawione jako przejrzane
	}
	printf("Symbol:\t\t");
	for (int i = 0; i < N; i++) printf("%c   ", wierzcholek[i].p);
	printf("\nKoszt:\t\t");
	for (int i = 0; i < N; i++) printf("%d   ", wierzcholek[i].cost);
	printf("\nPoprzednik:\t");
	for (int i = 0; i < N; i++) printf("%c   ", wierzcholek[i].prev);
}

struct edge* inicjacjalizacja_grafu(struct tabela* wierzcholek) {
	struct edge krawedz[M] = { {
		&wierzcholek[0].p,
		&wierzcholek[1].p,
		4,
	},
	{
		&wierzcholek[0].p,
		&wierzcholek[2].p,
		5,
	},
	{
		&wierzcholek[1].p,
		&wierzcholek[3].p,
		2,
	},
	{
		&wierzcholek[1].p,
		&wierzcholek[4].p,
		1,
	},
	{
		&wierzcholek[2].p,
		&wierzcholek[3].p,
		3,
	},
	{
		&wierzcholek[3].p,
		&wierzcholek[5].p,
		3,
	},
	{
		&wierzcholek[4].p,
		&wierzcholek[5].p,
		5,
	}};
	return krawedz;
}

bool czy_przejrzane(struct tabela* tablica) {
	for (int i = 0; i < N; i++) {									// je�li znaleziony zostanie wierzcho�ek nieprzejrzany to zwr�� true
		if (tablica[i].seen == false) return true;
	}
	return false;
}