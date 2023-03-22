#include <iostream>
#include <math.h>

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
    double getX1()
    {
        if (getDelta() < 0)
        {
            return 0;
        }
        else
        {
            double x1 = (-getB() - sqrt(getDelta())) / 2 * getA();
            return x1;
        }
    }
    double getX2()
    {
        if (getDelta() <= 0)
        {
            cout << "Delta mniejsza lub rowna zero";
            return 0;
        }
        else
        {
            double x2 = (-getB() + sqrt(getDelta())) / 2 * getA();
            return x2;
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
    Kwadratowe row1;
    row1.setA(1);
    row1.setB(2);
    row1.setC(1);
    cout << "A= " << row1.getA() << "\nB= " << row1.getB() << "\nC= " << row1.getC() << endl;
    cout << "Delta = " << row1.getDelta() << endl;
    row1.getX1();
    row1.getX2();
    // cout << "x1 = " << row1.getX1() << endl;
    // cout << "x2 = " << row1.getX2() << endl;
    Kwadratowe row2(2, 4, 6);
    cout << "A= " << row2.getA() << "\nB= " << row2.getB() << "\nC= " << row2.getC() << endl;
    cout << "Delta = " << row2.getDelta() << endl;
    row2.getX1();
    row2.getX2();
    return 0;
}
