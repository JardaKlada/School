#include <iostream>
#include <vector>

using namespace std;

//#pragma region Produkt

class Produkt
{
private:
    string nazev;
    float price;
    int code;
    string description;
    float sleva;
    static int productsCount;

public:
    Produkt(string na, float p, int c, string d);
    Produkt(string na, float p, int c, string d, float discount);
    ~Produkt();

    string GetNazev();
    float GetPrice();
    int GetCode();
    string GetDescription();
    static int GetProduktsCount();
    void SetPrice(float newPrice);
};

int Produkt::productsCount = 0;


#pragma region Pretizeni
Produkt::Produkt(string na, float p, int c, string d)
{
    this->nazev = na;
    this->price = p;
    this->code = c;
    this->description = d;
    this->sleva = 0;
    Produkt::productsCount += 1;
}

Produkt::Produkt(string na, float p, int c, string d, float discount)
{
    this->nazev = na;
    this->price = p;
    this->code = c;
    this->description = d;
    this->sleva = discount;
    Produkt::productsCount += 1;
}

Produkt::~Produkt()
{
    Produkt::productsCount -= 1;
}

int Produkt::GetProduktsCount()
{
    return Produkt::productsCount;
}

string Produkt::GetNazev()
{
    return this->nazev;
}

float Produkt::GetPrice()
{
    return this->price;
}

int Produkt::GetCode()
{
    return this->code;
}

string Produkt::GetDescription()
{
    return this->description;
}

void Produkt::SetPrice(float newPrice)
{
    this->price = newPrice;
    cout << "Cena produktu " << this->nazev << " byla aktualizována na " << newPrice << " Kč." << endl;
}

#pragma endregion

//#pragma region Storage

class Storage
{
private:
    Produkt** produkty;
    vector<int> amountOfProduct;

public:
    Storage(int p);
    ~Storage();

    Produkt* GetProdukt(int c);
    int GetAmounth(int c);
    Produkt* CreateProdukt(string nazev, int code, float price, string popis, int amounth);

    void BuyProduct(int c, int a);
    void SellProduct(int c, int a);
};

Storage::Storage(int p)
{
    this->produkty = new Produkt*[p];
    this->amountOfProduct = {};
}

Storage::~Storage()
{
    for (int i = 0; i < produkty[0]->GetProduktsCount(); i++)
    {
        delete produkty[i];
    }
    delete produkty;
}

Produkt* Storage::CreateProdukt(string nazev, int code, float price, string popis, int amounth)
{
    Produkt* newProduct = new Produkt(nazev, price, code, popis);
    this->produkty[produkty[0]->GetProduktsCount()] = newProduct;
    this->amountOfProduct.push_back(amounth);

    cout << "Vytvořen nový produkt: " << nazev << " s kódem " << code << " a cenou " << price << " Kč." << endl;

    return newProduct;
}

Produkt* Storage::GetProdukt(int code)
{
    for (int i = 0; i < produkty[0]->GetProduktsCount(); i++)
    {
        if (produkty[i]->GetCode() == code)
        {
            return produkty[i];
        }
    }
    return nullptr;
}

int Storage::GetAmounth(int c)
{
    return this->amountOfProduct[c];
}

void Storage::BuyProduct(int c, int a)
{
    this->amountOfProduct[c] += a;
}

void Storage::SellProduct(int c, int a)
{
    this->amountOfProduct[c] -= a;
}

#pragma endregion

//#pragma region Objednavka

class Objednavka
{
private:
    bool completed;

    vector<Produkt> listOfProducts;
    vector<int> numberOfProducts;

    
    #pragma region Trida v roli objektu
    static int orderAmounth;

public:
    Objednavka(vector<Produkt> p, vector<int> a);

    vector<Produkt>* GetListOfProducts();
    vector<int>* GetNumberOfProducts();

    float GetFullPrice();
    void addItem(Produkt* p, int a);
    void deleteItem(Produkt* p);
    int GetOrderAmount();
};

int Objednavka::orderAmounth = 0;

Objednavka::Objednavka(vector<Produkt> p, vector<int> a)
{
    this->completed = false;
    this->listOfProducts.insert(listOfProducts.end(), p.begin(), p.end());
    this->numberOfProducts.insert(numberOfProducts.end(), a.begin(), a.end());
    Objednavka::orderAmounth += 1;
}

int Objednavka::GetOrderAmount()
{
    return Objednavka::orderAmounth;
}

