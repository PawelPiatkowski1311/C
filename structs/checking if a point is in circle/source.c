#define _USE_MATH_DEFINES	// sta³a PI
#define MAX 255
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct kolo {
	int numer;
	char nazwa[MAX];
	int a;
	int b;
	int r1;
};

int main() {
	int a;
	int b;
	double pole;
	bool gate = false;
	struct kolo koloElement[3] = {{
		1,
		"Kolo im. Pawla Piatkowskiego",
		5,
		45,
		12
	},
	{
		2,
		"Kolo graniaste",
		-10,
		15,
		7
	},
	{
		3,
		"Najgorsze kolo",
		30,
		12,
		24
	}};
	printf("Podaj wspolrzedne:\n");
	printf("A: ");
	scanf_s("%d", &a);
	printf("B: ");
	scanf_s("%d", &b);
	for (int i = 0; i < 3; i++) {
		if (sqrt(pow((koloElement[i].a - a), 2) + pow((koloElement[i].b - b), 2)) <= koloElement[i].r1) {
			pole = M_PI * pow(koloElement[i].r1, 2);
			printf("Nazwa: %s, Pole: %g\n", koloElement[i].nazwa, pole);
			gate = true;
		}
	}
	if (gate == false) printf("Punkt lezy poza jakimkolwiek kolem");
}