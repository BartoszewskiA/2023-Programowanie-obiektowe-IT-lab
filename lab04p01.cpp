#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

class Kwadratowe
{
private:
    int a;
    int b;
    int c;

public:
    Kwadratowe(int A = 0, int B = 0, int C = 0) : a(A), b(B), c(C) {}
    void setA(int a) { this->a = a; }
    void setB(int b) { this->b = b; }
    void setC(int c) { this->c = c; }
    int getA() { return a; }
    int getB() { return b; }
    int getC() { return c; }
    double getDelta()
    {
        double delta = (getB() * getB()) - 4 * getA() * getC();
        return delta;
    }
    string getX1()
    {
        if (getDelta() < 0)
        {
            return "";
        }
        else
        {
            double x1 = (-getB() - sqrt(getDelta())) / 2 * getA();
            stringstream s;
            s << x1;
            return s.str();
        }
    }
    string getX2()
    {
        if (getDelta() <= 0)
        {
            return "";
        }
        else
        {
            double x2 = (-getB() + sqrt(getDelta())) / 2 * getA();
            stringstream s;
            s << x2;
            return s.str();
        }
    }
    

    // void getX1()
    // {
    //     if (getDelta() < 0)
    //     {
    //         cout << "Delta mniejsza od zera, brak rozwiazan dla x1" << endl;
    //     }
    //     else
    //     {
    //         double x1 = (-getB() - sqrt(getDelta())) / 2 * getA();
    //         cout << "x1 = " << x1 << endl;
    //     }
    // }
    // void getX2()
    // {
    //     if (getDelta() <= 0)
    //     {
    //         cout << "Delta mniejsza lub rowna zero, brak rozwiazan dla x2" << endl;
    //     }
    //     else
    //     {
    //         double x2 = (-getB() + sqrt(getDelta())) / 2 * getA();
    //         cout << "x2 = " << x2 << endl;
    //     }
    // }
    ~Kwadratowe() {}
};

int main()
{
    Kwadratowe row1(1, 2, -11);
    cout << row1.getDelta() << " " << row1.getX1() << " " << row1.getX2();

    return 0;
}
