#include <iostream>
#include <string>

using namespace std;

// Deklarace tříd před použitím
class Osoba;
class PolozkaFaktury;

class Faktura
{
private:
    int num;
    Osoba* osoba;
    PolozkaFaktury** polozkaFaktury;

public:
    Faktura(int n);
    ~Faktura();
    void CreateFaktura(string n, string a, int p, string t);
};

class Osoba
{
private:
    string name;
    string address;

public:
    Osoba(string n, string a);
    string GetName();
    string GetAddress();
};

class PolozkaFaktury
{
private:
    int price;
    string title;

public:
    PolozkaFaktury(int p, string t);
    int GetPrice();
    string GetTitle();
};

Faktura::Faktura(int n)
{
    this->num = n;
    this->osoba = nullptr;
    this->polozkaFaktury = new PolozkaFaktury*[n];
}

Faktura::~Faktura()
{
    delete[] polozkaFaktury;
}

void Faktura::CreateFaktura(string n, string a, int p, string t)
{
    Osoba* newOsoba = new Osoba(n, a);
    this->osoba = newOsoba;

    PolozkaFaktury* newPolozka = new PolozkaFaktury(p, t);
    this->polozkaFaktury[this->num] = newPolozka;
}

Osoba::Osoba(string n, string a)
{
    this->name = n;
    this->address = a;
}

string Osoba::GetName()
{
    return this->name;
}

string Osoba::GetAddress()
{
    return this->address;
}

PolozkaFaktury::PolozkaFaktury(int p, string t)
{
    this->price = p;
    this->title = t;
}

int PolozkaFaktury::GetPrice()
{
    return this->price;
}

string PolozkaFaktury::GetTitle()
{
    return this->title;
}

int main()
{
    Faktura faktura(1);
    faktura.CreateFaktura("Jan Novák", "Praha", 100, "Kniha");


    return 0;
}
