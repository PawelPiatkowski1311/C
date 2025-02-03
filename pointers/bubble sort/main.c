#include <stdio.h>
#define CIAG {5,4,6,1,2,4,9,7,0,3}

int main() {
	int temp;
	int tab[10] = CIAG;
	int* ws;
	for (int i = 0; i < 10; i++) {
		ws = &tab[0];
		for (int j = 0; j < 10 - i - 1; j++, ws++) {
			if (*ws > *(ws + 1)) {
				temp = *ws;
				*ws = *(ws + 1);
				*(ws + 1) = temp;
			}
		}
	}
	for (int i = 0; i < 10; i++, ws++) {
		printf("%d ", *ws);
	}
	getchar();
	getchar();
	return 0;
}