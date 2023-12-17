#include "Transactions.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
Transactions::Transactions(int accountNumber, double amount, std::string type) {
    this->accountNumber = accountNumber;
    this->amount = amount;
    this->type = type;
    time_t now = time(0);
    char str[26];
    ctime_s(str, sizeof str, &now);
    //std::cout << "The current date and time is: " << str;
   // this->date = ctime(&now);
    this->date = str;
}

int Transactions::getAccountNumber() {
    return accountNumber;
}

double Transactions::getAmount() {
    return amount;
}

std::string Transactions::getType() {
    return type;
}

std::string Transactions::getDate() {
    return date;
}

void Transactions::writeToFile() {
    ofstream file("transactions.txt", ios::app);
    file << "Account Number: " << accountNumber << ", Type: " << type << ", Amount: " << amount << ", Date: " << date << "*" << endl;
    file.close();
}
