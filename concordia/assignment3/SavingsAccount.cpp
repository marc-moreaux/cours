#include "SavingsAccount.h"

int SavingsAccount::lastAccountNumber=-1;
SavingsAccount::SavingsAccount(void){
	accountNumber = ++lastAccountNumber;
	balance = 0.0;
	annualInterest = 5.2;
	transactionFee = 3.3;

	std::cout << ">>CONSTRUCTOR : SavingsAccount #" << accountNumber << std::endl;
}
SavingsAccount::~SavingsAccount(void){
	std::cout << ">>DESTRUCTOR : SavingsAccount #" << accountNumber << std::endl;
}


bool SavingsAccount::withdrawal(double amount, int account_number){
	if(account_number!=accountNumber )// it's not the good account
		return false;
	if(balance < amount+transactionFee){ // you don't have money enough
		printf("not money enough\n");
		return false;
	}
	balance-=amount+transactionFee;
	printf("new amount in account %d is %2.2f\n",accountNumber,balance);
	return true;
}
bool SavingsAccount::deposit(double amount, int account_number){
	if(account_number!=accountNumber) // if it's not the good account
		return false;
	balance += amount;
	printf("amount %2.2f has been added to balance in account %d\n",amount,accountNumber);
	return true;
}
void SavingsAccount::addInterest(void){
	balance*=annualInterest/12;
}
void SavingsAccount::show(){
	std::cout<< std::endl;
	std::cout<<"  account number : "<<accountNumber  <<std::endl;
	//std::cout<<"  custumerName : "  <<custumerName   <<std::endl;
	printf("  balance : %2.2f\n",balance);
	//std::cout<<"  balance : "       <<(double)balance        <<std::endl;
	std::cout<<"  annualInterest : "<<annualInterest <<std::endl;
	std::cout<<"  transactionFee : "<<transactionFee <<std::endl;
}
double SavingsAccount::getInterests() const {
	return balance*annualInterest;
}
double SavingsAccount::get_annualInterest()const{double const a=annualInterest; return a;}
double SavingsAccount::get_balance()const{return balance;}
void   SavingsAccount::set_balance(double newBalance){balance = newBalance;}
int    SavingsAccount::get_accountNumber()const{return accountNumber;}
double SavingsAccount::get_transactionFee()const{return transactionFee;}