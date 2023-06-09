#include <iostream>

using namespace std;

class Lz
{
private:
    double a;
    double b;

public:
    Lz(double A, double B) : a(A), b(B) {}
    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    double getA() { return a; }
    double getB() { return b; }
};

Lz operator+(Lz l1, Lz l2)
{
    double a = l1.getA() + l2.getA();
    double b = l1.getB() + l2.getB();
    Lz wynik(a, b);
    return wynik;
}

Lz operator-(Lz l1, Lz l2)
{
    double a = l1.getA() - l2.getA();
    double b = l1.getB() - l2.getB();
    Lz wynik(a, b);
    return wynik;
}

Lz operator*(double skal, Lz ob)
{
    double a = skal * ob.getA();
    double b = skal * ob.getB();
    Lz wynik(a, b);
    return wynik;
}

Lz operator*(Lz ob, double skal)
{
    double a = skal * ob.getA();
    double b = skal * ob.getB();
    Lz wynik(a, b);
    return wynik;
}

ostream &operator<<(ostream &str, Lz obiekt)
{
    double a = obiekt.getA();
    double b = obiekt.getB();
    if (a == 0 && b == 0)
        str << 0;
    else
    {
        if (a != 0)
        {
            str << a;
            if (b > 0)
                str << "+";
        }
        if (b != 0)
            str << b << "i";
    }
    return str;
}

istream &operator>>(istream &str, Lz &obiekt)
{
    string s;
    cin >> s;
    double a = 0,
           b = 0;
    int poz_i = s.find('i');
    if (poz_i < 0) // tylko czesc rzeczywista
        a = atof(s.c_str());
    else // takze urojona
    {
        s = s.substr(0, s.length() - 1); // obcinam ostatni znak "i"
        int poz_plus = s.find('+');
        int poz_minus = s.find('-');
        int poz_dr_min = s.find('-',1);
        if (poz_plus < 0 && poz_minus <= 0 && poz_dr_min < 0) // tylko urojona
            b = atof(s.c_str());
        else // obie
        {
            if (poz_plus > 0) // a+b i -a+b
            {
                a = atof(s.substr(0, poz_plus).c_str());
                b = atof(s.substr(poz_plus, s.length() - poz_plus).c_str());
            }
            else if (poz_dr_min > 0) //-a-b
            {
                a = atof(s.substr(0, poz_dr_min).c_str());
                b = atof(s.substr(poz_dr_min, s.length() - poz_dr_min).c_str());
            }
            else // a-b
            {
                a = atof(s.substr(0, poz_minus).c_str());
                b = atof(s.substr(poz_minus, s.length() - poz_minus).c_str());
            }
        }
    }
    obiekt.setA(a);
    obiekt.setB(b);
    return str;
}

int main()
{
    // Lz tab[] = {Lz(5, 7), Lz(-5, 7), Lz(5, -7),
    //             Lz(-5, -7), Lz(0, 7), Lz(0, -7),
    //             Lz(5, 0), Lz(-5, 0), Lz(0, 0)};
    // for (int i = 0; i < 9; i++)
    //     cout << tab[i] << endl;

    Lz test(0, 0);
    cin >> test;
    cout << test;
    return 0;
}