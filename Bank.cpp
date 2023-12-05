#include "Bank.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include<iostream>
using namespace std;
//constructor
Bank::Bank()
{
    head = NULL;
}

//return number of accounts
//Size of the Linked List
unsigned short Bank::AccountsNum()
{
    return count;
}

/*addAccount fn:
 1.creates a linked list if there is no accounts inserted and inserts it as the first acc
 2.if there is an acccount, it inserts the node in the end of the linked list*/

void Bank::addAccount(string accounOwnerName, double balance, int pin)
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
bool Bank::AccNumSearch(unsigned short accountNumber) {
    AccountPointer current = head;
    while (current != nullptr) {
        if (current->accountNumber == accountNumber)
            return true;
        current = current->next;
    }
    return false;
}//tested


bool Bank::loginVerify(Bank* bank, string accounOwnerName, int pin) {
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
void Bank::deleteAccount(int accountNum) {
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
void Bank::deposit(int accountNum, double amount) {
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
void Bank::withdraw(int accountNum, double amount) {
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

unsigned short Bank::findAccount(const string& username, int pin) {
    AccountPointer current = head;
    while (current != nullptr) {
        if (current->accounOwnerName == username && current->getPin() == pin) {
            return current->accountNumber;
        }
        current = current->next;
    }
    return 0;  // Return 0 if account is not found (assuming 0 is not a valid account number)
}

void Bank::BalanceDisplay(const string& account_holder_name)
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

void Bank::TransferMoney(unsigned short AccountNum1, unsigned short AccountNum, double Amount) {
    AccountPointer ptr = head, ptr1 = head;
    double balance1=0;
    while (ptr1 != NULL) {
        if (ptr1->accountNumber == AccountNum1) {
            balance1 = ptr1->balance;
            break;
        }
        ptr1 = ptr1->next;
    }


    while (ptr != NULL)
    {
        if (ptr->accountNumber == AccountNum)
        {
            if (Amount <= balance1)
            {
                withdraw(AccountNum1, Amount);
                deposit(AccountNum, Amount);
                //ptr->accountNumber += Amount;
                //acc->accountNumber -= Amount;
                cout << "Money Transfered Successfully" << endl;
                return;
            }
            else if (Amount > balance1) {
                cout << "No enough Money to Transfer" << endl;
            }
        }

        ptr = ptr->next;
    }

    return;

}

void Bank::Write_List_into_Files() {
    ofstream bank("Bank.txt");
    AccountPointer ptr = head;

    while (ptr != NULL) {
        bank << ptr->accounOwnerName << " " << ptr->accountNumber << " " << ptr->balance << " " << ptr->getPin() << endl;
        ptr = ptr->next;

    }
    bank.close();

}//tested               

void Bank::Read_File_into_List() {

    ifstream Bank("Bank.txt");
    head = NULL;
    AccountPointer current = NULL;
    string name, number, balance, pin;
    while (Bank >> name >> number >> balance >> pin) {
        Account* newNode = new Account;
        newNode->accounOwnerName = name;
        newNode->accountNumber = std::stoul(number);
        newNode->balance = std::stod(balance);
        int p = stoi(pin);
        newNode->setPin(p);
        // newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
            current = newNode;
        }
        else {
            current->next = newNode;
            current = newNode;
        }
    }
    Bank.close();
}//tested


