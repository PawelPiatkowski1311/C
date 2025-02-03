#include <stdio.h>
#include <string.h>
#define SIZE 255	

void sklej(char* wskA, char* wskB);

char test;

int main() {
	char a[SIZE];
	char b[SIZE];
	printf("Lancuch A: ");
	fgets(a, sizeof(a), stdin);
	char* wskA = a;
	printf("Lancuch B: ");
	fgets(b, sizeof(b), stdin);
	char* wskB = b;
	sklej(wskA, wskB);
	printf("Polaczone lancuchy: ");
	puts(a);
	getchar();
	getchar();
	return 0;
}

void sklej(char* wskA, char* wskB) {
	int dlugoscA = strlen(wskA) - 1;	// strlen() - 1, poniewa¿ d³ugoœæ
	int dlugoscB = strlen(wskB) - 1;	// ma nieobejmowaæ bitu zakoñczenia ³añcucha
	wskA += dlugoscA;					// ustaw wskaŸnik na koñcowy bit ³añcucha
	for (int i = 0; i < dlugoscB; i++) {
		*wskA = *wskB;
		wskA++;
		wskB++;
	}
	*wskA = '\0'; // bit koñcowy oznaczaj¹cy koniec ³añcucha
}