#include<iostream>
#include<string>

using namespace std;

int wyszukajWzorzec(string wzor, string tekst){
    
    for(int i = 0; i<=tekst.size() - wzor.size(); i++){
        
        int c = 0;
        for(int j = 0; j<wzor.size(); j++){
            
            if(wzor[j] != tekst[i+c]){
                break;
            }
            if(j == wzor.size()-1){
                return i+1;
            }
            
            ++c;
        }
    }
    return -1;
}

int main()
{
    string tekst, wzorzec;
    
    cout<<"Podaj tekst: ";
    cin>>tekst;
    
    cout<<"Teraz wzorzec do wyszukania w tym tekscie: ";
    cin>>wzorzec;
    
    int pozycja = wyszukajWzorzec(wzorzec, tekst);
    
    if(pozycja == -1){
        cout<<"Brak wzorca w tekscie"<<endl;
    }
    else{
        cout<<"Wzorzec zaczyna sie na pozycji: "<<pozycja<<endl;
    }
    return 0;
}
