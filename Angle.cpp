/*
Да се дефинира класа Agol, во која се чуваат информации за:

степени, минути и секунди (int)
Во класата да се реализираат:

конструктор по потреба
методи за поставување на вредности на атрибутите на класата (set методи)
метод за пресметуванје на вредноста на аголот во секунди
Да се дефинира и метод за проверување на тоа дали внесениот агол е валиден, односно дали се внесени соодветни вредности за атрибутите (во границите кои ги дозволуваат).
*/
#include <iostream>
using namespace std;
class Agol {
private:
    int stepeni;
    int minuti;
    int sekundi;
public:
void set_stepeni(int step)
{
     stepeni=step;
}
void set_minuti(int min)
{
     minuti=min;
}
void set_sekundi(int sek)
{
     sekundi=sek;
}
    int vo_sekundi()
{
    return sekundi+(minuti*60)+(stepeni*3600);
}
    
} a1;

bool  proveri(int step,int min,int sek)
{
    if (sek >=60  || min >=60  || step>=360)
    {cout<<("Ne validni vrednosti za agol\n");
           return 0;}
    else
        return 1;
}

int main() {
    
    //da se instancira objekt od klasata Agol
    int deg, min, sec;
    cin >> deg >> min >> sec;
    
    if (proveri(deg, min, sec)) {
    
    	a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.vo_sekundi();
        
    }
    
    return 0;
} 

/*
Sample input
380 80 0
Sample output
Ne validni vrednosti za agol
*/
