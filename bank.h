#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include <string>
#include "aes.h"
#include "modes.h"
#include "filters.h"
#include "files.h"
#include "osrng.h"
#include "hex.h"
#include <sstream>
#include "cryptlib.h"
#include "rijndael.h"
#include <sstream>

using namespace CryptoPP;
using namespace std;


using namespace std;


class Bank
{

public:
    class Account
    {
    protected:
        int pin;

    public:
        unsigned short accountNumber;
        string accounOwnerName;
        double balance;
        Account* next;
        //constructor
        Account();
        Account(const string& ownerName, unsigned short accNumber, double accBalance, int accPin);
            


        int getPin();
        void setPin(int accPin);
        double getBalance();//?


    };


public:
    //Bank data membersss
    unsigned short count = 0;
    AutoSeededRandomPool prng;  // Move prng to the class level

public:
    typedef Account* AccountPointer;
    AccountPointer head;
    // Add member variables for key and IV in your Bank class
    SecByteBlock encryptionKey;
    SecByteBlock encryptionIV;


    Bank();
    unsigned short AccountsNum();
    void addAccount(string accounOwnerName, double balance, int pin);
    bool AccNumSearch(unsigned short accountNumber);
    bool loginVerify(Bank* bank, string accounOwnerName, int pin);
    void deleteAccount(int accountNum);
    void deposit(int accountNum, double amount);
    void withdraw(int accountNum, double amount);
    unsigned short findAccount(const string& username, int pin);
    void BalanceDisplay(const string& account_holder_name);
    void TransferMoney(unsigned short AccountNum1, unsigned short AccountNum, double Amount);
    void EncryptAndWriteToFile(AutoSeededRandomPool& prng);
    void DecryptFromFile(AutoSeededRandomPool& prng) ;
};
