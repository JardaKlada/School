#include <iostream>

using namespace std;


#pragma region Client
class Client
{
    private: 
        int code;
        string name;

    public:
        Client(int c, string n);

        int GetCode();
        string GetName();
};

Client::Client(int c, string n)
{
    this->code = c;
    this->name = n;
}

int Client::GetCode()
{
    return this->code;
}

string Client::GetName()
{
    return this->name;
}

#pragma endregion 

#pragma region Transakce


class Transakce
{
    private:
        double value;
        char subject;
        Client* person2;

    public:
        Transakce(double v, char s);
        Transakce(double v, char s, Client* p2);
        double GetValue();
        char GetSubjectChar();
        string GetSubject();
        Client* GetPerson2();
};

Transakce::Transakce(double v, char s)
{
    this->value = v;
    this->subject = s;
}

Transakce::Transakce(double v, char s, Client* p2)
{
    this->value = v;
    this->subject = s;
    this->person2 = p2;
}

double Transakce::GetValue()
{
    return this->value;
}

char Transakce::GetSubjectChar()
{
    return this->subject;
}

string Transakce::GetSubject()
{
    switch(this->subject)
    {
        case('d'):
        {
            return " vložil na účet: ";
        }
        case('w'):
        {
            return " vybral z účtu: ";
        }
        case('s'):
        {
            return " poslal klientovi jménem: ";
        }
        case('r'):
        {
            return " dostal od klienta jménem: ";
        }
    }
    return nullptr;
}

Client* Transakce::GetPerson2()
{
    return this->person2;
}

#pragma endregion 

#pragma region Account
class Account
{
    private:
        int number;
        double balance;
        double interestRate;

        Client *owner;
        Client *partner;  

        Transakce** transactions;
        int transactionsCount;

    public:
        Account(int n, Client *c);
        Account(int n, Client *c, double ir);
        Account(int n, Client *c, Client *p);
        Account(int n, Client *c, Client *p, double ir);
        ~Account();

        int GetNumber();
        int GetTransactionsCount();
        double GetBalance();
        double GetInterestRate();
        Client* GetOwner();
        Client* GetPartner();
        Transakce** GetHistoryOfTransactions();
        bool CanWithdraw(double a);

        void Deposit(double a);
        bool Withdraw(double a);
        void SendMoney(double a, Client* poslal);
        void ReceiveMoney(double a, Client* dostal);
        void AddInterest();
};

Account::Account(int n, Client *c)
{
    this->number = n;
    this->balance = 0;
    this->interestRate = 0;

    this->owner = c;
    this->partner = nullptr;

    this->transactions = new Transakce*[n];
    this->transactionsCount = 0; 
}

Account::Account(int n, Client *c, double ir)
{
    this->number = n;
    this->balance = 0;
    this->interestRate = ir;

    this->owner = c;
    this->partner = nullptr;

    this->transactions = new Transakce*[n];
    this->transactionsCount = 0; 
}

Account::Account(int n, Client *c, Client *p)
{
    this->number = n;
    this->balance = 0;
    this->interestRate = 0;

    this->owner = c;
    this->partner = p;

    this->transactions = new Transakce*[n];
    this->transactionsCount = 0; 
}

Account::Account(int n, Client *c, Client *p, double ir)
{
    this->number = n;
    this->balance = 0;
    this->interestRate = ir;

    this->owner = c;
    this->partner = p;

    this->transactions = new Transakce*[n];
    this->transactionsCount = 0; 
}

int Account::GetNumber()
{
    return this->number;
}

double Account::GetBalance()
{
    return this->balance;
}

double Account::GetInterestRate()
{
    return this->interestRate;
}

Client* Account::GetOwner()
{
    return this->owner;
}

Client* Account::GetPartner()
{
    return this->partner;
}

Transakce** Account::GetHistoryOfTransactions()
{
    return this->transactions;
}

int Account::GetTransactionsCount()
{
    return this->transactionsCount;
}

bool Account::CanWithdraw(double a)
{
    return (this->balance > a);
}

void Account::Deposit(double a)
{
    this->balance += a;

    Transakce *newTransaction = new Transakce(a, 'd'); 
    this->transactions[this->transactionsCount] = newTransaction;
    this->transactionsCount += 1;
}

void Account::SendMoney(double a, Client* dostal)
{
    this->balance += a;

    Transakce *newTransaction = new Transakce(a, 's', dostal);
    this->transactions[this->transactionsCount] = newTransaction;
    this->transactionsCount += 1;
}

void Account::ReceiveMoney(double a, Client* poslal)
{
    this->balance += a;

    Transakce *newTransaction = new Transakce(a, 'r', poslal);
    this->transactions[this->transactionsCount] = newTransaction;
    this->transactionsCount += 1;
}

bool Account::Withdraw(double a)
{
    if(CanWithdraw(a))
    {
        this->balance -= a;
        Transakce *newTransaction = new Transakce(a, 'w'); 
        this->transactions[this->transactionsCount] = newTransaction;
        this->transactionsCount += 1;

        return true;
    }
    return false;
}

void Account::AddInterest()
{
    this->balance = balance + balance*this->interestRate;    
}

#pragma endregion

#pragma region Bank
class Bank
{
    private:
        Client** clients;
        int clientsCount;

        Account** accounts;
        int accountsCount;

    public:
        Bank(int c, int a, int i);
        ~Bank();

        Client* GetClient(int c);
        Account* GetAccount(int a);
        Transakce* GetHistoryOfTransactions(int i);

