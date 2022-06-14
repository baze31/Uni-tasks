/*
Да се дефинира класа Пица за која ќе се чуваат податоци за (5 поени):

име на пицата (низа од 15 знаци)
цена (цел број)
состојки (динамички алоцирана низа од знаци)
намалување на цената во проценти (цел број) - ако пицата не е на промоција намалувањето има вредност нула, во спротивно, вредност поголема од нула и не поголема од 100.
За потребите на оваа класа да се креираат потребните конструктори и да се напише соодветен деструктор. (10 поени) Дополнително за оваа класа да се дефинира функцијата:

pecati() - функција во која ќе се печатат податоците за пицата во следниот формат: име - состојки, цена. (5 поени)
istiSe(Pica p) - функција за споредба на две пици според состојките (5 поени):
Да се дефинира класа Picerija во која се чуваат (5 поени):

име (низа од максимум 15 знаци)
динмички алоцирана низа од објекти од класата Pica
број на пици (цел број)
За потребите на оваа класа да се дефинираат потребните конструктори и да се напише соодветен деструктор. (10 поени) Да се имплементираат и следниве методи:

dodadi (Pica P) - за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде). (10 поени)
void piciNaPromocija() - се печатат сите пици од пицеријата што се на промоција во формат : име - состојки, цена, цена со попуст. (10 поени)
*/

#include <iostream>
#include <cstring>

using namespace std;
class Pica
{

    char ime[15];
    int cena;
    char *sostojki;
    int popust;
 
	public:
        Pica():
        popust(0),sostojki(NULL),cena(0){
        
        }
        Pica(char *name, int pari, char *sos, int popusti):
        cena(pari), popust(popusti), sostojki(new char[strlen(sos)+1])
        {
            strcpy(ime,name);
            strcpy(sostojki,sos);
        }
        Pica(const Pica &zz)
        {
            strcpy(ime,zz.ime);
            cena=zz.cena;
            popust=zz.popust;
            sostojki=new char(strlen(zz.sostojki));
            strcpy(sostojki,zz.sostojki);
        }
        Pica &operator=(const Pica &pizza)
        {
             delete [] sostojki;
             sostojki = new char[strlen(pizza.sostojki)+1];
             strcpy(sostojki,pizza.sostojki);
             strcpy(ime,pizza.ime);
             popust = pizza.popust;
             cena = pizza.cena; 
             return *this;
        } 
        void pecati()
        {
            cout<<ime<<" "<<"-"<<" "<<sostojki<<","<<" "<<cena<<" ";
        }
        int getPopust()
        {
                return popust;
        }
        int getCena()
        {
                return cena;
        } 
        int istiSe(Pica &piz)
        {
            if(strcmp(this->sostojki,piz.sostojki)==0)
            {
                return 1;
            } 
            else
            {
                return 0;
            }
        } 
        ~Pica()
        {
            delete [] sostojki;
        } 
    };
    class Picerija
    {
        private:
            char ime[15];
            Pica *p;
            int brPici;
        public:
            Picerija(){
 
            } 
        Picerija(char *name):
        brPici(0),p(NULL)
        {
            strcpy(ime,name);
        } 
        void setIme(char *name)
        {
            strcpy(ime,name);
        } 
        char *getIme()
        {
            return ime;
        } 
        Picerija(const Picerija &o)
        {
            strcpy(ime,o.ime);
            brPici=o.brPici;
            p=new Pica[o.brPici];
            for(int i=0;i<brPici;i++)
            {
                p[i]=o.p[i];
            }
        } 
        Picerija &operator=(const Picerija &pic)
        {
            delete [] p; 
            p=new Pica[pic.brPici+1];
            for(int i=0;i<brPici;i++)
            {
                p[i]=pic.p[i];
            }
            strcpy(ime,pic.ime);
            brPici=pic.brPici; 
            return *this;
        } 
        void dodadi(Pica &pza)
        {
            if(pza.getPopust()>0&&pza.getPopust()<100)
            {
                Pica *nova = new Pica[brPici+1]; 
                    for(int i=0;i<brPici;i++)
                    {
                        nova[i]=p[i]; 
                    } 
                    if(brPici==0)
                    {
                        nova[brPici]=pza;
                        delete [] p;
                        p=nova; 
                        brPici+=1;
                    } 
                    else if(nova[brPici-1].istiSe(pza)!=1)
                    { 
                        nova[brPici]=pza;
                        delete [] p; 
                        p=nova; 
                        brPici+=1;
                    } 
            } 
        } 
        ~Picerija()
        {
            delete [] p;
        } 
        void piciNaPromocija()
        {
            for(int j=0;j<brPici;j++)
            {
                p[j].pecati();
                int popust;
                popust=p[j].getCena()-((p[j].getCena()*p[j].getPopust())/100);
                cout<<popust<<endl;
            }
        }
    };


int main () {

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for(int i = 0; i < n; i++){
        char imp[100];
        cin.get();
        cin.getline(imp,100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki,100);
        int popust;
        cin >> popust;
        Pica p(imp,cena,sostojki,popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp,100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki,100);
    int popust;
    cin >> popust;
    Pica p(imp,cena,sostojki,popust);
    p2.dodadi(p);

    cout<<p1.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p1.piciNaPromocija();

    cout<<p2.getIme()<<endl;
    cout<<"Pici na promocija:"<<endl;
    p2.piciNaPromocija();

	return 0;
}

/*
Sample input
FINKI-Pica
4
Margarita
200
Domaten sos, kaskaval, maslinovo maslo
0
Napolitana 
210
Domaten sos, kaskaval, svezi sampinjoni, maslinovo maslo
0
Kapricioza 
210
Domaten sos, kaskaval, sunka, svezi sampinjoni
30
Vegetarijana
230
Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka
20
Pica-FINKI
Tuna
230
Domaten sos, kaskaval, pcenka, maslinki, tuna, rukola
0

Sample output
FINKI-Pica
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
Pica-FINKI
Pici na promocija:
Kapricioza  - Domaten sos, kaskaval, sunka, svezi sampinjoni, 210 147
Vegetarijana - Domaten sos, kaskaval, tikvici, svezi sampinjoni, piperka, domat, maslinki, rukola, pcenka, 230 184
*/
