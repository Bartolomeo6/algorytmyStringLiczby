#include <iostream>

using namespace std;

// Funkcja do wykonywania operacji matematycznych
int dzialanie(int a, int b, char oper) {
    if (oper == '+') return a + b;
    if (oper == '-') return a - b;
    if (oper == '*') return a * b;
    if (oper == '/') return a / b;
    return 0; // Błędny operator
}

// Funkcja do obliczania wyniku z notacji postfiksowej
int obliczONP(char postfiks[]) {
    int stos[100];  // Stos do obliczania wyniku
    int top = -1;   // Wskaźnik na wierzchołek stosu
    int a, b, wynik;
    int i = 0;

    // Przechodzimy przez każde wyrażenie w postfiksie
    while (postfiks[i] != '\0') {
        char c = postfiks[i];

        if (c >= '0' && c <= '9') {  // Sprawdzamy, czy to cyfra
            int liczba = 0;
            while (postfiks[i] >= '0' && postfiks[i] <= '9') {  // Zbieramy pełną liczbę
                liczba = liczba * 10 + (postfiks[i] - '0');
                i++;
            }
            stos[++top] = liczba;  // Dodajemy liczbę na stos
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {  // Jeśli operator
            b = stos[top--];  // Zdejmujemy drugi operand
            a = stos[top--];  // Zdejmujemy pierwszy operand
            wynik = dzialanie(a, b, c);  // Wykonujemy operację
            stos[++top] = wynik;  // Dodajemy wynik na stos
            i++;  // Przechodzimy do następnego znaku
        } else {
            i++;  // Zwykle przechodzimy do następnego znaku
        }
    }

    return stos[top];  // Wynik znajduje się na szczycie stosu
}

// Funkcja konwertująca infiks na ONP
void infiksNaONP(string infiks, char wynik[]) {
    int k = 0;  // Indeks w tablicy wynik
    int stos[100];  // Stos operatorów
    int top = -1;  // Indeks na wierzchołku stosu
    string liczba = "";  // Zmienna do przechowywania liczby

    // Przechodzimy przez każde wyrażenie w infiksie
    for (int i = 0; i < infiks.length(); i++) {
        char c = infiks[i];

        if (c >= '0' && c <= '9') {  // Zbieramy liczby
            liczba += c;
        } else {
            // Jeśli znalazła się liczba, dodajemy ją do wyniku
            if (liczba != "") {
                for (int j = 0; j < liczba.length(); j++) {
                    wynik[k++] = liczba[j];
                }
                wynik[k++] = ' ';  // Dodajemy spację między liczbami
                liczba = "";  // Resetujemy zmienną liczba
            }

            // Jeśli nawias otwierający, dodajemy na stos
            if (c == '(') {
                stos[++top] = c;
            } else if (c == ')') {
                // Zdejmujemy z stosu, aż do napotkania nawiasu otwierającego
                while (top != -1 && stos[top] != '(') {
                    wynik[k++] = stos[top--];
                    wynik[k++] = ' ';
                }
                top--;  // Usuwamy nawias otwierający
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                // Sprawdzamy operator
                while (top != -1 && (stos[top] == '*' || stos[top] == '/' ||
                    (stos[top] == '+' || stos[top] == '-') && (c == '+' || c == '-'))) {
                    wynik[k++] = stos[top--];
                    wynik[k++] = ' ';
                }
                stos[++top] = c;  // Operator na stos
            }
        }
    }

    // Zapisujemy ostatnią liczbę, jeśli jakaś jest
    if (liczba != "") {
        for (int j = 0; j < liczba.length(); j++) {
            wynik[k++] = liczba[j];
        }
        wynik[k++] = ' ';
        liczba = "";
    }

    // Zdejmujemy pozostałe operatory ze stosu
    while (top != -1) {
        wynik[k++] = stos[top--];
        wynik[k++] = ' ';
    }

    wynik[k] = '\0';  // Kończymy wynik null-terminatorem
}

int main() {
    string infiks;
    char wynik[100];  // Tablica do przechowywania wyniku w ONP

    // Wczytanie wyrażenia infiksowego
    cout << "Podaj wyrazenie w notacji infiksowej (np. 3+2*5): ";
    cin >> infiks;

    // Konwersja na ONP
    infiksNaONP(infiks, wynik);
    cout << "Notacja postfiksowa (ONP): ";
    cout << wynik << endl;

    // Obliczanie wyniku w notacji postfiksowej
    int wynikOblicz = obliczONP(wynik);
    cout << "Wynik wyrazenia w notacji postfiksowej: " << wynikOblicz << endl;

    return 0;
}
