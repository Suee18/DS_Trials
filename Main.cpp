
#include "Bank.h"
#include "Admin.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include<iostream>
using namespace std;
/*choice1, , count = 0, count2 = 0;*/
int pin, pin2;
double amount;
string userName;

void mainMenu(Bank& bankk, string userName, int pin) {
    //Bank::Account acc;
    unsigned short choice2;
    double balance = 0;
    unsigned short accN = bankk.findAccount(userName, pin);

    do
    {
        /*enters to bank main menu */
        cout << "\nPress a number for transactions:\n(1)View account details\n(2)Deposit\n(3)Withdraw\n(4)DeleteAccount\n (5)TransferMoney\n(6)Quit\n";
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
            //balance = acc.getBalance();
            //unsigned short accN = bankk.findAccount(userName, pin);
            bankk.deposit(accN, amount);
            cout << "Updated data after the transaction:\n";
            bankk.BalanceDisplay(userName);
            cout << "*************************************************";

        }
        /*withdraw*/
        else if (choice2 == 3) {
            cout << "Enter the amount";
            cin >> amount;
            //balance = acc.getBalance();
            //unsigned short accN = bankk.findAccount(userName, pin);
            bankk.withdraw(accN, amount);
            cout << "Updated data after the transaction:\n";
            bankk.BalanceDisplay(userName);
            cout << "*************************************************";
        }
        /*delete account*/
        else if (choice2 == 4) {
            //delete account   by using implemented functions 
            //unsigned short accN = bankk.findAccount(userName, pin);
            bankk.deleteAccount(accN);
            if (bankk.findAccount(userName, pin) == 0)
                cout << "Account deleted successfully";
            // cout << bankk.findAccount(userName, pin)<<endl;

        }
        else if (choice2 == 5) {

            cout << "Enter account number you want to transfer" << endl;
            unsigned short num;
            cin >> num;
            cout << "Enter the Amount" << endl;
            double Amount;
            cin >> Amount;
            //unsigned short accN = bankk.findAccount(userName, pin);
            bankk.TransferMoney(accN, num, Amount);


        }
        else  cerr << "Invalid Input";

    } while (choice2 != 6);
    bankk.Write_List_into_Files();
    exit(0);

}
void AdminmainMenu(Admin &admin) {
    //Bank::Account acc;
    unsigned short choice2;
    double balance = 0;


    do
    {
        
        cout << "\nPress a number for transactions:\n(1)View Bank accounts\n(2)Search for Account\n (3)AddAccount\n (4)DeleteAccount\n(5)ViewTransactions\n(6)Quit\n";
        cin >> choice2;

        
        if (choice2 == 1) {
            admin.viewAccounts();
            cout << "*************************************************";
        }
      
        else if (choice2 == 2) {
            unsigned short accN ;
            cout << "Enter the Account Number: ";
            cin >> accN;
            admin.SearchAccount(accN);
            cout << "*************************************************";

        }

        else if (choice2 == 3) {
            cout << "Enter Account User Name" << endl;
            cin >> userName;
            cout << "Enter Account pin" << endl;
            cin >> pin;
            cout << "Enter Account balance" << endl;
            cin >> balance;
            admin.addAccount(userName, balance, pin);
            cout << "*************************************************";
        }
        /*delete account*/
        else if (choice2 == 4) {
            unsigned short accN;
            cout << "Enter Account Number you want to delete" << endl;
            cin >> accN;
            admin.deleteAccount(accN);
        }
        else if (choice2 == 5) {

            cout << "Under Construction" << endl;
        }
        else  cerr << "Invalid Input";

    } while (choice2 != 6);
    admin.Write_List_into_Files();
    exit(0);

}
//MAIN STARTS HERE
int main()
{

    //A varaiable = addaccount, as it returns the acc number!!!!>>>>
    Bank bank1;
    Admin admin;
    Bank::Account acc;

    /*string s = "123.9";
    double num = stod(s);
    cout << num;
   */
    unsigned short choice1 = 0, choice2 = 0, count = 0, count2 = 0;
    int pin, pin2;
    double amount;
    string userName;

    //creating accounts as data in the bank (inserting)
   /*bank1.addAccount("mohamed", 300.5, 43256);
    bank1.addAccount("modo", 30045, 43266);
    bank1.addAccount("Robbison", 65000, 15012);
    bank1.addAccount("Bataman", 723000000, 101);
    bank1.addAccount("Aliah", 15000, 32014);
    bank1.addAccount("Liam", 600000, 20041);
    bank1.addAccount("Zoe", 23000, 61400);*/
    //bank1.Write_List_into_Files();
    
    
    int x;
    string AdminName;
    cout << "Press\n(1)Admin\t(2)Customer\n";
    cin >> x;
    switch (x)
    {
    case 1:
        admin.Read_File_into_List();
        cout << "Enter your name:\n";
        cin >> AdminName;
        // getline(cin,userName);
        cout << "Enter the pin:";
        cin >> pin;
        if (AdminName == "Ashraf" && pin==111)  {
            
            AdminmainMenu(admin);
        }
        break;


    case 2 :
        bank1.Read_File_into_List();
        cout << "Press\n (1)Sign in.\t(2)Sign up.\n";
        cin >> choice1;


        /*LogIn*/
        if (choice1 == 1)
        {

            while (count < 5)
            {
                /*checking for entered username and pin*/
                cout << "Enter your name:\n";
                cin >> userName;
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



    }
    



    
    return 0;
}

