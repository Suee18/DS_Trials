#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <string>
using namespace std;

class Bank
{

    public:
     class Account
     {
       protected:
        int pin;

       public:
        unsigned short accountNumber ;
        string accounOwnerName;
        double balance ;
        Account* next;


        int getPin();
        void setPin(int accPin);
        double getBalance();//?


    };

    
    public:
         //Bank data membersss
        unsigned short count = 0;
public:
    typedef Account* AccountPointer;
        AccountPointer head;


    Bank();
    unsigned short AccountsNum();
    void addAccount(string accounOwnerName, double balance, int pin);
    bool AccNumSearch(unsigned short accountNumber);
    bool loginVerify(Bank * bank, string accounOwnerName, int pin);
    void deleteAccount(int accountNum);
    void deposit(int accountNum, double amount);
    void withdraw(int accountNum, double amount);
    unsigned short findAccount(const string & username, int pin);
    void BalanceDisplay(const string & account_holder_name);
    void TransferMoney(unsigned short AccountNum1, unsigned short AccountNum, double Amount);
    void Write_List_into_Files();
    void Read_File_into_List();

};
