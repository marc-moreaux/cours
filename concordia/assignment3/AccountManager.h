#pragma once
#define NUMB_ACCOUNT 50
#define USE_CLS 0
#include "CheckingAccount.h"

class AccountManager
{
public:
	void run();
	void insert (SavingsAccount *new_savings_account);// adds a new savings account to the array
	void insert (CheckingAccount *new_checkings_account);// adds a new checking account to the array
	bool close(int account_number, std::string account_type);// close the account by deleting the account obj
	int calculateInterest();// It will calculate the monthly interest on all active accounts. 
	bool Withdrawal(double amount, int account_number, std::string account_type); // Account type will be either “checking” or “savings”. The function will determine the corresponding account object in the array, then, it will execute the appropriate transaction.
	bool deposit (double amount, int account_number, std::string account_type);

	AccountManager(void);
	~AccountManager(void);

private :
	SavingsAccount **mySavingsAccountArray;
	CheckingAccount **myCheckingAccountArray;
	CheckingAccount wayToManageTheDate;

private :
	void showMenu();
	void add_account();
	void close_account();
	void do_withdrowal();
	void do_deposit();
	void change_day();
	void change_month();
	void show_pointers();
	void show_members();
};

