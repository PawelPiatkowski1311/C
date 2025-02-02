#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c;
    printf("Podaj a: ");
    scanf_s("%d", &a);
    printf("Podaj b: ");
    scanf_s("%d", &b);
    printf("Podaj c: ");
    scanf_s("%d", &c);
    if (a < b + c && b < a + c && c < a + b) {
        int obwod = (a + b + c);
        double p = obwod / 2; // Po³owa obwodu
        double pole = sqrt(p * (p - a) * (p - b) * (p - c)); // Wzór Herona
        printf("Obwod wynosi: %d\nPole wynosi: %g", obwod, pole); // %d dla zmiennej ca³kowitej, %g dla zmiennej zmiennoprzecinkowej
    }
    else {
        printf("Z podanych wymiarow nie da sie stowrzyc trojkata");
    }
    getchar();
    getchar();
    return 0;
}