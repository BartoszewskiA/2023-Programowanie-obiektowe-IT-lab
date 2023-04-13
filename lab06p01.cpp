#include <iostream>
#include <sstream>

using namespace std;

int ile = 0; // liczba utworzonych obiektow
class Osoba
{
    // private:
protected:
    int id;
    string imie;
    string nazwisko;

public:
    // Osoba(){};
    Osoba(string IMIE, string NAZWISKO);
    int getID() { return id; }
    string getImie() { return imie; }
    string getNazwisko() { return nazwisko; }
    void setImie(string imie) { this->imie = imie; }
    void setNazwisko(string nazwisko) { this->nazwisko = nazwisko; }
    string toString();
    ~Osoba();
};

Osoba::Osoba(string IMIE, string NAZWISKO) : imie(IMIE), nazwisko(NAZWISKO)
{
    id = ++ile;
}

string Osoba::toString()
{
    stringstream s;
    s << id << ": " << imie << " " << nazwisko;
    return s.str();
}

Osoba::~Osoba()
{
    cout << "\nLOG: obiekt Osoba usuniety";
}

//-------------------------------------------------------------------------------------//

class Pracownik : public Osoba
{
protected:
    string wydzial;

public:
    Pracownik(string IMIE, string NAZWISKO, string WYDZIAL) : Osoba(IMIE, NAZWISKO), wydzial(WYDZIAL) {}

    string toString()
    {
        stringstream s;
        s << id << ": " << imie << " " << nazwisko << " " << wydzial;
        // s << getID() << ": " << getImie() << " " << getNazwisko() << " " << wydzial;
        // s << Osoba::toString() << " " << wydzial;
        return s.str();
    }

    ~Pracownik() { cout << "\nLOG: obiekt Pracownik usuniety"; }
};

//-------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------//

class Kierownik : public Pracownik
{
protected:
    string pion;

public:
    Kierownik(string IMIE, string NAZWISKO, string WYDZIAL, string PION) : Pracownik(IMIE, NAZWISKO, WYDZIAL), pion(PION) {}

    string toString()
    {
        stringstream s;
        s << id << ": " << imie << " " << nazwisko << " " << wydzial << " " << pion;
        return s.str();
    }
};

//-------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------//

class Kierownik_v2 : public Osoba
{
protected:
    string wydzial;
    string pion;

public:
    Kierownik_v2(string IMIE, string NAZWISKO, string WYDZIAL, string PION) : Osoba(IMIE, NAZWISKO), wydzial(WYDZIAL), pion(PION) {}

    string toString()
    {
        stringstream s;
        s << id << ": " << imie << " " << nazwisko << " " << wydzial << " " << pion;
        return s.str();
    }
};

//-------------------------------------------------------------------------------------//
int main()
{
    Pracownik ktos("Jan", "Kowalski", "IT");
    cout << ktos.toString();
    return 0;
}