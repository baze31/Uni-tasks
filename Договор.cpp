/*
Да се дефинира класа Potpisuvac во која се чуваат информации за:

име (низа од максимум 20 знаци)
презиме (низа од максимум 20 знаци)
ЕМБГ (низа од максимум 14 знаци)
За класата да се дефинира copy конструктор, default конструктор и конструктор со аргументи.

Да се дефинира класа Dogovor, во која се чуваат информации за:

број на договор (int),
категорија на договор (низа од 50 знаци),
поле од 3 потпишувачи на договорот (објекти од класата Potpisuvac)
Во класата да се додаде метод кој ќе проверува дали постојат два исти потпишувачи (имаат ист ЕМБГ).
*/

#include<iostream>
#include<cstring>
using namespace std;
 
class Potpisuvac
{
	private:
    char ime[20];
    char prezime[20];
    char embg[14];
	public:
    Potpisuvac()
    {
    ime[0]='\0';
    prezime[0]='\0';
    embg[0]='\0';
    }
    Potpisuvac(char *i, char*p, char*e)
    {
        strcpy(ime, i);
        strcpy(prezime, p);
        strcpy(embg, e);
    }
    Potpisuvac( Potpisuvac const &p)
    {
        strcpy(ime, p.ime);
        strcpy(prezime, p.prezime);
        strcpy(embg, p.embg);
    }
    char *getEMBG() {return embg;}
};
class Dogovor
{
	private:
    Potpisuvac potpisuvaci[3];
    char kategorija[50];
    int broj;
	public:
    Dogovor() {}
    Dogovor(int broj, char* kat, Potpisuvac * p)
    {
        this->broj=broj;
        strcpy(kategorija, kat);
        potpisuvaci[0] = p[0];
        potpisuvaci[1] = p[1];
        potpisuvaci[2] = p[2];
    }
    bool proverka()
    {
        bool a=strcmp(potpisuvaci[0].getEMBG(), potpisuvaci[1].getEMBG())==0;
        bool b=strcmp(potpisuvaci[0].getEMBG(), potpisuvaci[2].getEMBG())==0;
        bool c=strcmp(potpisuvaci[2].getEMBG(), potpisuvaci[1].getEMBG())==0;
        return a||b||c;
    } 
};
 
int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1; p[1] = p2; p[2] = p3;
        Dogovor d(broj, kategorija, p);
        cout<<"Dogovor "<<i+1<<":"<<endl;
        if(d.proverka() == true)
            cout << "Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
} 	
/*
Sample input
1
0101988450001 Alek Aleksov
0101988450001 Alek Aleksov
0202987440022 Marko Markov
1 Osiguruvanje

Sample output
Dogovor 1:
Postojat potpishuvaci so ist EMBG
*/
