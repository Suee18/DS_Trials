#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Account {
public:
    int accountNumber;
    int pin;
    string account_holder_name;
    double balance;
    Account* next;

    void display() {
        cout << "Account number: [" << accountNumber << "]\n";
        cout << "Account holder name: [" << account_holder_name << "]\n";
        cout << "Balance: [" << balance << "]\n";
    }

};

class Bank {
public:
    Account* head;
    /*Constructor*/
    Bank() {
        head = NULL;
    }


    void add_account( string account_holder_name, double balance,int pin) {
        Account* new_account = new Account(); /*new node?*/
        /*Account number generation*/
        new_account->accountNumber = rand() % 9000000 + 1000000;
        new_account->account_holder_name = account_holder_name;
        new_account->balance = balance;
        new_account->pin = pin;
        new_account->next = head;
        head = new_account;
        cout << "account created succefully!";
    }



    bool loginVerify(Bank* bank, string account_holder_name, int pin) {
        Account* currentPtr = bank->head;
        while (currentPtr != nullptr) {
            if (currentPtr->account_holder_name == account_holder_name) {
                if (currentPtr->pin == pin) {
                    return true;
                }
                else {
                    return false;
                }
            }
            currentPtr = currentPtr->next;
        }
        return false;
    }



    void delete_account(int account_number) {
        Account* current = head;
        Account* previous = NULL;
        while (current != NULL) {
            if (current->accountNumber == account_number) {
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
            if (current->accountNumber == account_number) {
                current->balance += amount;
                return;
            }
            current = current->next;
        }
    }
    void withdraw(int account_number, double amount) {
        Account* current = head;
        while (current != NULL) {
            if (current->accountNumber == account_number) {
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
            if (current->accountNumber == account_number) {
                cout << "Account holder name: " << current->account_holder_name << endl;
                cout << "Balance: " << current->balance << endl;
                return;
            }
            current = current->next;
        }
    }
};

int main() {
    Bank user;
    short choice1,choice2,count;
    int pin;
    string userName;

    cout << "Press\n (1)Sign in.\t(2)Sign up.\n ";
    cin >> choice1;
    if (choice1 == 1) {
        /*checks for sign in info function make it boolean*/
        cout << "Enter your name";
        cin >> userName;
        cout << "Enter the pin";
        cin >> pin;

        if (user.loginVerify(&user,userName,pin)==true) 
        { /*check the pass by reference and the parameter concept!!!!*/
            /*enters to main menu #2*/ 
            cout << "Press a number for transactions:\n (1)View balance\n(2)Deposit\n(3)Withdraw\n(4)DeleteAccount\n";
            cin >> choice2;

            if (choice2 == 1) {}
            else if (choice2 == 2) {}
            else if (choice2 == 3) {}
            else if (choice2 == 4) {}
            else cerr << "Invalid Input";
            return;
        }



        else cerr << "Invalid username or password.";/*returns to log in n numbers of times*/
        count++;
        if (count >5)
            return;
        else cerr << "Exceeded number of Logging in mistakes";
    }


    else if (choice1 == 2) {
        /*call add account fn*/
      
    }
    else cerr << "Invalid input.";
    /*return to main menu*/
    











   /* Bank bank;
    bank.add_account(1, "Alice", 1000);
    bank.add_account(2, "Bob", 2000);
    bank.add_account(3, "Charlie", 3000);
    bank.deposit(1, 500);
    bank.withdraw(2, 1000);
    bank.balance_inquiry(3);
    bank.delete_account(2);
    bank.head->display();*/
    return 0;
}
