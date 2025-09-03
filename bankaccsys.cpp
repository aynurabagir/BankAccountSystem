#include <iostream>
#include <string>
#include <vector>

using namespace std;


class BankAccount {
    private:
       
        int accountNumber;
        string holderName;
        double balance;
        vector<string> transactions;

    public:
        BankAccount(int accountNumber, const string &holderName, double initialBalance) {
            this->accountNumber = accountNumber;
            this->holderName = holderName;
            balance = initialBalance;
        }

       void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: " << amount << endl;
            transactions.push_back("Deposited: " + to_string(amount));
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
       }
       void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
            transactions.push_back("Withdrawn: " + to_string(amount));
        } else {
            cout << "Invalid or insufficient funds! " << endl;
        }
    }

    bool transferTo(BankAccount &target, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            target.deposit(amount);
            cout << "Transferred: " << amount << " to account " << target.accountNumber << endl;
            transactions.push_back("Transferred: " + to_string(amount) + " to account " + to_string(target.accountNumber));
            return true;
        } else {
            cout << "Invalid or insufficient funds for transfer!" << endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }
    void displayAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: " << balance << endl;
    }
    void showTransactions() const {
        cout << "Transaction History for Account " << accountNumber << ":" << endl;
        if (transactions.empty()) {
            cout << "No transactions found." << endl;
        } else {
            for (const string &t : transactions) {
                cout << t << endl;
            }
        }
    }
};



int main() {
    BankAccount acc1(1001, "Alice", 1000.0);
    BankAccount acc2(1002, "Bob", 500.0);

    int choice;
    double amount;

    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Display Account 1\n";
        cout << "2. Display Account 2\n";
        cout << "3. Deposit to Account 1\n";
        cout << "4. Withdraw from Account 1\n";
        cout << "5. Transfer from Account 1 to Account 2\n";
        cout << "6. Show Transactions of Account 1\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                acc1.displayAccount();
                break;
            case 2:
                acc2.displayAccount();
                break;
            case 3:
                cout << "Enter amount to deposit to Account 1: ";
                cin >> amount;
                acc1.deposit(amount);
                break;
            case 4:
                cout << "Enter amount to withdraw from Account 1: ";
                cin >> amount;
                acc1.withdraw(amount);
                break;
            case 5:
                cout << "Enter amount to transfer from Account 1 to Account 2: ";
                cin >> amount;
                acc1.transferTo(acc2, amount);
                break;
            case 6:
                acc1.showTransactions();
                break;
            case 7:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}