#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

class czas_pracy
{
public:
    czas_pracy()
    {
        zapisz_czas();
    }
    ~czas_pracy()
    {
        zapisz_czas();
    }
    void zapisz_czas()
    {
        fstream plik;
        plik.open("log.txt", ios::app);
        plik << time(NULL) << endl;
        plik.close();
    }

    int zlicz_czas_pracy()
    {
        fstream plik;
        plik.open("log.txt", ios::in);
        if (!plik.good())
            return 0;

        string s1, s2;
        int p, k, odstep, czas_calkoity = 0;
        while (!plik.eof())
        {
            getline(plik, s1);
            getline(plik, s2);
            if (s1.length() > 0 && s2.length() > 0)
            {
                p = atoi(s1.c_str());
                k = atoi(s2.c_str());
                odstep = k - p;
                // cout << s1 << " " << s2 << " " << odstep << endl;
                czas_calkoity += odstep;
            }
        }
        plik.close();
        return czas_calkoity;
    }

    void raport()
    {
        fstream plik;
        plik.open("log.txt", ios::in);
        if (!plik.good())
            return;
        string s1, s2;
        // int pocz, koniec;
        time_t p, k;
        tm *pocz, *kon;
        while (!plik.eof())
        {
            getline(plik, s1);
            getline(plik, s2);
            if (s1.length() > 0 && s2.length() > 0)
            {
                // cout << s1 << " do " << s2 << endl;
                p = atoi(s1.c_str());
                k = atoi(s2.c_str());
                pocz = localtime(&p);
                kon = localtime(&k);
                cout << pocz->tm_year + 1900 << "."
                     << pocz->tm_mon + 1 << "."
                     << pocz->tm_mday << " "
                     << pocz->tm_hour << ":"
                     << pocz->tm_min << ":"
                     << pocz->tm_sec
                     << "  do  "
                     << kon->tm_year + 1900 << "."
                     << kon->tm_mon + 1 << "."
                     << kon->tm_mday << " "
                     << kon->tm_hour << ":"
                     << kon->tm_min << ":"
                     << kon->tm_sec
                     << endl;
            }
        }

        plik.close();
    }
};
int main()
{
    czas_pracy c1;
    cout << "Przepracowales: " << c1.zlicz_czas_pracy() << endl;
    c1.raport();
    cout
        << "nacisnij dowolny klawisz ";
    getch();
    return 0;
}