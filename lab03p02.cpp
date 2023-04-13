#include <iostream>
#include <ctime>

using namespace std;

class kotSchrodingera
{
private:
    // -1 - martwy
    // 0 - stan nieustalony
    // +1 - zywy
    int stan;

public:
    kotSchrodingera() { stan = 0; }
    string otworzPudelko()
    {
        if (stan == 0)
        {
            if (rand() % 2 == 0)
                stan = -1;
            else
                stan = 1;
        }
        if (stan == -1)
            return "kotek jest martwy";
        else
            return "kotek jest zywy";
    }

    
};



int main()
{
    srand(time(NULL));
    kotSchrodingera k1;
    for (int i = 0; i < 10; i++)
    {
        cout << k1.otworzPudelko() << endl;
    }
    return 0;
}