void Objednavka::addItem(Produkt* p, int a)
{
    this->listOfProducts.push_back(*p);
    this->numberOfProducts.push_back(a);
}

void Objednavka::deleteItem(Produkt* p)
{
    int it = 0;
    for (int i = 0; i < listOfProducts.size(); i++)
    {
        if (this->listOfProducts[i].GetCode() == p->GetCode())
        {
            listOfProducts.erase(listOfProducts.begin() + it);
        }
        it++;
    }
}

float Objednavka::GetFullPrice()
{
    float fullPrice = 0;
    for (int i = 0; i < this->numberOfProducts.size(); i++)
    {
        fullPrice += this->numberOfProducts[i] * (this->listOfProducts[i].GetPrice());
    }
    return fullPrice;
}

vector<Produkt>* Objednavka::GetListOfProducts()
{
    return &this->listOfProducts;
}

vector<int>* Objednavka::GetNumberOfProducts()
{
    return &this->numberOfProducts;
}

#pragma endregion

#pragma region Dedicnost Abstraktni

class Uzivatel
{
private:
    string name;
    int id;
    static int uzivatelCount;

public:
    Uzivatel(string n, int i);
    virtual ~Uzivatel();

    string GetName();
    int GetId();
    int GetUzivatelCount();

    #pragma region Polymorfismus
    virtual Objednavka* MakeOrder(vector<Produkt> p, vector<int> a) = 0;
};

int Uzivatel::uzivatelCount = 0;

Uzivatel::Uzivatel(string n, int i) : name(n), id(i)
{
    Uzivatel::uzivatelCount += 1;
}

Uzivatel::~Uzivatel()
{
    Uzivatel::uzivatelCount -= 1;
}

int Uzivatel::GetUzivatelCount()
{
    return Uzivatel::uzivatelCount;
}

string Uzivatel::GetName()
{
    return this->name;
}

int Uzivatel::GetId()
{
    return this->id;
}


#pragma endregion

//#pragma region Zakaznik

class Zakaznik : public Uzivatel
{
private:
    
public:
    Zakaznik(string n, int i) : Uzivatel(n, i) {}
    Objednavka* MakeOrder(vector<Produkt> p, vector<int> a) override;

};

Objednavka* Zakaznik::MakeOrder(vector<Produkt> p, vector<int> a)
{
    Objednavka* newOrder = new Objednavka(p, a);
    
    cout << "Uživatel " << this->GetName() << " vytvořil novou objednávku." << endl;
    
    cout << "Seznam produktů v objednávce:" << endl;
    for (int i = 0; i < p.size(); ++i) {
        cout << " - " << p[i].GetNazev() << endl;
    }
    
    return newOrder;
}

#pragma endregion

//#pragma region Eshop

#pragma region Kompozice

class Eshop
{
private:
    Storage* sklad;
    Uzivatel** uzivatele;
    vector<Objednavka*> seznamObjednavek;

public:
    Eshop(int p, int u);
    ~Eshop();
    void AddOrder(Objednavka* o);
    Storage* GetStorage();
};

Eshop::Eshop(int p, int u)
{
    this->sklad = new Storage(p);
    this->uzivatele = new Uzivatel*[u];
}

Eshop::~Eshop()
{
    for(int i = 0; i < this->uzivatele[0]->GetUzivatelCount(); i++)
    {
        if(this->uzivatele[0]->GetUzivatelCount() == 0)
        {
            delete uzivatele[i];
        }
    }
    delete[] uzivatele;
    delete this->sklad;
}

Storage* Eshop::GetStorage()
{
    return this->sklad;
}

void Eshop::AddOrder(Objednavka* novaObjednavka)
{
    seznamObjednavek.push_back(novaObjednavka);
    cout << "Objednávka byla přidána do seznamu." << endl;
}

#pragma endregion

//#pragma region Zamestnanec

class Zamestnanec : public Zakaznik
{
private:
    Eshop* eshop; 

public:
    Zamestnanec(string n, int i, Eshop* es) : Zakaznik(n, i), eshop(es) {}

    Produkt CreateProduct(string nazev, float price, int code, string description)
    {
        Storage* sklad = eshop->GetStorage();
        return *(sklad->CreateProdukt(nazev, code, price, description, 0));
    }

    void ChangePrice(int id, float newPrice)
    {
        Storage* sklad = eshop->GetStorage();
        Produkt* produkt = sklad->GetProdukt(id);
        if (produkt != nullptr) {
            produkt->SetPrice(newPrice);
            cout << "Cena produktu s ID " << id << " byla změněna na " << newPrice << " Kč." << endl;
        } else {
            cout << "Produkt s ID " << id << " nebyl nalezen." << endl;
        }
    }

