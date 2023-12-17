#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include<iostream>

using namespace std;

class Bank
{
public:
    class Account
    {
    protected:
        int pin; /*keep it int*/

    public:
        //bad initialization
        unsigned short accountNumber = 0;
        string accounOwnerName;
        double balance = 0;
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
        void setPin(int accPin) {
            /*unsigned short count = 0;
            int num = accPin;
            bool four = true;
            while (num != 0&&four==true) {
                num = num / 10;
                count++;
                if (count == 4) {
                    this->pin = num;
                    four = false;
                    return;
                }
                else {
                    cerr << "enter 4 digits" << endl;
                    count = 0;
                    cout << "enter the pin again:";
                    cin >> num;
                    return;
                }
            }*/
            this->pin = accPin;
           
            
           
           
           /* this->pin = accPin;*/
        }
        
        
        //tested   
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

   
    Bank();
    unsigned short AccountsNum();
    void addAccount(string accounOwnerName, double balance, int pin);
    bool loginVerify(Bank* bank, string accounOwnerName, int pin);
    bool AccNumSearch(unsigned short accountNumber);
    void deleteAccount(int accountNum);
    void deposit(int accountNum, double amount);
    void withdraw(int accountNum, double amount);
    unsigned short findAccount(const string username, int pin);
    void BalanceDisplay(const string account_holder_name);
    void TransferMoney(unsigned short AccountNum1, unsigned short AccountNum, double Amount);
     void Write_List_into_Files();
    void Read_File_into_List();
    int encryptPin(int pin);
    int decryptPin(int encryptedPin);
};