        Client* CreateClient(int c, string n);
        Account* CreateAccount(int n, Client *c);
        Account* CreateAccount(int n, Client *c, double ir);
        Account* CreateAccount(int n, Client *c, Client *p);
        Account* CreateAccount(int n, Client *c, Client *p, double ir);

        void AddInterest();
        bool MakeTransaction(double amount, int s, int r);
};

Bank::Bank(int c, int a, int i)
{
    this->clients = new Client*[c];
    this->clientsCount = 0;

    this->accounts = new Account*[a];
    this->accountsCount = 0;
}

Bank::~Bank()
{
    // for(int i = 0; i < accountsCount; i++)
    // {
    //     if(accounts[i] != nullptr)
    //     {
    //         delete accounts[i];
    //     }
    // }
    // for(int i = 0; i < clientsCount; i++)
    // {
    //     if(accounts[i] != nullptr)
    //     {
    //         delete clients[i];
    //     } 
    // }
    // delete[] accounts;
    // delete[] clients;
}

Client* Bank::GetClient(int c)
{
    for(int i = 0; i < this->clientsCount; i++)
    {
        if(this->clients[i]->GetCode() == c)
        {
            return this->clients[i];
        }
    }

    return nullptr;
}

Account* Bank::GetAccount(int a)
{
    for(int i = 0; i < this->accountsCount; i++)
    {
        if(this->accounts[i]->GetNumber() == a)
        {
            return this->accounts[i];
        }
    }

    return nullptr;
}


Client* Bank::CreateClient(int c, string n)
{
    Client *newClient = new Client(c, n);

    this->clients[this->clientsCount] = newClient;
    clientsCount += 1;

    return newClient;
}

Account* Bank::CreateAccount(int a, Client *c)
{
    Account *newAccount = new Account(a, c);

    this->accounts[this->accountsCount] = newAccount;
    accountsCount += 1;

    return newAccount;
}

Account* Bank::CreateAccount(int a, Client *c, double ir)
{
    Account *newAccount = new Account(a, c, ir);

    this->accounts[this->accountsCount] = newAccount;
    accountsCount += 1;

    return newAccount;
}

Account* Bank::CreateAccount(int a, Client *c, Client *p)
{
    Account *newAccount = new Account(a, c, p);

    this->accounts[this->accountsCount] = newAccount;
    accountsCount += 1;

    return newAccount;
}

Account* Bank::CreateAccount(int a, Client *c, Client *p, double ir)
{
    Account *newAccount = new Account(a, c, p, ir);

    this->accounts[this->accountsCount] = newAccount;
    accountsCount += 1;

    return newAccount;
}

void Bank::AddInterest()
{
    for(int i = 0; i < accountsCount; i++)
    {
        accounts[i]->AddInterest();
    }
}

bool Bank::MakeTransaction(double amount, int s, int r)
{
    if(this->accounts[s]->CanWithdraw(amount))
    {
        Client* poslal = accounts[s]->GetOwner();
        Client* dostal = accounts[r]->GetOwner();
        this->accounts[s]->SendMoney(amount, dostal);
        this->accounts[r]->ReceiveMoney(amount, poslal);
        return true;
    }
    return false;
}

#pragma endregion


int main()
{
    int clientLimit = 10;
    int accountLimit = 10;
    int transactionsLimit = 20;
    string nameList[] = {"Jakub", "Petr", "Karel", "Honza", "Milan", "Lukáš", "Ladislav", "Vladimír", "Michal", "Vašek"};

    Bank *newBank = new Bank(clientLimit, accountLimit, transactionsLimit);

    for(int i = 0; i < clientLimit; i++)
    {
        newBank->CreateClient(i, nameList[i]);
    }

    for(int i = 0; i < accountLimit; i++)
    {
        newBank->CreateAccount(i, newBank->GetClient(i));
    }

    for(int i = 0; i < accountLimit; i++)
    {
        newBank->GetAccount(i)->Deposit(i * 200 + 2000);
        
    }

    for(int i = 0; i < clientLimit; i++)
    {
        cout << "Vlastník účtu: " << newBank->GetClient(i)->GetName() 
        << ", zůstatek na účtu: " << newBank->GetAccount(i)->GetBalance() << endl;
    }
    int sender = 1;
    int receiver = 2;
    int amount = 500;

    if(newBank->MakeTransaction(amount, sender, receiver))
    {
        cout << "Transakce proběhla úspěšně " << newBank->GetClient(sender)->GetName() << " poslal: " << amount << " klientovi jménem: " << newBank->GetClient(receiver)->GetName() << endl; 
    } else{
        cout << "Transakce neproběhla" << endl;
    }

    newBank->MakeTransaction(499, 1, 4);
    newBank->MakeTransaction(350, 5, 1);
    newBank->MakeTransaction(200, 6, 1);

    // char ass[100];

    // sprintf(ass);

    Transakce** history = newBank->GetAccount(1)->GetHistoryOfTransactions();

    cout << "Toto je historie: " << endl;

    for(int i = 0; i < newBank->GetAccount(1)->GetTransactionsCount(); i++)
    {
        if(history[i]->GetSubjectChar() == 's' || history[i]->GetSubjectChar() == 'r')
        {
            cout << newBank->GetAccount(1)->GetOwner()->GetName() << history[i]->GetSubject() << history[i]->GetValue() << "Kč " << history[i]->GetPerson2()->GetName() << endl;            
        } else
        {
            cout << newBank->GetAccount(1)->GetOwner()->GetName() << history[i]->GetSubject() << history[i]->GetValue() << "Kč " << endl;
        }

    }

    delete newBank;
}