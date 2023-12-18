#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include<iostream>
#include<iomanip>

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
        double balance = 1;
        Account* next;
        Account()
            : next(0)
        {}
        /*Account(ElementType dataValue)
            : data(dataValue), next(0)
        {}*/
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

    unsigned short numofacc=0;
    typedef Account* AccountPointer;
    AccountPointer head;


    Bank();
    unsigned short AccountsNum();
    void addAccount(string accounOwnerName, double balance, int pin);
    bool loginVerify(Bank* bank, string accounOwnerName, int pin);
   // bool AccNumSearch(unsigned short accountNumber);
    void deleteAccount(int accountNum);
    void deposit(int accountNum, double amount);
    void withdraw(int accountNum, double amount);
    unsigned short findAccount(const string& username, int pin);
    void BalanceDisplay(const string& account_holder_name);
    void TransferMoney(unsigned short AccountNum1, unsigned short AccountNum, double Amount);
    void Write_List_into_Files();
    unsigned short Read_File_into_List();
    //unsigned short Read_File_into_ListSerializze();

   // void viewHistory(string& accounOwnerName, Bank& obj);
};



//class Bank
//{
//public:
//    class Account
//    {
//    protected:
//        int pin; /*keep it int*/
//
//    public:
//        unsigned short accountNumber = 0;
//        string accounOwnerName;
//        double balance = 0;
//        Account* next;
//
//
//        int getPin()
//        {
//            return pin;
//        }//tested
//        void setPin(int accPin)
//        {
//            pin = accPin;
//        }//tested   
//        double getBalance()
//        {
//            return balance;
//        }//tested
//
//
//    };
//
//    /*BANK CLASS STARTS HERE*/
//
//   //data membersss
//    unsigned short count = 0;
//    typedef Account* AccountPointer;
//    AccountPointer head;
//
//  
//
//
///*choice1, , count = 0, count2 = 0;*/
//int pin, pin2;
//double amount;
//string userName;
//
//void mainMenu(Bank& bankk, string userName, int pin) {
//    //Bank::Account acc;
//    unsigned short choice2;
//    double balance = 0;
//
//
//    do
//    {
//        /*enters to bank main menu */
//        cout << "\nPress a number for transactions:\n(1)View account details\n(2)Deposit\n(3)Withdraw\n(4)DeleteAccount\n (5)TransferMoney\n(6)Quit\n";
//        cin >> choice2;
//
//        /*view account details*/
//        if (choice2 == 1) {//done
//            bankk.BalanceDisplay(userName);
//            cout << "*************************************************";
//        }
//        /*deposit*/
//        else if (choice2 == 2) {//done
//            cout << "Enter the amount: ";
//            cin >> amount;
//            //balance = acc.getBalance();
//            unsigned short accN = bankk.findAccount(userName, pin);
//            bankk.deposit(accN, amount);
//            cout << "Updated data after the transaction:\n";
//            bankk.BalanceDisplay(userName);
//            cout << "*************************************************";
//
//        }
//        /*withdraw*/
//        else if (choice2 == 3) {
//            cout << "Enter the amount";
//            cin >> amount;
//            //balance = acc.getBalance();
//            unsigned short accN = bankk.findAccount(userName, pin);
//            bankk.withdraw(accN, amount);
//            cout << "Updated data after the transaction:\n";
//            bankk.BalanceDisplay(userName);
//            cout << "*************************************************";
//        }
//        /*delete account*/
//        else if (choice2 == 4) {
//            //delete account   by using implemented functions 
//            unsigned short accN = bankk.findAccount(userName, pin);
//            bankk.deleteAccount(accN);
//            if (bankk.findAccount(userName, pin) == 0)
//                cout << "Account deleted successfully";
//            // cout << bankk.findAccount(userName, pin)<<endl;
//
//        }
//        else if (choice2 == 5) {
//
//            cout << "Enter account number you want to transfer" << endl;
//            unsigned short num;
//            cin >> num;
//            cout << "Enter the Amount" << endl;
//            double Amount;
//            cin >> Amount;
//            unsigned short accN = bankk.findAccount(userName, pin);
//            bankk.TransferMoney(accN, num, Amount);
//
//
//        }
//        else  cerr << "Invalid Input";
//
//    } while (choice2 != 6);
//    bankk.Write_List_into_Files();
//    exit(0);
//
//}
//
////MAIN STARTS HERER
//int main()
//{
//
//    //A varaiable = addaccount, as it returns the acc number!!!!>>>>
//    Bank bank1;
//    Bank::Account acc;
//
//    /*string s = "123.9";
//    double num = stod(s);
//    cout << num;
//   */
//    unsigned short choice1, choice2 = 0, count = 0, count2 = 0;
//    int pin, pin2;
//    double amount;
//    string userName;
//
//    //creating accounts as data in the bank (inserting)
//   /*bank1.addAccount("mohamed", 300.5, 43256);
//    bank1.addAccount("modo", 30045, 43266);
//    bank1.addAccount("Robbison", 65000, 15012);
//    bank1.addAccount("Bataman", 723000000, 101);
//    bank1.addAccount("Aliah", 15000, 32014);
//    bank1.addAccount("Liam", 600000, 20041);
//    bank1.addAccount("Zoe", 23000, 61400);*/
//    //bank1.Write_List_into_Files();
//    bank1.Read_File_into_List();
//
//
//
//
//    cout << "Press\n (1)Sign in.\t(2)Sign up.\n";
//    cin >> choice1;
//
//
//    /*LogIn*/
//    if (choice1 == 1)
//    {
//
//        while (count < 5)
//        {
//            /*checking for entered username and pin*/
//            cout << "Enter your name:\n";
//            cin >> userName;
//            // getline(cin,userName);
//            cout << "Enter the pin:";
//            cin >> pin;
//            acc.setPin(pin);
//            int pinn = acc.getPin();
//            count++;
//
//
//            if (bank1.loginVerify(&bank1, userName, pinn) == true)
//            {
//                mainMenu(bank1, userName, pin);
//
//            }
//            else
//                cerr << "Invalid username or password. Try again\n"; /*5 times*/
//        }
//        if (count > 5)
//        {
//            cerr << "Exceeded number of Logging in mistakes";
//            exit(1);
//        }
//
//    }
//
//    /*SignUp*/
//    else if (choice1 == 2)
//    {
//
//        cout << "Welcome! pleaser enter your name:";
//        cin >> userName;
//        cout << "Enter the  amount of money you want to keep:";
//        cin >> amount;
//        do
//        {
//            count2++;
//            if (count2 > 1) {
//                cerr << "you entered different pins!Try again\n";
//            }
//            cout << "enter your pin:";
//            cin >> pin;
//            cout << "enter your pin again:";
//            cin >> pin2;
//
//
//        } while (pin != pin2);
//
//
//        bank1.addAccount(userName, amount, pin);
//
//
//        mainMenu(bank1, userName, pin);
//
//
//        /*call add account fn*/
//      /* (****note that pin shouldn't be less that 7 digits and numbers only****)*/
//    }
//
//
//
//    //reasoning for user when he chosses a number that is not in the main menu 
//    else if (choice1 != 1 || choice1 != 2)
//    {
//        cerr << "Invalid Input, Quitting";
//        exit(1); //to flag invalid choices from the user 
//    }
//
//    return 0;
//}
//
