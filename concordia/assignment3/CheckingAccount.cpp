#include "CheckingAccount.h"
#define NUMBER_OF_FREE_TRANSACTION 10


bool CheckingAccount::withdrawal(double amount, int account_number){
	if( 30 < currentDate.getDateOf360()-freeTransactionDate.getDateOf360() ){ // check the date
		remainingNumberOfFreeTransactions = numberOfFreeTransactionPerPeriod;
		freeTransactionDate.operator=(currentDate);
		printf("number of transation of account %d set to %d\n",get_accountNumber(),remainingNumberOfFreeTransactions);
	}
		
	if( get_balance() < amount ){// you want to remove more money than you have  
		printf("you don't have money enough\n");
		return false;
	}
	if(account_number!=get_accountNumber() )//  it's not the good account
		return false;
	if(remainingNumberOfFreeTransactions < 0){
		set_balance(  get_balance()-amount-get_transactionFee()  );
		printf(" remaining Number Of Free Transactions : %d\n",remainingNumberOfFreeTransactions);
		printf(" new balance on account %d is %2.2f\n",get_accountNumber(),get_balance());
	}
	else{
		remainingNumberOfFreeTransactions--;
		set_balance( get_balance() - amount ) ;
		printf(" remaining Number Of Free Transactions : %d\n",remainingNumberOfFreeTransactions);
		printf(" new balance on account %d is %2.2f\n",get_accountNumber(),get_balance());
	}
	return true;
}
Date CheckingAccount::currentDate=Date();
void CheckingAccount::addOneDay(){
	currentDate.addOneDay();
}
Date CheckingAccount::getCurentDate(){return currentDate;}

CheckingAccount::CheckingAccount(void){
	std::cout << ">>CONSTRUCTOR : CheckingAccount" << std::endl;
	numberOfFreeTransactionPerPeriod = NUMBER_OF_FREE_TRANSACTION;
	remainingNumberOfFreeTransactions = numberOfFreeTransactionPerPeriod;
}
CheckingAccount::~CheckingAccount(void){
	std::cout << ">>DESTRUCTOR : CheckingAccount" << std::endl;
}
