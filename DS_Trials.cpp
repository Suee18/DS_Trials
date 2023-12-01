#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
using namespace std;

class Bank
{
public:
    class Account
    {
    protected:
        int pin; /*keep it int*/

    public:
        unsigned short accountNumber = 0;
        string accounOwnerName;
        double balance = 0;
        Account* next;
        

        int getPin()
        {
            return pin;
        }//tested
        void setPin(int accPin)
        {
            pin = accPin;
        }//tested   
        double getBalance()
        {
            return balance;
        }//tested


    };

    /*BANK CLASS STARTS HERE*/

   //data membersss
    unsigned short count = 0;
    typedef Account* AccountPointer;
    AccountPointer head;
   
    //constructor
    Bank()
    {
        head = NULL;
    }

    //return number of accounts
    //Size of the Linked List
    unsigned short AccountsNum()
    {
        return count;
    }

    /*addAccount fn:
     1.creates a linked list if there is no accounts inserted and inserts it as the first acc
     2.if there is an acccount, it inserts the node in the end of the linked list*/

    void addAccount(string accounOwnerName, double balance, int pin)
    {
        Account* newAccount = new Account();
        AccountPointer ptr = head; //****enhance here 3 in read me

        //generate a random acc number
        unsigned short accnum = rand() % (65535 - 10000 - 1) + 10000;

        // Generate a new random number (to avoid repetition)
        while (AccNumSearch(accnum))
        {
            accnum = rand() % (65535 - 10000 - 1) + 10000;
        }

        newAccount->accountNumber = accnum;
        newAccount->accounOwnerName = accounOwnerName;
        newAccount->balance = balance;
        newAccount->setPin(pin);
        newAccount->next = NULL;

        if (head == NULL)
        {
            head = newAccount;
            cout << "First account created successfully!" << endl;
            cout << "Account number: " << accnum << endl;
            return;
        }


        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newAccount;

        count++; // Incrementing number of accounts: our ll size
        cout << "Account created successfully!" << endl;
        cout << "Account number: " << accnum << endl;
        
    }

    /*Search for account number not to be repeated
    Used in add acc to avoid repition*/
    bool AccNumSearch(unsigned short accountNumber) {
        AccountPointer current = head;
        while (current != nullptr) {
            if (current->accountNumber == accountNumber)
                return true;
            current = current->next;
        }
        return false;
    }//tested


