#include "Admin.h"
#include"Bank.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include<fstream>
#include<iostream>
using namespace std;

Admin::Admin() {
	
}

void Admin::viewAccounts()
{
	AccountPointer ptr=head;
	while (ptr != nullptr) {

		cout << "Account Username =" << ptr->accounOwnerName << endl;
		cout << "Account number =" << ptr->accountNumber << endl;
		cout << "Balance = " << ptr->balance<<endl;
		ptr = ptr->next;

	}
}

void Admin::SearchAccount(unsigned short accountNumber)
{
	AccountPointer ptr = head;
	while (ptr != nullptr) {
		if (ptr->accountNumber == accountNumber) {
			cout << "Account Username =" << ptr->accounOwnerName << endl;
			cout << "Balance = " << ptr->balance << endl;
			
			return;
		}
          ptr = ptr->next;
	}
}

void Admin::ViewTransactions()
{
	string t;
	ifstream Transactions("transactions.txt");
	while (!Transactions.eof()) {
		getline(Transactions, t,'*');
		cout << t;
	}
	return;
}