    Objednavka* MakeOrder(vector<Produkt> p, vector<int> a) override;
};

Objednavka* Zamestnanec::MakeOrder(vector<Produkt> p, vector<int> a)
{
    for (int i = 0; i < p.size(); ++i) {
        float discountedPrice = p[i].GetPrice() * 0.9;
        p[i].SetPrice(discountedPrice);
    }
    Objednavka* newOrder = new Objednavka(p, a);
    cout << "Zaměstnanec " << this->GetName() << " vytvořil novou objednávku se slevou." << endl;
    
    cout << "Seznam produktů v objednávce:" << endl;
    for (int i = 0; i < p.size(); ++i) {
        cout << " - " << p[i].GetNazev() << endl;
    }
    return newOrder;
}

#pragma endregion

//#pragma region Administrator

class Administrator : public Zamestnanec
{
private:
    Eshop* eshop;

public:
    Administrator(string n, int i, Eshop* es) : Zamestnanec(n, i, es) {}

    void RemoveUser(Uzivatel* user, Uzivatel** users, int& userCount);
    Objednavka* MakeOrder(vector<Produkt> p, vector<int> a) override;
};

void Administrator::RemoveUser(Uzivatel* user, Uzivatel** users, int& userCount)
{
    int index = -1;
    for (int i = 0; i < userCount; ++i)
    {
        if (users[i] == user)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < userCount - 1; ++i)
        {
            users[i] = users[i + 1];
        }
        userCount--;
        delete user;
        cout << "Uživatel byl úspěšně odstraněn." << endl;
    } else {
        cout << "Uživatel nebyl nalezen." << endl;
    }
}

Objednavka* Administrator::MakeOrder(vector<Produkt> p, vector<int> a)
{
    for (int i = 0; i < p.size(); ++i) {
        float discountedPrice = p[i].GetPrice() * 0.8;
        p[i].SetPrice(discountedPrice);
    }
    Objednavka* newOrder = new Objednavka(p, a);
    cout << "Administrátor " << this->GetName() << " vytvořil novou objednávku se slevou." << endl;
    return newOrder;
}

#pragma endregion


//#pragma region main

int main()
{
    Eshop* obchod = new Eshop(100, 10);

    vector<Produkt> produkty;
    vector<int> mnozstvi = {2, 1};
#pragma region Polymorfni prirazeni
    Zamestnanec* polymorf = new Zamestnanec("Polymorfni", 2, obchod);
    Uzivatel* uzivatel = polymorf;

    string podlahy[] = {"Dřevěná podlaha", "Kobercová podlaha", "Kamenná dlažba", "Laminátová podlaha", "PVC podlaha",
                        "Korková podlaha", "Betonová podlaha", "Linoleová podlaha", "Květinový koberec", "Parkety"};

    string jmena[] = {"Anna", "David", "Eva", "Jakub", "Karolína", "Martin", "Petra", "Tomáš", "Veronika", "Zdeněk"};

    polymorf->MakeOrder(produkty, mnozstvi);
    polymorf->ChangePrice(100 + 2, 50.0 + 2 * 3);

    for (int i = 0; i < 10; ++i) {
        produkty.push_back(Produkt(podlahy[i], 10.0 + i * 5, 100 + i, "Popis produktu " + to_string(i+1)));
    }

    for (int i = 0; i < 10; ++i) {
        cout << "Vytváření uživatele " << i+1 << endl;
        Zakaznik* zakaznik = new Zakaznik(jmena[i], 200 + i);
        zakaznik->MakeOrder(produkty, mnozstvi);
        cout << endl;
    }

    for (int i = 0; i < 10; ++i) {
        cout << "Vytváření zaměstnance " << i+1 << endl;
        Zamestnanec* zamestnanec = new Zamestnanec("Zamestnanec " + jmena[9 - i], 200 + i, obchod);
        zamestnanec->MakeOrder(produkty, mnozstvi);
        zamestnanec->ChangePrice(100 + i, 50.0 + i * 3);
        cout << endl;
    }

    for (int i = 0; i < 10; ++i) {
        cout << "Vytváření administrátora " << i+1 << endl;
        Administrator* admin = new Administrator(jmena[i], 300 + i, obchod);
        admin->MakeOrder(produkty, mnozstvi);
        cout << endl;
    }


    delete obchod;

    return 0;
}

#pragma endregion

