#include <iostream>
#include <ctime>

using namespace std;

class Random
{
public:
    Random() { srand(time(NULL)); }
    int nextInt() { return rand(); }
    int nextInt(int b) { return rand() % b; }
    int nextInt(int a, int b) { return rand() % (b - a) + a; }
    double nextDouble() { return (rand() % 10000) / 10000.0; }
    int kostka() { return rand() % 6 + 1; }
    string moneta()
    {
        int los = rand() % 2;
        if (los == 0)
            return "reszka";
        else
            return "orzel";
    }
};

int main()
{
    Random random;
    for (int i = 0; i < 100; i++)
        cout << random.moneta() << " ";
    return 0;
}