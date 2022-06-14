/*
Во оваа задача е потребно да уредите даден дом со маси. Креирајте класа Masa со следниве атрибути:

должина (целобројна вредност)
ширина (целобројна вредност)
конструктор со и без параметри и метода pecati().

Креирајте класа Soba која содржи:

маса (објект од класата Маса)
должина на собата (целобројна вредност)
ширина на собата (целобројна вредност)
конструктор со и без параметри и метода pecati() во која се повикува и pecati() за објектот Masa.

Креирајте класа Kukja со атрибути:

соба (објект од класата Soba)
адреса (низа од 50 знаци), и соодветни методи.
конструктор со и без параметри, деструктор и метода pecati() во која се повикува и pecati() за објектот Soba.
*/
#include <iostream>
#include <cstring>

using namespace std;
class Masa
    {private:
    int dolzina;
    int sirina;   
    public:
    Masa() {}
    Masa(int s, int d)
    {sirina=s; dolzina=d;}
    void pecati()
        {cout << "Masa: " << sirina << " " << dolzina << " "<< endl;}
    };
 class Soba
    {private:
    Masa masa;
    int dolzinaSoba;
    int sirinaSoba;
    public:
    Soba() {}
    Soba(int s, int d, Masa& m)
    {masa=m;
        dolzinaSoba=d;
        sirinaSoba=s;}
    void pecati()
        {cout << "Soba: " << sirinaSoba << " " << dolzinaSoba<< " ";
        masa.pecati();}
    };
class Kukja
    {private:
    char adresa[50];
    Soba soba;
    public:
    Kukja() {}
    Kukja(Soba& s, char* a)
    {   soba=s;
        strcpy(adresa, a);}
    void pecati()
        {cout << "Adresa: " << adresa<< " ";
        	soba.pecati();}
};
 

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int masaSirina,masaDolzina;
        cin>>masaSirina;
        cin>>masaDolzina;
    	Masa m(masaSirina,masaDolzina);
    	int sobaSirina,sobaDolzina;
        cin>>sobaSirina;
        cin>>sobaDolzina;
    	Soba s(sobaSirina,sobaDolzina,m);
    	char adresa[30];
        cin>>adresa;
    	Kukja k(s,adresa);
    	k.pecati();
	}
    
    return 0;
}
/*
Sample input
3
2 4 10 20 Goce_Delcev_20
1 1 12 43 Pitu_Guli_2
2 4 10 20 Partizanski_Odredi_87_b

Sample output
Adresa: Goce_Delcev_20 Soba: 10 20 Masa: 2 4 
Adresa: Pitu_Guli_2 Soba: 12 43 Masa: 1 1 
Adresa: Partizanski_Odredi_87_b Soba: 10 20 Masa: 2 4 
*/
