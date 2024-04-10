#include <iostream>
#include <string>

using namespace std;

class KeyValue
{
    private:
        int key;
        double value;

    public:
        KeyValue(int k, double v);
        int GetKey();
        double GetValue();
};

class KeyValues
{
    private:
        int count;
        KeyValue** keyValues;
    public:
        KeyValues(int n);
        ~KeyValues();
        KeyValue* CreateObject(int k, double v);
        KeyValue* SearchObject(int key);
        KeyValue* RemoveObject(int key);
        KeyValue** ReturnList();
        int Count();
};

KeyValue::KeyValue(int k, double v)
{
    this->value = v;
    this->key = k;
}

int KeyValue::GetKey()
{
    return this->key;
}

double KeyValue::GetValue()
{
    return this->value;
}

KeyValues::KeyValues(int n)
{
    this->keyValues = new KeyValue*[n];
    this->count = 0;
}

KeyValues::~KeyValues()
{
    for(int i = 0; i < this->count; i++)
    {
        delete this->keyValues[i];
    }

    delete[] this->keyValues;
}

int KeyValues::Count()
{
    return this->count;
}

KeyValue* KeyValues::CreateObject(int k, double v)
{   
    KeyValue *newObject = new KeyValue(k, v);

    this->keyValues[this->count] = newObject;
    this->count += 1;

    return newObject;
}

KeyValue* KeyValues::SearchObject(int k)
{
    for(int i = 0; i < this->count; i++)
    {
        if(this->keyValues[i]->GetKey() == k)
        {
            return this->keyValues[i];
        }
    }

    return nullptr;
}

KeyValue* KeyValues::RemoveObject(int k)
{
    KeyValue* searchedObject = SearchObject(k);
    KeyValue* lastObject = SearchObject(count - 1);
    int a = lastObject->GetKey();
    double b = lastObject->GetValue();
    if(searchedObject != nullptr)
    {
        int index = -1;
        for(int i = 0; i < count; i++)
        {
            if(keyValues[i] == searchedObject)
            {
                index = i;
                break;
            }
        }
        
        delete searchedObject;
        delete lastObject;
        KeyValue* newObject1 = new KeyValue(a, b);
        this->keyValues[index] = newObject1;
        count -= 1;
        return searchedObject;
    }   

    return nullptr;
}

KeyValue** KeyValues::ReturnList()
{
    return this->keyValues;
}




class Osoba
{
    private:
        string name;
        string adress;
    public:
        Osoba(string n, string a);
        string GetName();
        string GetAdress();
};

Osoba::Osoba(string n, string a)
{
    this->name = n;
    this->adress = a;
}

string Osoba::GetName()
{
    return this->name;
}

string Osoba::GetAdress()
{
    return this->adress;
}

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

class Faktura
{
    private:
        int num;
        int countFiles;

        Osoba* osoba;
        PolozkaFaktury** polozkaFaktury;
    public:
        Faktura(int b);
        ~Faktura();
        void CreateFaktura(string n, string a, int p, string t);
        void AddFile(int p, string t);
        int SumValues();
};

Faktura::Faktura(int b)
{
    this->num = 0;
    this->countFiles = 0;
    this->osoba = nullptr;

    this->polozkaFaktury = new PolozkaFaktury*[b];
}

Faktura::~Faktura()
{
    delete[] polozkaFaktury;
}

void Faktura::CreateFaktura(string n, string a, int p, string t)
{
    Osoba *newOsoba = new Osoba(n, a);
    this->osoba = newOsoba;
    this->num += 1;
    
    PolozkaFaktury *newPolozka = new PolozkaFaktury(p, t);
    this->polozkaFaktury[this->countFiles] = newPolozka;
    this->countFiles += 1;
}

void Faktura::AddFile(int p, string t)
{
    PolozkaFaktury *newPolozka = new PolozkaFaktury(p, t);
    this->polozkaFaktury[this->countFiles] = newPolozka;
    this->countFiles += 1;
}

int Faktura::SumValues()
{
    int sum = 0;

    for(int i = 0; i < this->countFiles; i++)
    {
        sum += this->polozkaFaktury[i]->GetPrice();
    }

    return sum;
}

int main()
{
    int N = 5;
    KeyValues* myKeyValues = new KeyValues(N); 

    for(int i = 0; i < N; i++)
    {
        myKeyValues->CreateObject(i, i + 0.5);
    }


    myKeyValues->RemoveObject(2);

    KeyValue** list = myKeyValues->ReturnList();

    for(int i = 0; i < myKeyValues->Count(); i++)
    {
        cout << list[i]->GetKey()<< endl;
        cout << list[i]->GetValue()<< endl;
    }

    Faktura faktura(1);
    faktura.CreateFaktura("Jakub", "Praha", 200, "Auto");
    faktura.AddFile(2500, "Telefon");
    faktura.AddFile(25210, "domov");

    cout << faktura.SumValues()<< " Kč" << endl;

    return 0;
}