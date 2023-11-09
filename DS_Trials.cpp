#include <iostream>
#include <string>
using namespace std;

class Account {
public:
    int account_number;
    string account_holder_name;
    double balance;
    Account* next;

    void display() {
        cout << "Account number: " << account_number << endl;
        cout << "Account holder name: " << account_holder_name << endl;
        cout << "Balance: " << balance << endl;
    }

};

class Bank {
public:
    Account* head;
    Bank() {
        head = NULL;
    }
    void add_account(int account_number, string account_holder_name, double balance) {
        Account* new_account = new Account();
        new_account->account_number = account_number;
        new_account->account_holder_name = account_holder_name;
        new_account->balance = balance;
        new_account->next = head;
        head = new_account;
    }
    void delete_account(int account_number) {
        Account* current = head;
        Account* previous = NULL;
        while (current != NULL) {
            if (current->account_number == account_number) {
                if (previous == NULL) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }
    void deposit(int account_number, double amount) {
        Account* current = head;
        while (current != NULL) {
            if (current->account_number == account_number) {
                current->balance += amount;
                return;
            }
            current = current->next;
        }
    }
    void withdraw(int account_number, double amount) {
        Account* current = head;
        while (current != NULL) {
            if (current->account_number == account_number) {
                if (current->balance >= amount) {
                    current->balance -= amount;
                }
                else {
                    cout << "Insufficient balance" << endl;
                }
                return;
            }
            current = current->next;
        }
    }
    void balance_inquiry(int account_number) {
        Account* current = head;
        while (current != NULL) {
            if (current->account_number == account_number) {
                cout << "Account holder name: " << current->account_holder_name << endl;
                cout << "Balance: " << current->balance << endl;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    Bank bank;
    bank.add_account(1, "Alice", 1000);
    bank.add_account(2, "Bob", 2000);
    bank.add_account(3, "Charlie", 3000);
    bank.deposit(1, 500);
    bank.withdraw(2, 1000);
    bank.balance_inquiry(3);
    bank.delete_account(2);
    bank.head->display();
    return 0;
}