    bool loginVerify(Bank* bank, string accounOwnerName, int pin) {
        AccountPointer currentPtr = bank->head;
        while (currentPtr != nullptr) {
            if (currentPtr->accounOwnerName == accounOwnerName) {
                if (currentPtr->getPin() == pin) {
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


    //need to be tested (and called in main in choice 4)
    //node: account destructor
    void deleteAccount(int accountNum) {
        AccountPointer current = head;
        AccountPointer previous = NULL;
      //Another Approach
     /*   if (current != NULL && current->accountNumber == accountNum) {
            head = current->next;
            delete current;
            return;

        }
        while (current != NULL && current->accountNumber != accountNum) {
            previous = current;
            current = current->next;
        }
        if (current == NULL) return;

        previous->next = current->next;
        delete current;
        return;*/

        while (current != NULL) {
            if (current->accountNumber == accountNum) {
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
        count--;
        return;
    }//tested


    //add money to balance
    void deposit(int accountNum, double amount) {
        AccountPointer current = head;
        while (current != NULL) {
            if (current->accountNumber == accountNum) {
                current->balance += amount;
                return;
            }
            current = current->next;
        }
    }//tested 

    //deduct money from balance
    void withdraw(int accountNum, double amount) {
        AccountPointer current = head;
        while (current != NULL) {
            if (current->accountNumber == accountNum) {
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
    }//tested

    unsigned short findAccount(const string& username, int pin) {
        AccountPointer current = head;
        while (current != nullptr) {
            if (current->accounOwnerName == username && current->getPin() == pin) {
                return current->accountNumber;
            }
            current = current->next;            
        }
        return 0;  // Return 0 if account is not found (assuming 0 is not a valid account number)
    }

    void BalanceDisplay(const string& account_holder_name)
    {
        AccountPointer current = head;

        while (current != nullptr)
        {
            if (current->accounOwnerName == account_holder_name)
            {
                cout << "Account Holder: " << current->accounOwnerName << endl;
                cout << "Account Number: " << current->accountNumber << endl;
                cout << "Balance: " << current->balance << endl;
                return;  // Exit the function once the account is found and displayed
            }

            current = current->next;
        }

        cout << "Account not found" << endl;
    }//tested

    void Write_List_into_Files(Bank*b) {
        ofstream bank("Bank.txt");
        AccountPointer ptr= b->head;
        while (ptr != NULL) {
            bank << ptr->accounOwnerName <<" " << ptr->accountNumber <<" " << ptr->balance <<" " << ptr->getPin() << endl;
            ptr = ptr->next;
            
        }
        bank.close();
    
    }//tested               

    void Read_File_into_List(Bank* b) {
   
        ifstream Bank("Bank.txt");
        b->head = NULL;
        AccountPointer current = NULL;
        string name, number, balance, pin;
        while (Bank >> name >> number >> balance >> pin) {
            Account* newNode = new Account;
            newNode->accounOwnerName = name;
            newNode->accountNumber = std::stoul(number);
            newNode->balance = std::stod(balance);
            int p = stoi(pin);
            newNode->setPin(p);
            newNode->next = nullptr;
            if (b->head == nullptr) {
                b->head = newNode;
                current = newNode;
            }
            else {
                current->next = newNode;
                current = newNode;
            }
        }
        Bank.close();
    }//tested


};


/*choice1, , count = 0, count2 = 0;*/
int pin, pin2;
double amount;
string userName;

void mainMenu(Bank& bankk, string userName, int pin) {
    Bank::Account acc;
    unsigned short choice2;
    double balance = 0;


    do
    {
        /*enters to bank main menu */
        cout << "\nPress a number for transactions:\n(1)View account details\n(2)Deposit\n(3)Withdraw\n(4)DeleteAccount\n(5)Quit\n";
        cin >> choice2;

        /*view account details*/
        if (choice2 == 1) {//done
            bankk.BalanceDisplay(userName);
            cout << "*************************************************";
        }
        /*deposit*/
        else if (choice2 == 2) {//done
            cout << "Enter the amount: ";
            cin >> amount;
            balance = acc.getBalance();
            unsigned short accN = bankk.findAccount(userName, pin);
            bankk.deposit(accN, amount);
            cout << "Updated data after the transaction:\n";
            bankk.BalanceDisplay(userName);
            cout << "*************************************************";

        }
        /*withdraw*/
        else if (choice2 == 3) {
            cout << "Enter the amount";
            cin >> amount;
            balance = acc.getBalance();
            unsigned short accN = bankk.findAccount(userName, pin);
            bankk.withdraw(accN, amount);
            cout << "Updated data after the transaction:\n";
            bankk.BalanceDisplay(userName);
            cout << "*************************************************";
        }
        /*delete account*/
        else if (choice2 == 4) {
            //delete account   by using implemented functions 
            unsigned short accN = bankk.findAccount(userName, pin);
            bankk.deleteAccount(accN);
            if (bankk.findAccount(userName, pin)==0)
                cout << "Account deleted successfully";
           // cout << bankk.findAccount(userName, pin)<<endl;

        }
        cerr << "Invalid Input";



    } while (choice2 != 5);
    bankk.Write_List_into_Files(&bankk);
    exit(0);

}

//MAIN STARTS HERER
int main()
{
   
    //A varaiable = addaccount, as it returns the acc number!!!!>>>>
    Bank bank1;
    Bank::Account acc;
    
    string s = "123.9";
    double num = stod(s);
    cout << num;
   
    unsigned short choice1, choice2 = 0, count = 0, count2 = 0;
    int pin, pin2;
    double amount;
    string userName;

    //creating accounts as data in the bank (inserting)
   /* bank1.addAccount("mohamed", 300.5, 43256);
    bank1.addAccount("modo", 30045, 43266);
    bank1.addAccount("Robbison", 65000, 15012);
    bank1.addAccount("Bataman", 723000000, 101);
    bank1.addAccount("Aliah", 15000, 32014);
    bank1.addAccount("Liam", 600000, 20041);
    bank1.addAccount("Zoe", 23000, 61400);
    bank1.Write_List_into_Files(&bank1);*/
    bank1.Read_File_into_List(&bank1);




    cout << "Press\n (1)Sign in.\t(2)Sign up.\n";
    cin >> choice1;


    /*LogIn*/
    if (choice1 == 1)
    {

        while (count < 5)
        {
            /*checking for entered username and pin*/
            cout << "Enter your name:\n";
            cin>>userName;
           // getline(cin,userName);
            cout << "Enter the pin:";
            cin >> pin;
            acc.setPin(pin);
            int pinn = acc.getPin();
            count++;

            
            if (bank1.loginVerify(&bank1, userName, pinn) == true)
            {
                mainMenu(bank1, userName, pin);

            }
            else
                cerr << "Invalid username or password. Try again\n"; /*5 times*/
        }
        if (count > 5)
        {
            cerr << "Exceeded number of Logging in mistakes";
            exit(1);
        }

    }

    /*SignUp*/
    else if (choice1 == 2)
    {

        cout << "Welcome! pleaser enter your name:";
        cin >> userName;
        cout << "Enter the  amount of money you want to keep:";
        cin >> amount;
        do
        {
            count2++;
            if (count2 > 1) {
                cerr << "you entered different pins!Try again\n";
            }
            cout << "enter your pin:";
            cin >> pin;
            cout << "enter your pin again:";
            cin >> pin2;


        } while (pin != pin2);


        bank1.addAccount(userName, amount, pin);


        mainMenu(bank1, userName, pin);


        /*call add account fn*/
      /* (****note that pin shouldn't be less that 7 digits and numbers only****)*/
    }



    //reasoning for user when he chosses a number that is not in the main menu 
    else if (choice1 != 1 || choice1 != 2)
    {
        cerr << "Invalid Input, Quitting";
        exit(1); //to flag invalid choices from the user 
    }
    
    return 0;
}
