#include <iostream>

using namespace std;

class Liczba
{
private:
    int x;
    static double ile;
    static double suma;

public:
    Liczba(int X) : x(X)
    {
        ++ile;
        suma += X;
    }
    void setX(int x)
    {
        suma -= this->x;
        this->x = x;
        suma += this->x;
    }
    static double getIle() { return ile; }
    static double getSuma() { return suma; }
    static double getSrednia() { return suma / ile; }
    ~Liczba()
    {
        ile--;
        suma -= x;
    }
};

double Liczba::suma = 0;
double Liczba::ile = 0;

int main()
{
    // Liczba x1(10), x2(30), x3(100);
    Liczba *x1 = new Liczba(10);
    Liczba *x2 = new Liczba(20);
    Liczba *x3 = new Liczba(30);
    cout << Liczba::getIle() << " " << Liczba::getSrednia() << endl;
    delete x3;
    cout << Liczba::getIle() << " " << Liczba::getSrednia();
    return 0;
}