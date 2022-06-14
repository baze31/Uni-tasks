/*
Да се дефинира класа Krug, во која се чуваат информации за:

радиус float
бројот π const float.
Во класата да се реализираат:

default конструктор и конструктор со аргументи
метод за пресметување плоштина
метод за пресметување периметар
метод кој кажува дали плоштината и периметарот на даден круг се еднакви
*/

#include <iostream>
using namespace std;

class Krug {
    private:
    float radius;
    const float pi=3.14;
	public:
    Krug(float r=1.0)
    {
    	radius=r;
    }
    Krug(const Krug &k)
    {
    	radius=k.radius;
    }
    float perimetar()
    {
    	return 2*pi*radius;
    }
    float plostina()
    {
    	return radius*radius*pi;
    }
    int ednakvi()	
    {
    	if(plostina()==perimetar())
        	return 1;
        	else return 0;
    }
    float getRadius()
    {
    	return radius;
    }
    void setRadius(float rad)
    {
    	radius=rad;
    }
    };

int main() {
	float r;
	cin >> r;
	Krug k(r);
	cout << k.perimetar() << endl;
	cout << k.plostina() << endl;
	cout << k.ednakvi() <<endl;
    
	return 0;
}

/*
Sample input
5

Sample output
31.4
78.5
0
*/
