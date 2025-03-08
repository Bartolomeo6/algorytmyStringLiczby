#include <iostream>
#include <stack>
#include <string>

using namespace std;

int dzialanie(int a, int b, char oper){
    
    switch(oper){
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
    }
    
    cout<<"Niepoprawny operator!"<<endl;
    return 0;
}

bool czy_cyfra(char znak){
    return znak >= '0' && znak <= '9';
}

bool czy_oper(char znak){
    return znak == '+' || znak == '-' || znak == '*' || znak == '/';
}

int str_to_int(string tekst, int &pozycja){
    int liczba = 0;
    while(pozycja < tekst.size() && czy_cyfra(tekst[pozycja])){
        liczba = liczba*10 + tekst[pozycja] - '0';
        ++pozycja;
    }
    --pozycja;
    
    return liczba;
}

int main(){
    string odwNotPol = "";
    
    cout<<"Wprowadz wyrazenie w ONP: ";
    getline(cin, odwNotPol);
    
    stack<int> stos;
    int a,b;
    
    for(int i = 0; i<odwNotPol.size(); i++){
        if(czy_cyfra(odwNotPol[i])){
            stos.push((str_to_int(odwNotPol, i)));
        }
        else{
            if(czy_oper(odwNotPol[i])){
                if(stos.size() < 2){
                    cout<<"Źle my pi";
                    return 0;
                }
                
                a = stos.top();
                stos.pop();
                
                b = stos.top();
                stos.pop();
                
                stos.push(dzialanie(b,a, odwNotPol[i]));
            }
        }
        
    }
    if(stos.size() != 1){
        cout<<"Aj karamba, cos not gut";
    }
    
    cout<<"Wynik dzialania ("<<odwNotPol<<") wynosi: "<<stos.top()<<endl;
    
    return 0;
}
