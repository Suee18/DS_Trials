#pragma once
#include"Bank.h"
class Admin:public Bank
{
	public:
	Admin();
	void viewAccounts();
	void SearchAccount(unsigned short accountNumber);
	//void ViewTransactions();


};

