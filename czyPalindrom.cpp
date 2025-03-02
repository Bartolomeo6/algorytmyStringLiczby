#include <iostream>
#include <string>

using namespace std;

bool czy_palindrom(string tekst){
    int i = 0;
    int j = tekst.length()-1;
    
    while(i<j){
        if(tekst[i] != tekst[j]){
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int main()
{
    string potencjalPali;
	cout<<"Podaj wyraz: ";
	cin>>potencjalPali;
	
	if(czy_palindrom(potencjalPali))
		cout<<"Wyraz "<<potencjalPali<<" jest palindromem"<<endl;
	else
		cout<<"Wyraz "<<potencjalPali<<" nie jest palindromem"<<endl;

    return 0;
}
