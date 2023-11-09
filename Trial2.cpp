#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
using namespace std;

class Bank {
public:
    class Account {
    public:
        unsigned short accountNumber;
        unsigned short pin;
        string account_holder_name;
        float balance;
        Account* next;

        void display() {
            cout << "Account number: [" << accountNumber << "]\n";
            cout << "Account holder name: [" << account_holder_name << "]\n";
            cout << "Balance: [" << balance << "]\n";
        }
    Account* head;

    /Constructor/
    Bank() {
        head = NULL;
    }

    //Add new account
    void add_account( string account_holder_name, float balance,short pin) {
        Account* new_account = new Account(); /new node?/
        /Account number generation/
        new_account->accountNumber = rand() % 65535 + 10000;
        new_account->account_holder_name = account_holder_name;
        new_account->balance = balance;
        new_account->pin = pin;
        new_account->next = head;
        head = new_account;
        cout << "account created succefully!";
    }



    bool loginVerify(Bank* bank, string account_holder_name, short pin) {
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



    void delete_account(unsigned short account_number) {
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
    void deposit(unsigned short account_number, float amount) {
        Account* current = head;
        while (current != NULL) {
            if (current->accountNumber == account_number) {
                current->balance += amount;
                cout << amount + " has been added to your balance succesfully..."<<endl;
                cout << "Balance= " + current->balance<<endl;
                return;
            }
            current = current->next;
        }
        cerr << "cant find the account" << endl;
    }
    void withdraw(unsigned short account_number, float amount) {
        Account* current = head;
        while (current != NULL) {
            if (current->accountNumber == account_number) {
                if (current->balance >= amount) {
                    current->balance -= amount;
                    return;
                }
                cerr << "Cant find the account" << endl;
            }
            current = current->next;
        }
    }
    void balance_inquiry(unsigned short account_number) {
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
    Bank bank1;
    unsigned short choice1,choice2,count;
    unsigned short pin;
    double amoAccount; //keep it double
    string userName;

    //creating accounts as data in the bank (inserting)
    bank1.add_account(Claire, 1000000, 13033);
    bank1.add_account(Robbison, 65000, 15012);
    bank1.add_account(Mark, 7230000, 58012);
    bank1.add_account(Aliah, 15000, 32014);
    bank1.add_account(Liam, 600000, 20041);
    bank1.add_account(Zoe, 23000, 61400);



    cout << "Press\n (1)Sign in.\t(2)Sign up.\n ";
    cin >> choice1;
    if (choice1 == 1) {
        /checks for sign in info function make it boolean/
        cout << "Enter your name";
        cin >> userName;
        cout << "Enter the pin";
        cin >> pin;

        if (bank1.loginVerify(&bank1,userName,pin)==true) 
        { /check the pass by reference and the parameter concept!!!!/
            /enters to main menu #2/ 
            cout << "Press a number for transactions:\n (1)View balance\n(2)Deposit\n(3)Withdraw\n(4)DeleteAccount\n";
            cin >> choice2;

            if (choice2 == 1) {
                //display for that account
            }
            else if (choice2 == 2) {
            cout<<"enter the amount to deposit in balance";
            cin>>amount;

            }
            else if (choice2 == 3) {}
            else if (choice2 == 4) {}
            else cerr << "Invalid Input";
            return;
        }



        else cerr << "Invalid username or password.";/returns to log in n numbers of times/
        count++;
        if (count >5)
            return;
        else cerr << "Exceeded number of Logging in mistakes";
    }


    else if (choice1 == 2) {
        /call add account fn/
      
    }
    else cerr << "Invalid input.";
    /return to main menu/
    


   

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
