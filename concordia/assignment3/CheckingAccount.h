#pragma once
#include "Date.h"
#include "SavingsAccount.h"

class CheckingAccount :
	public SavingsAccount
{
public:
	bool withdrawal(double amount, int account_number);
	CheckingAccount(void);
	~CheckingAccount(void);
	void addOneDay();
	Date getCurentDate();

private :
	int numberOfFreeTransactionPerPeriod;
	int remainingNumberOfFreeTransactions;
	static Date currentDate;
	Date freeTransactionDate;
};

