#include <iostream>            // obs³uga wejœcia i wyjœcia
#include <vector>              // obs³uga struktur danych biblioteki stl
using namespace std;           // zapis dziêki któremu kompilator nie wymaga przedrostka std

int main() {
    vector <string> wektor;    // zainicjalizowanie wektora

    // inicjalizacja zmiennych
    char instrukcja;           // przechowuje instrukcje
    char instrukcjaM;          // przechowuje podinstrukcje dodawania i ususwania
    string tekst;              // przechowuje tekst, który ma byæ dodany
    string check;              // przechowuje tekst, który ma byæ sprawdzony
    bool checkSet = false;     // zmienna pomocnicza
    int n;                     // przechowuje indeks elementu wektora

    // menu
    cout << "Wybierz instrukcje\n";
    cout << "m - dodawanie i usuwanie elementow,\n";
    cout << "d - pobranie wartosci skrajnych elementow,\n";
    cout << "n - pobieranie n-tego elementu struktury,\n";
    cout << "c - sprawdzenie czy element nalezy do struktury,\n";
    cout << "s - pobranie wielkosci struktury,\n";
    cout << "e - sprawdzenie, czy wektor jest niepusty\n";

    // operacje
    while (true) {                                                                           // program dzia³a w nieskoñczonoœæ
        cout << "\npodaj operacje: ";
        cin >> instrukcja;

        // instrukcje dla konkretnego wyboru
        switch (instrukcja) {

            // dodawanie lub usuwanie
        case 'm':
            cout << "\nwybierz operacje:\n";
            cout << "d - dodawanie\n";
            cout << "u - usuwanie\n";
            cout << "\npodaj instrukcje: ";
                cin >> instrukcjaM;                                                          // pobranie podinstrukcji
                cout << "\n";
                switch (instrukcjaM) {
                case 'd':
                    cout << "podaj tekst, ktory ma zostac dodany do struktury: ";
                    cin >> tekst;
                    wektor.push_back(tekst);                                                 // dodanie elementu na sam koniec struktury
                    cout << "\ndodano!\n";
                    break;
                case 'u':
                    if (!wektor.empty()) {                                                   // obs³uga b³êdu, jeœli wektor jest pusty, wyœwietlony zostanie komunikat
                        wektor.pop_back();                                                   // usuñ ostatni element struktury
                        cout << "\nusunieto!\n";
                    }
                    else cout << "\nstruktura jest pusta\n";
                default:
                    cout << "\nnieznana operacja\n";
                    break;
            }
            break;

            // pobranie skrajnej wartoœci
        case 'd':
            if (!wektor.empty()) {                                                            // obs³uga b³êdu
                cout << "\nwartosci skrajne struktury: " << wektor.front() << ", " << wektor.back() << "\n";
            }
            else cout << "\nstruktura jest pusta\n";
            break;

            // pobranie n-tej wartoœci
        case 'n':
            cout << "Podaj n: ";
            cin >> n;
            if (n <= wektor.size()) cout << n << " element struktury jest rowny: " << wektor[n-1];    // obs³uga b³êdu, jeœli podany indeks jest poza rozmiarem struktury to wyœwietlony zostanie komunikat
            else cout << "struktura nie zawiera tylu elementow";
            break;

            // sprawdzenie, czy element nale¿y do struktury
        case 'c':
            cout << "\npodaj ciag do sprawdzenia\n";
            cin >> check;
            for (int i = 0; i < wektor.size(); i++) {                                         // pêtla wykonuje siê o rozmiar wektora
                if (check == wektor[i]) {                                                     // jeœli tekst zostanie odnaleziony, to zmienna pomocnicza zostanie ustawiona na true
                    checkSet = true;                                                          // wartoœæ true deklaruje, ¿e w wektorze jest przynajmniej jeden element pasuj¹cy do szukanego ci¹gu
                    break;                                                                    // funkcja, przerywa pêtle
                }
            }
            if (checkSet == true) cout << "\nelement" << check << "nalezy do struktury\n";    // jeœli w wektorze znajduje siê szukany ci¹g znaków wyœwietlony zostanie ten komunikat
            else cout << "\nelement" << check << "nie zostal znaleziony w strukturze\n";      // jeœli szukany ci¹g nie zostanie znaleziony wyœwietlony zostanie ten komunikat
            break;

            // pobranie rozmiaru struktury
        case 's':
            cout << "\nstruktura ma rozmiar: " << wektor.size() << "\n";
            break;

            // sprawdzenie, czy struktura jest pusta
        case 'e':
            if (wektor.empty()) cout << "\nstruktura jest pusta\n";
            else cout << "\nstruktura jest niepusta\n";
            break;

            // obs³uga b³êdu
        default:
            cout << "\nnieznana operacja\n";
            break;
        }
    }
    return 0;
}