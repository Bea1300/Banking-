#include <iostream>
#include <fstream>  // For file handling
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize the bank account
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful! New Balance: $" << balance << endl;
            saveTransaction("Deposit", amount);
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful! New Balance: $" << balance << endl;
            saveTransaction("Withdraw", amount);
        } else {
            cout << "Insufficient balance or invalid withdrawal amount." << endl;
        }
    }

    // Function to check the current balance
    double getBalance() {
        return balance;
    }

    // Function to display account information
    void displayAccountInfo() {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }

    // Function to save transaction details to a file
    void saveTransaction(string type, double amount) {
        ofstream file("transaction_record.txt", ios::app);  // Open file in append mode
        if (file.is_open()) {
            file << type << " of $" << amount << " | New Balance: $" << balance << endl;
            file.close();
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }
};

// Main function to demonstrate the banking system
int main() {
    string name;
    int accNum;
    double initialDeposit;

    // Create a new bank account
    cout << "Welcome to the Bank!" << endl;
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your account number: ";
    cin >> accNum;
    cout << "Enter an initial deposit: $";
    cin >> initialDeposit;

    // Create a BankAccount object
    BankAccount account(name, accNum, initialDeposit);

    int choice;
    double amount;

    // Banking operations menu
    do {
        cout << "\nBanking Menu: \n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Display Account Info\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: $";
            cin >> amount;
            account.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: $";
            cin >> amount;
            account.withdraw(amount);
            break;
        case 3:
            cout << "Your current balance is: $" << account.getBalance() << endl;
            break;
        case 4:
            account.displayAccountInfo();
            break;
        case 5:
            cout << "Thank you for using our banking system!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
