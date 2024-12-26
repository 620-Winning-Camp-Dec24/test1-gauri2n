
#include <iostream>
#include <iomanip>
using namespace std;

class Account {
protected:
    int balance;
public:
    Account(int bal) : balance(bal) {}
    virtual void calculateInterest() const = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double rate;
    int time;
public:
    SavingsAccount(int bal, double r, int t) : Account(bal), rate(r), time(t) {}
    void calculateInterest() const override {
        double interest = balance * (rate / 100) * time;
        cout << fixed << setprecision(2);
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
    int maintenanceFee;
public:
    CurrentAccount(int bal, int fee) : Account(bal), maintenanceFee(fee) {}
    void calculateInterest() const override {
        cout << "Current Account Maintenance Fee Deducted: " << maintenanceFee << endl;
        cout << "Final Balance after Fee Deduction: " << (balance - maintenanceFee) << endl;
    }
};

int main() {
    int accountType;
    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    int balance;
    cout << "Enter Account Balance: ";
    cin >> balance;

    if (accountType == 1) {
        double rate;
        int time;
        cout << "Enter Interest Rate (as percentage): ";
        cin >> rate;
        cout << "Enter Time (in years): ";
        cin >> time;

        if (balance < 1000 || balance > 1000000 || rate < 1 || rate > 15 || time < 1 || time > 10) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        SavingsAccount sa(balance, rate, time);
        sa.calculateInterest();
    } else if (accountType == 2) {
        int fee;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> fee;

        if (balance < 1000 || balance > 1000000 || fee < 50 || fee > 500) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        CurrentAccount ca(balance, fee);
        ca.calculateInterest();
    } else {
        cout << "Invalid account type." << endl;
    }

    return 0;
}