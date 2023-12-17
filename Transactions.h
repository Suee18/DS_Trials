#pragma once
//class Transactions
//{
//
//
//
//};
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
using namespace std;
class Transactions {
public:
    Transactions(int accountNumber, double amount, string type);

    int getAccountNumber();
    double getAmount();
    string getType();
    string getDate();

    void writeToFile();

private:
    int accountNumber;
    double amount;
    string type;
    string date;
};

#endif


