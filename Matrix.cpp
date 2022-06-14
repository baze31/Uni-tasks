/*
Да се напише класа за матрица. Во класата се чуваат елементите од матрицата од тип float (матрица со максимална димензија [10]x[10]) и големината на матрицата (број на редици и колони). За оваа класа да се преоптоварат следните оператори:

оператор + за собирање на број од матрица
оператор - за одземање на матрици
оператор * за множење на матрици
операторот >> за внесување на елементите на матрицата
операторот << за печатење на елементите на матрицата
Во главната функција да се креираат објекти A, B и C со подразбирливиот конструктор на класата Matrica. Од стандарден влез да се прочитаат нивните вредности. Да се отпечати вредноста на изразот A-(BC)+2** на стандарден излез.

Да се претпостави дека секогаш матриците ќе бидат квадратни со ист број на редици и колони.
*/
#include <iostream>
#include <cstring>
using namespace std;
class Matrica {
private:
float mat[100][100];
int red;
int kol;
public:
Matrica() {
red=0;
kol=0;
}

Matrica operator +(int const& br) {
Matrica drug;
drug.red=red;
drug.kol=kol;
for(int j=0;j<red;j++)
for(int i=0;i<kol;i++)
drug.mat[j][i]=mat[j][i]+br;
return drug;
}

Matrica operator -(Matrica const& m) {
Matrica drug;
drug.red=red;
drug.kol=kol;
for(int j=0;j<red;j++)
for(int i=0;i<kol;i++)
drug.mat[j][i]=mat[j][i]-m.mat[j][i];
return drug;
}

Matrica operator *(Matrica const& matr) {
Matrica drug;
drug.red=matr.red;
drug.kol=matr.kol;
for(int i=0;i<matr.red; i++)
for(int j=0;j<matr.kol; j++) {
float t=0;
for(int k=0;k<matr.red;k++)
t+= mat[i][k] * matr.mat[k][j];
drug.mat[i][j] = t;
}
return drug;
}

friend istream& operator >>(istream& input, Matrica& matr);
friend ostream& operator <<(ostream& output, Matrica& matr);
};

istream& operator >>(istream& input, Matrica& matr) {
input >> matr.red;
input >> matr.kol;
for (int i=0;i<matr.red;++i)
for (int j=0;j<matr.kol;++j)
input >> matr.mat[i][j];
return input;
}

ostream& operator <<(ostream& output, Matrica& matr) {
for (int i=0;i<matr.red;++i) {
for (int j=0;j<matr.kol;++j)
output << matr.mat[i][j] << " ";
output << endl;
}
return output;
}
//vashiot kod ovde

int main()
{
    Matrica A,B,C;
    cin>>A>>B>>C;
    Matrica D=B*C;
    Matrica R=A-D+2;
    cout<<R;
}
/*
Sample input
2
2
1 1
1 1

2
2
1 1
1 1
 
2
2
2 1
-1 1

Sample output
2 1 
2 1 
*/
