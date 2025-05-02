#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction
{
public:
    string type;
    double amount;

    Transaction(string type, double amount)
    {
        this->type = type;
        this->amount = amount;
    }

    void display()
    {
        cout << type << ": " << amount << endl;
    }
};

class Account
{
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo)
    {
        accountNumber = accNo;
        balance = 0.0;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }

    void deposit(double amount)
    {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
        cout << "Deposit successful." << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            transactions.push_back(Transaction("Withdraw", amount));
            cout << "Withdrawal successful." << endl;
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayTransactions()
    {
        cout << "Transactions for Account " << accountNumber << ":\n";
        for (Transaction &t : transactions)
        {
            t.display();
        }
    }
};

class Customer
{
private:
    string name;
    int customerID;
    vector<Account> accounts;

public:
    Customer(string name, int id)
    {
        this->name = name;
        customerID = id;
    }

    int getCustomerID()
    {
        return customerID;
    }

    void addAccount(Account acc)
    {
        accounts.push_back(acc);
    }

    Account *getAccount(int accNo)
    {
        for (auto &acc : accounts)
        {
            if (acc.getAccountNumber() == accNo)
                return &acc;
        }
        return nullptr;
    }

    void displayInfo()
    {
        cout << "Customer: " << name << ", ID: " << customerID << "\n";
        for (Account &acc : accounts)
        {
            cout << "Account No: " << acc.getAccountNumber() << ", Balance: " << acc.getBalance() << "\n";
        }
    }
};

class Bank
{
private:
    vector<Customer> customers;

public:
    void addCustomer(string name, int id)
    {
        customers.push_back(Customer(name, id));
    }

    Customer *getCustomer(int id)
    {
        for (auto &cust : customers)
        {
            if (cust.getCustomerID() == id)
                return &cust;
        }
        return nullptr;
    }

    void transfer(int fromAcc, int toAcc, double amount)
    {
        Account *sender = nullptr, *receiver = nullptr;

        for (auto &cust : customers)
        {
            if (!sender)
                sender = cust.getAccount(fromAcc);
            if (!receiver)
                receiver = cust.getAccount(toAcc);
        }

        if (sender && receiver && sender->getBalance() >= amount)
        {
            sender->withdraw(amount);
            receiver->deposit(amount);
            cout << "Transfer successful.\n";
        }
        else
        {
            cout << "Transfer failed.\n";
        }
    }
};

int main()
{
    Bank bank;

    bank.addCustomer("Alice", 1);
    bank.addCustomer("Bob", 2);

    Customer *alice = bank.getCustomer(1);
    Customer *bob = bank.getCustomer(2);

    alice->addAccount(Account(1001));
    bob->addAccount(Account(2001));

    Account *aliceAcc = alice->getAccount(1001);
    Account *bobAcc = bob->getAccount(2001);

    aliceAcc->deposit(5000);
    aliceAcc->withdraw(1000);
    bobAcc->deposit(2000);

    bank.transfer(1001, 2001, 500);

    cout << "\n--- Account Info ---\n";
    alice->displayInfo();
    bob->displayInfo();

    cout << "\n--- Transactions ---\n";
    aliceAcc->displayTransactions();
    bobAcc->displayTransactions();

    return 0;
}
