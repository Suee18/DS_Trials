#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Bank {
    public:
    class Account {
        protected:
        int pin; /*keep it int*/

         public:
        unsigned short accountNumber=0;
        string account_holder_name;
        double balance=0;
        Account* next;
        
         int getPin() {
             return pin;
         }
         void setPin(int accPin) {
             pin = accPin;
         }

      /*  void display() {
            cout << "Account number: [" << accountNumber << "]\n";
            cout << "Account holder name: [" << account_holder_name << "]\n";
            cout << "Balance: [" << balance << "]\n";
        }*/

    };



    /*BANK CLASS*/



    Account* head;
    /*Constructor*/
    Bank() {
        head = NULL;
    }


    
    unsigned short add_account(string account_holder_name, double balance, int pin) {
        Account* new_account = new Account();
        new_account->accountNumber = rand() % (65535 - 10000 - 1) + 10000;
        new_account->account_holder_name = account_holder_name;
        new_account->balance = balance;
        new_account->setPin(pin);
        new_account->next = head;
        head = new_account;
        cout << "Account created successfully!" << endl;
        return new_account->accountNumber; /*too keep it in balance display*/
    }




    bool loginVerify(Bank* bank, string account_holder_name, int pin) {
        Account* currentPtr = bank->head;
        while (currentPtr != nullptr) {
            if (currentPtr->account_holder_name == account_holder_name) {
                if (currentPtr->  getPin() == pin) {
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



    Account* findAccount(const string& username, int pin) {
        Account* current = head;
        while (current != nullptr) {
            if (current->account_holder_name == username && current->getPin() == pin) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }



    void BalanceDisplay(Account* account) 
    {
        if (account != nullptr)
        {
            cout << "Account Holder: " << account->account_holder_name << endl;
            cout << "Account Number: " << account->accountNumber << endl;
            cout << "Balance: " << account->balance <<endl;
        }
        else  cout << "Account not found" << endl;
    }

};

int main() {

    Bank bank1;
    Bank::Account acc;
    Bank::Account* loggedInAccount = nullptr;

    unsigned short choice1, choice2, count = 0;
    int pin;
    string userName;

    //creating accounts as data in the bank (inserting)
    bank1.add_account("Claire", 1000000, 13033);
    bank1.add_account("Robbison", 65000, 15012);
    bank1.add_account("Mark", 7230000, 58012);
     bank1.add_account("Aliah", 15000, 32014);
     bank1.add_account("Liam", 600000, 20041);
    bank1.add_account("Zoe", 23000, 61400);





    cout << "Press\n (1)Sign in.\t(2)Sign up.\n ";
    cin >> choice1;


    if (choice1 == 1) {
        /*checks for sign in info function make it boolean*/
        while (count < 5) {
            cout << "Enter your name:";
            cin >> userName;
            cout << "\nEnter the pin:";
            cin >> pin;
            acc.setPin(pin); // Set the pin
            int pinn = acc.getPin(); // Get the pin
            loggedInAccount = bank1.findAccount(userName, pin);
            count++;

            if (bank1.loginVerify(&bank1, userName, pinn) == true)
            { /*check the pass by reference and the parameter concept!!!!*/
                /*enters to main menu #2*/
                cout << "Press a number for transactions:\n(1)View balance\n(2)Deposit\n(3)Withdraw\n(4)DeleteAccount\n";
                cin >> choice2;

                if (choice2 == 1) {
                    bank1.BalanceDisplay(loggedInAccount);

                }
                else if (choice2 == 2) {}
                else if (choice2 == 3) {}
                else if (choice2 == 4) {}
                else cerr << "Invalid Input";
                break;

            }
            cerr << "Invalid username or password. Try again\n"; /*5 times*/
          

        }
        if (count > 5) {
            cerr << "Exceeded number of Logging in mistakes";
            exit(1);
        }
       
 
    }


    else if (choice1 == 2) {
        /*call add account fn*/
      /* (****note that pin shouldn't be less that 7 digits and numbers only****)*/
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
