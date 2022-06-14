/*
Да се дефинира класа Film, во која ќе се чуваат информации за:

име низа од 100 знаци
режисер низа од 50 знаци
жанр низа од 50 знаци
година цел број
Сите променливи треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:

default конструктор и конструктор со аргументи
метод за печатење на информациите за филмот
Дополнително да се реализира надворешна функција:

void pecati_po_godina(Film *f, int n, int godina) која ќе прима аргумент низа од филмови, вкупниот број на филмови и година, а треба да ги отпечати само филмовите кои се направени во дадената година.
*/

#include <iostream>
#include <cstring>
using namespace std;

// vashiot kod ovde
class Film {
private:
    char ime[100];
    char rezhiser[50];
    char zhanr[50];
    int godina;
public:
    Film () {
    }
    Film (char *ime, char *rezhiser, char *zhanr, int godina)
    {
    	strcpy(this->ime, ime);
        strcpy(this->rezhiser, rezhiser);
        strcpy(this->zhanr, zhanr);
        this->godina = godina;        
    }
    int get_godina(){
    	return godina;
    }
    void pecati ()
    {
    	cout << "Ime: " << ime << endl;
        cout << "Reziser: " << rezhiser << endl;
        cout << "Zanr: " << zhanr << endl;
        cout << "Godina: " << godina << endl;
    }
    
};

void pecati_po_godina(Film *f, int n, int godina)
{
    for (int i = 0; i < n; i++){
        if (f[i].get_godina() == godina){
            f[i].pecati();
        }
	}
}

int main() {
 	int n;
 	cin >> n;
 	//da se inicijalizira niza od objekti od klasata Film
    Film filmovi[100];
 	for(int i = 0; i < n; ++i) {
 		char ime[100];
 		char rezhiser[50];
 		char zhanr[50];
 		int godina;
 		cin >> ime;
 		cin >> rezhiser;
 		cin >> zhanr;
 		cin >> godina;
 		//da se kreira soodveten objekt
        filmovi[i] = Film(ime,rezhiser,zhanr,godina);
 	}
 	int godina;
 	cin >> godina;
    pecati_po_godina(filmovi, n, godina);
 	//da se povika funkcijata pecati_po_godina
 	return 0;
 }

/*
Sample input
4
Frankenweenie
Tim_Burton
Animation
2012
Lincoln
Steven_Spielberg
History
2012
Wall-E
Andrew_Stanton
Animation
2008
Avatar
James_Cameron
Fantasy
2009
2008

Sample output
Ime: Wall-E
Reziser: Andrew_Stanton
Zanr: Animation
Godina: 2008
*/
