#include<iostream>
#include<cstdlib>  // Dla funkcji rand() i srand()
#include<ctime>    // Dla funkcji time()
using namespace std;

int wyszukiwanieWartownik(int tab[], int n, int szukana){
    
    srand(time(NULL));
    
    int i = 0;

    cout << "Automatyczne uzupelnianie tablicy losowymi liczbami..." << endl;
    while (i < n) {
        tab[i] = rand() % 10 + 1;  // Losowa liczba z przedziału 1-10
        i++;
    }
    
    // Dodanie wartownika (-1) na końcu tablicy
    tab[i] = -1;

    cout << "Tablica zawiera: ";
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;

    i = 0;  // Resetowanie zmiennej i

    while (tab[i] != szukana && tab[i] != -1) {
        ++i;  // Zwiększamy indeks, aby przejść do kolejnego elementu
    }

    if (tab[i] == -1) {
        return -1;
    } else {
        return i;  
    }
}

int main()
{
    int *tab;
    int n = 0;
    int szukana = 0;
    
    cout << "Podaj dlugosc tablicy: ";
    cin >> n;
    
    tab = new int[n + 1];  // Alokowanie pamięci dla tablicy z dodatkowym miejscem na wartownika
    
    cout << "Podaj liczbę do wyszukania: ";
    cin >> szukana;
    
    int indeksSzukanej = wyszukiwanieWartownik(tab, n, szukana);
    
    if (indeksSzukanej == -1) {
        cout << "Szukany element nie występuje w tablicy" << endl;
    } else {
        cout << "Liczba " << szukana << " znajduje się na pozycji " << indeksSzukanej + 1 << endl;
    }

    delete[] tab;

    return 0;
}
