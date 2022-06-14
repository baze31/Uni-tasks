/*
Креирајте класа Rabotnik која во себе содржи:

ime (низа од максимум 30 знаци)
prezime (низа од максимум 30 знаци)
plata (целобројна вредност)
За оваа класа да се креираат default конструктор и конструктор со аргументи. Да се имплементираат и следните методи:

getPlata() која ја враќа платата на работникот
pecati() која ги печати името, презимето и платата.
Креирајте класа Fabrika во која има:

rabotnik [100] (низа од вработени)
brojVraboteni (целобројна вредност)
Во класта имплементирајте ги следните методи:

pecatiVraboteni() ги пречати сите вработени
pecatiSoPlata(int plata) ги печати сите вработени со плата поголема или еднаква на дадената во аргументот (int plata).
Во главната функција се внесуваат податоци за n вработени. Притоа прво се несува n, па податоците за сите n вработени. Во последниот ред се чита минималната плата.

На излез да се прикажат прво сите вработени, а потоа само оние со поголема плата од минималната. Треба да се корисатат методите pecatiVraboteni и pecatiSoPlata!
*/
#include <iostream>
#include <cstring>
using namespace std;
class Rabotnik
    {
    private:
    char ime[30];
    char prezime[30];
    int plata;
    
    public:
    Rabotnik() {}
    Rabotnik(char* i, char* p, int s)
        {
        strcpy(ime,i);
        strcpy(prezime,p);
        plata = s;
        }
    
    Rabotnik(const Rabotnik& r) 
        {
        strcpy(ime,r.ime);
        strcpy(prezime,r.prezime);
        plata = r.plata;
        }
    
    void print() 
        {
        cout << ime << " " << prezime << " " << plata << endl;
        }
    
    int getPlata()
        {
        return plata;
        }
    char* getName() 
        {
        return ime;
        }
    char* getSurname()
        {
        return prezime;
        }
    void setName(char *i) 
        {
        strcpy(ime,i);
        }
    void setSurname(char *p)
        {
        strcpy(prezime,p);
        }
    void setSalary(int pl)
        {
        plata = pl;
        }
};

class Fabrika {
    private:
    Rabotnik rabotnici[100];
    int brRab;
    
    public:
    Fabrika() {
        brRab = 0;
        }
    void dodajRabotnik(Rabotnik& r) {
        rabotnici[brRab++] = r;
        }
    void pecatiVraboteni() {
        for (int i = 0; i < brRab; i++)
            cout << rabotnici[i].getName() << " " << rabotnici[i].getSurname() << " " << rabotnici[i].getPlata() << endl;
}
    void pecatiSoPlata(int plata) {
        for (int i = 0; i < brRab; i++) 
        {if (rabotnici[i].getPlata() >= plata)
                rabotnici[i].print();
            }
        }
};

int main() {
    int n;
    Fabrika f;
    cin >> n;
    int s;
    for (int j = 0; j < n; j++) 
    {
        char i[30];
        char p[30];
        cin >> i >> p >> s;
        Rabotnik r(i, p, s);
        f.dodajRabotnik(r);
        }
    cout << "Site vraboteni:" << endl;
    f.pecatiVraboteni();
    cin >> n;
    cout << "Vraboteni so plata povisoka od " << n << " :" << endl;
    f.pecatiSoPlata(n);
    return 0;
    }
/*
Sample input
3
Mile Palkovski 20000
Kalina Saleska 40720
Aco Noveski 66320
30000

Sample output
Site vraboteni:
Mile Palkovski 20000
Kalina Saleska 40720
Aco Noveski 66320
Vraboteni so plata povisoka od 30000 :
Kalina Saleska 40720
Aco Noveski 66320
*/
