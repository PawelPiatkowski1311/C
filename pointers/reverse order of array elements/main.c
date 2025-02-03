#include <stdio.h>

int main() {
	int a[5];
	printf("Podaj 5 liczb:\n");
	for (int i = 0; i < 5; i++) {
		printf("%d) ", i+1);
		scanf_s("%d", &a[i]);
	}
	for (int i = 4; i >= 0; i--) {
		printf("%d ", a[i]);
	}
	getchar();
	getchar();
	return 0;
}