/*
Да се креира класа за претставување на планинарско друштво во која ќе се чуваат информации за името на друштвото (динамички алоцирана низа од знаци), број на поминати тури (цел број) и број на членови во планинарското друштво (цел број). За оваа класа да се напише:

оператор + за собирање на две друштва што како резултат враќа друштво со број на членови еднаков на збирот од членовите од двете друштва, а останатите атрибути на резултантното друштво ги добиваат вредностите на соодветните атрибути од друштвото со поголем број на членови

оператори >, < за споредба во однос на бројот на членови во планинарските друштва

оператор << за печатење на информациите за планинарското друштво

Да се напише функција што на влез прима низа од планинарски друштва и вкупен број на друштва во низата и го печати планинарското друштво што има најголем број на членови .
*/
#include <iostream>
#include <string.h>
using namespace std;
class PlDrustvo {
private:
    char *ime;
    int brTuri;
    int brClenovi;
    void copy(const PlDrustvo &p)
    {
        this->ime = new char[strlen(p.ime) + 1];
        strcpy(this->ime, p.ime);
        this->brTuri = p.brTuri;
        this->brClenovi = p.brClenovi;
    }
public:
    PlDrustvo(char *ime = "", int brTuri = 0, int brClenovi = 0)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->brTuri = brTuri;
        this->brClenovi = brClenovi;
    }
    PlDrustvo &operator =(const PlDrustvo &p)
    {
        if(this == &p) return *this;
        copy(p);
        return *this;
    }
    PlDrustvo(const PlDrustvo &p)
    {
        copy(p);
    }
    ~PlDrustvo()
    {
        delete [] ime;
    }
    PlDrustvo operator +(const PlDrustvo &p)
    {
        PlDrustvo f;
        f.brClenovi = this->brClenovi + p.brClenovi;
        if(p.brClenovi > this->brClenovi)
        {
            f.brTuri = p.brTuri;
            f.ime = new char[strlen(p.ime) + 1];
            strcpy(f.ime, p.ime);
        }
        else if(p.brClenovi < this->brClenovi)
        {
            f.brTuri = this->brTuri;
            f.ime = new char[strlen(this->ime) + 1];
            strcpy(f.ime, this->ime);
        }
        return f;
    }
    bool operator <(const PlDrustvo &p)
    {
        return brClenovi < p.brClenovi;
    }
    bool operator >(const PlDrustvo &p)
    {
        return brClenovi > p.brClenovi;
    }
    friend ostream& operator <<(ostream& out, PlDrustvo &p);
    int getBrClenovi()
    {
        return brClenovi;
    }
};
ostream& operator <<(ostream& out, PlDrustvo &p)
{
    out << "Ime: " << p.ime << " Turi: " << p.brTuri << " Clenovi: " << p.brClenovi << endl;
    return out;
}

void najmnoguClenovi(PlDrustvo *p, int o) {
    PlDrustvo dr;
    dr = p[0];
    for(int j = 1; j < o; ++j)
    {
        if(dr < p[j])
            dr = p[j];
    }
    cout << "Najmnogu clenovi ima planinarskoto drustvo: " << dr;
}

int main()
{        		
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i=0;i<3;i++)
   	{
    	char ime[100];
    	int brTuri;
    	int brClenovi;
    	cin>>ime;
    	cin>>brTuri;
    	cin>>brClenovi;
    	PlDrustvo p(ime,brTuri,brClenovi);
        drustva[i] = p;
    	
   	}
    
    pl = drustva[0] + drustva[1];
    cout<<pl;
    
    najmnoguClenovi(drustva, 3);
    
    return 0;
}

/*
Sample input
Vodno
5
100
Korab
7
50
Аурора
2
10

Sample output
Ime: Vodno Turi: 5 Clenovi: 150
Najmnogu clenovi ima planinarskoto drustvo: Ime: Vodno Turi: 5 Clenovi: 100
*/
