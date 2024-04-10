#include <iostream>

using namespace std;

class KeyValue
{
    private:
        int key;
        double value;
        KeyValue *next;

    public:
        KeyValue(int k, double v);
        ~KeyValue();
        int GetKey();
        double GetValue();
        KeyValue* GetNext();
        KeyValue* CreateNext(int k, double v);
};

class StringF
{
    private:
        string pero;
        StringF* left;
        StringF* right;

    public:
        StringF(string p);
        ~StringF();        
        string GetString();
        StringF* GetRight();
        StringF* GetLeft();
        StringF* CreateRight(string p);
        StringF* CreateLeft(string p);
};

StringF::StringF(string p)
{
    this->pero = p;
    this->left = nullptr;
    this->right = nullptr;
}

string StringF::GetString()
{
    return this->pero;
}

StringF* StringF::CreateLeft(string p)
{   
    this-> left = new StringF(p);
    return this->left;
}

StringF* StringF::CreateRight(string p)
{
    this->right = new StringF(p);
    return this->right;
}

StringF* StringF::GetLeft()
{
    return this->left;
}

StringF* StringF::GetRight()
{
    return this->right;
}

StringF::~StringF()
{
    if(left != nullptr){
        delete left;
    }

    if(right != nullptr){
        delete right;
    }
}

KeyValue::KeyValue(int k, double v)
{
    this->value = v;
    this->key = k;
    this->next = nullptr;
}

int KeyValue::GetKey()
{
    return this->key;
}

double KeyValue::GetValue()
{
    return this->value;
}

KeyValue::~KeyValue()
{
    if(this != nullptr)
    {
        delete this->next;
        next = nullptr;
    }
}

KeyValue* KeyValue::GetNext()
{
    return this->next;
}

KeyValue* KeyValue::CreateNext(int k, double v)
{
    this->next = new KeyValue(k, v);
    return this->next;
}

int main()
{
    KeyValue *kv1 = new KeyValue(1, 1.5);
    cout << kv1->CreateNext(2, 2.5)->GetKey() <<endl;

    KeyValue *kv2 = kv1->GetNext();
    cout << kv2->GetNext() << "tady" << endl;
    
    KeyValue *temp = kv1->GetNext();

    for(int i = 0; i < 1000; i++){        
        temp->CreateNext(i, i + 0.5);
        //KeyValue *temp1 = temp->GetNext();
        //temp = temp1;
        temp = temp->GetNext();
        cout << temp->GetKey() << endl;
    }

    delete kv1;
    kv2 = nullptr;
    kv1 = nullptr;

    StringF *string1 = new StringF("Penis");
    cout << string1->CreateLeft("Pero")->GetString() << string1->GetString() << " " << " " << string1->CreateRight("Pele")->GetString() << endl; 

    delete string1;
    string1 = nullptr;

    getchar();
    return 0;
}