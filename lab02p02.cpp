#include <iostream>
#include <cmath>

using namespace std;

class punkt
{
private:
    int x;
    int y;

public:
    void setX(int px) { x = px; }
    void setY(int py) { y = py; }
    int getX() { return x; }
    int getY() { return y; }
    double getR();
    void wylosuj(int a, int b);
};

double punkt::getR()
{
    return sqrt(x * x + y * y);
}

void punkt::wylosuj(int a, int b)
{
    x = rand() % (b - a + 1) + a;
    y = rand() % (b - a + 1) + a;
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "Ile punktow: ";
    cin >> n;
    // ststyczna tablica wskaźników
    punkt *tab[1000];
    // tworzymy elementy
    for (int i = 0; i < n; i++)
        tab[i] = new punkt;
    // wypełniamy elementy
    for (int i = 0; i < n; i++)
        tab[i]->wylosuj(-100, 100);

    double r_min = tab[0]->getR(), r_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i]->getR() > r_max)
            r_max = tab[i]->getR();
        if (tab[i]->getR() < r_min)
            r_min = tab[i]->getR();
    }
    cout << "min=" << r_min << "  max=" << r_max;

    for (int i = 0; i < n; i++)
        delete tab[i];
    return 0;
}