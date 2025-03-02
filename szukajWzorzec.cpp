#include<iostream>
#include<string>
using namespace std;

int wyszukajWzorzec(string wzor, string tekst) {
    int licznik = 0;  // Zmienna do liczenia wszystkich wystąpień wzorca
    int pozycjaPierwszego = -1;  // Zmienna do przechowywania pierwszej pozycji wzorca

    // Iteracja przez tekst, sprawdzanie każdego fragmentu
    for(int i = 0; i <= tekst.size() - wzor.size(); i++) {
        bool dopasowanie = true;  // Flaga, która sprawdza, czy znaleźliśmy wzorzec

        // Sprawdzamy, czy fragment tekstu pasuje do wzorca
        for(int j = 0; j < wzor.size(); j++) {
            if(wzor[j] != tekst[i + j]) {
                dopasowanie = false;
                break;  // Jeśli nie pasuje, przerwij porównanie
            }
        }

        // Jeśli znaleźliśmy dopasowanie
        if(dopasowanie) {
            licznik++;  // Inkrementujemy licznik wystąpień wzorca

            if(pozycjaPierwszego == -1) {
                pozycjaPierwszego = i + 1;  // Zapisujemy pozycję pierwszego wystąpienia (liczymy od 1)
            }
        }
    }

    if (licznik > 0) {
        cout << "Pierwsza pozycja wzorca to: " << pozycjaPierwszego << endl;
        cout << "Liczba wystąpień wzorca: " << licznik << endl;
    } else {
        cout << "Wzorzec nie występuje w tekście." << endl;
    }

    return licznik;  // Zwracamy liczbę wystąpień wzorca
}

int main() {
    string tekst, wzorzec;

    cout << "Podaj tekst: ";
    getline(cin, tekst);  // Używamy getline, aby wczytać cały tekst, w tym spacje

    cout << "Podaj wzorzec do wyszukania: ";
    cin >> wzorzec;

    wyszukajWzorzec(wzorzec, tekst);  // Wywołanie funkcji

    return 0;
}
