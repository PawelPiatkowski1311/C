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
	int dlugoscA = strlen(wskA) - 1;	// strlen() - 1, poniewa� d�ugo��
	int dlugoscB = strlen(wskB) - 1;	// ma nieobejmowa� bitu zako�czenia �a�cucha
	wskA += dlugoscA;					// ustaw wska�nik na ko�cowy bit �a�cucha
	for (int i = 0; i < dlugoscB; i++) {
		*wskA = *wskB;
		wskA++;
		wskB++;
	}
	*wskA = '\0'; // bit ko�cowy oznaczaj�cy koniec �a�cucha
}