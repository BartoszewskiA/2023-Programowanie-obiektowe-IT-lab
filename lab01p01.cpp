#include <iostream>
#include <string>

using namespace std;

struct osoba
{
    int Id;
    string imie;
    string nazwisko;
};
osoba *baza[100];
int n = 0; // liczba elemntów w tablicy

void dodaj(string im, string nazw);
void wypisz(int poz);
void wyszukaj(string co);

int main()
{
    string im, nazw;
    while (1)
    {
        cout << "Podaj imie: ";
        getline(cin, im);
        if (im.length() == 0) // im==""
            break;
        cout << "Podaj nazwisko: ";
        getline(cin, nazw);
        dodaj(im, nazw);
    }
    for (int i = 0; i < n; i++)
        wypisz(i);
    cout << endl
         << endl;
    cout << "co wyszukac? ";
    getline(cin, im);
    wyszukaj(im);
    return 0;
}

void dodaj(string im, string nazw)
{
    baza[n] = new osoba;
    baza[n]->imie = im;
    baza[n]->nazwisko = nazw;
    baza[n]->Id = n + 1;
    n++;
}

void wypisz(int poz)
{
    cout << "--------------------------------------" << endl
         << "Id: " << baza[poz]->Id
         << " Imie: " << baza[poz]->imie
         << " Nazwisko: " << baza[poz]->nazwisko
         << endl;
}

void wyszukaj(string co)
{
    for (int i = 0; i < n; i++)
    {
        if (baza[i]->imie == co || baza[i]->nazwisko == co)
            wypisz(i);
    }
}