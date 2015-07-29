#pragma once

#include <iostream>
class SavingsAccount
{
public:
	SavingsAccount(void);
	virtual ~SavingsAccount(void);
	bool withdrawal(double amount, int account_number); // If withdrawal is successful return true else false
	bool deposit(double amount, int account_number); // Add amount to the account_number 
	void addInterest(void); // Calculate the monthly interest and add to the balance.
	void show();
	double getInterests() const; // return double value of interest
	double get_annualInterest() const;
	double get_balance() const;
	void set_balance(double);
	int get_accountNumber() const;
	double get_transactionFee() const;

private: // or some protected
	static int lastAccountNumber;
	int          accountNumber;
	std::string  custumerName;
	double       balance;
	double       annualInterest;
	double       transactionFee;
	
};

