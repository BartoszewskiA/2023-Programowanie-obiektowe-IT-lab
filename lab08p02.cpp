#include <iostream>
#include <sstream>

using namespace std;

class RGB
{
private:
    int R;
    int G;
    int B;

public:
    RGB(int r, int g, int b) : R(r), G(g), B(b)
    {
        cout << "\nkonstruktor " << toString() << endl;
    }
    ~RGB()
    {
        cout << "\ndestruktor " << toString() << endl;
    }
    string toString()
    {
        stringstream s;
        s << "R=" << R << " G=" << G << " B=" << B << " ";
        return s.str();
    }
    friend RGB dodaj(const RGB &p1, const RGB &p2);
    // nie będzie metod dostepowych
};

RGB dodaj(const RGB &p1, const RGB &p2)
{
    int r = p1.R + p2.R;
    int g = p1.G + p2.G;
    int b = p1.B + p2.B;
    if (r > 255)
        r = 255;
    if (g > 255)
        g = 255;
    if (b > 255)
        b = 255;

    RGB wynik(r, g, b);
    return wynik;
}

int main()
{

    RGB p1(10, 30, 200);
    RGB p2(30, 200, 100);
    // RGB wynik = dodaj(p1, p2);
    // cout << wynik.toString();
    cout << dodaj(p1, p2).toString();

    return 0;
}