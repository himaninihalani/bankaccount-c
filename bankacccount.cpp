#include <iostream>
using namespace std;

// Base Class
class Account {
protected:
    string name;
    float balance;
public:
    Account(string n, float b) {
        name = n;
        balance = b;
    }
    virtual void display() {
        cout << "\nAccount Holder: " << name
             << "\nBalance: " << balance << endl;
    }
};

// Derived Class
class SavingsAccount : public Account {
    float interestRate;
public:
    SavingsAccount(string n, float b, float rate)
        : Account(n, b) {
        interestRate = rate;
    }

    void addInterest() {
        balance += (balance * interestRate / 100);
    }

    void display() override {
        cout << "\nSavings Account Details:";
        cout << "\nName: " << name;
        cout << "\nFinal Balance with Interest: " << balance << endl;
    }
};

// Main Function
int main() {
    string name;
    float bal, rate;

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> bal;

    cout << "Enter Interest Rate (%): ";
    cin >> rate;

    SavingsAccount s1(name, bal, rate); // Object creation
    s1.addInterest();                   // Add interest
    s1.display();                       // Show final result

    return 0;
}
