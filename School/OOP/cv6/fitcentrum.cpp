#include <iostream>

using namespace std;

class Member
{
    private:
        string name;
        int code;

    public:
        Member(string n, int c);
        string GetName();
        int GetCode();
};

Member::Member(string n, int c)
{
    this->code = c;
    this->name = n;
}

int Member::GetCode()
{
    return this->code;
}

string Member::GetName()
{
    return this->name;
}

class Account
{
    private:
        int balance;
        int number;
        char memberClass;
        int remainingDays;

        Member* owner;

    public:
        Account(int b, int n, char mC, Member* o);
        int GetBalance();
        int GetNumber();
        string GetClass();
        int GetRemainingDays();

        Member* GetMember();

        void BuyTarif(char type);
        void DepositMoney(int amount);
        void BuyDays(int days);
};

Account::Account(int b, int n, char mC, Member* o)
{
    this->balance = b;
    this->number = n;
    this->memberClass = mC;

    this->owner = o;
}

int Account::GetBalance()
{
    return this->balance;
}

int Account::GetNumber()
{
    return this->number;
}

string Account::GetClass()
{
    switch (this->memberClass)
    {
    case ('0'):
        return "no tarif";
        break;
    case ('1'):
        return "low cost";
    case ('2'):
        return "first class";
    case ('3'):
        return "luxury class";
    }
}

int Account::GetRemainingDays()
{
    return this->remainingDays;
}

Member* Account::GetMember()
{
    return this->owner;
}

void Account::BuyTarif(char type)
{
    switch (type)
    {
    case ('1'):
        this->memberClass = 1;
        break;
    case ('2'):
        this->memberClass = 2;
        break;
    case ('3'):
        this->memberClass = 3;
        break;
    }
}

void Account::BuyDays(int days)
{
    switch (this->memberClass)
    {
    case ('1'):
        this->balance -= days * 20;
        this->remainingDays += days;
        break;
    case ('2'):
        this->balance -= days * 40;
        this->remainingDays += days;
        break;
    case ('3'):
        this->balance -= days * 80;
        this->remainingDays += days;
        break;
    }
}

void Account::DepositMoney(int n)
{
    this->balance += n;
}

class FitCentrum
{
    private:
        Member** members;
        int membersCount;

        Account** accounts;
        int accountsCount;

    public:
        FitCentrum(int m, int a);
        ~FitCentrum();

        Account* CreateAccount(int n, char c, int b, Member* owner);
        Member* CreateMember(int c, string name);
};

FitCentrum::FitCentrum(int m, int a)
{
    this->members = new Member*[m];
    this->membersCount = 0;

    this->accounts = new Account*[a];
    this->membersCount = 0;
}

FitCentrum::~FitCentrum()
{
    for(int i = 0; i < this->accountsCount; i++)
    {
        delete accounts[i];
    }   

    for(int i = 0; i < this->membersCount; i++)
    {
        delete members[i];
    }

    delete accounts;
    delete members;
}

Member* FitCentrum::CreateMember(int c, string name)
{
    Member* newMember = new Member(name, c);

    this->members[this->membersCount] = newMember;
    this->accountsCount += 1;

    return newMember;
}

Account* FitCentrum::CreateAccount(int n, char c, int b, Member* owner)
{
    Account* newAccount = new Account(n, c, b, owner);

    this->accounts[this->accountsCount] = newAccount;
    this->accountsCount += 1;

    return newAccount;
}

int main()
{
    return 0;
}