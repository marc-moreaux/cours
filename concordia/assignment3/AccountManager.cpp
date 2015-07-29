#include "AccountManager.h"
#include <conio.h>

int askAccountType(std::string propos){
	int choice=-1;
	std::cout << std::endl << std::endl << std::endl ;
	std::cout << "\t   " << propos << std::endl ;
	std::cout << std::endl ;
	std::cout << "\t\t  What sort of account are we dealing with ? " << std::endl ;
	std::cout << "\t\t  1 - savings account " << std::endl ;
	std::cout << "\t\t  2 - checking account " << std::endl ;
	do{
		if(_kbhit())
			choice=_getch()-'0';
	}while(choice < 1 || 2 < choice);
	return choice;
}
int askAccountNumber(){
	int choice;
	std::cout << std::endl << std::endl << std::endl ;
	std::cout << "\t\t  enter the number of your account (1 to " << NUMB_ACCOUNT << ")" << std::endl ;
	do{
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256,'\n');
	}while(choice<=0 || NUMB_ACCOUNT<=choice );
	return choice;
}
double askAmount(){
	double choice;
	std::cout << std::endl << std::endl << std::endl ;
	std::cout << "\t\t  enter your amount (0 to ... int limit please :p )" << std::endl ;
	do{
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256,'\n');
	}while(choice<0  );
	return choice;
}

void AccountManager::showMenu(){

	std::cout << std::endl << std::endl << std::endl ;
	std::cout << "\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<< std::endl ;
	std::cout << "\t\tบ                                                           บ" << std::endl ;
	std::cout << "\t\tบ                  Actual day is : ";wayToManageTheDate.getCurentDate().showDate(); std::cout <<"               บ" << std::endl ;
	std::cout << "\t\tบ                                                           บ" << std::endl ;
	std::cout << "\t\tบ     1 - add an account                                    บ" << std::endl ;
	std::cout << "\t\tบ     2 - close an account                                  บ" << std::endl ;
	std::cout << "\t\tบ     3 - do a withdrowal on an account                     บ" << std::endl ;
	std::cout << "\t\tบ     4 - do a deposit on an account                        บ" << std::endl ;
	std::cout << "\t\tบ     5 - change day                                        บ" << std::endl ;
	std::cout << "\t\tบ     6 - change month                                      บ" << std::endl ;
	std::cout << "\t\tบ     7 - show pointer all accounts                         บ" << std::endl ;
	std::cout << "\t\tบ     8 - show all accounts                                 บ" << std::endl ;
	std::cout << "\t\tบ     0 - quit                                              บ" << std::endl ;
	std::cout << "\t\tบ                                                           บ" << std::endl ;
	std::cout << "\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"<< std::endl ;
}

void AccountManager::add_account(){
	int choice=-1;
	if(USE_CLS) system("cls");
	choice=askAccountType("Add an account");

	switch(choice){
	case 1 : insert(new SavingsAccount()); break;
	case 2 : insert(new CheckingAccount()); break;
	default : std::cout << "\t\t  error on inserting an account " << std::endl ;
	}
	
}
void AccountManager::close_account(){
	int choice=-1;
	int choice2=0, error = 1;
	if(USE_CLS) system("cls");
	choice = askAccountType("Close an account");
	choice2= askAccountNumber();


	switch(choice){
	case 1 : error = (close(choice2,"savings")?  0 : 1); break;
	case 2 : error = (close(choice2,"checking")? 0 : 1); break;
	}

	if(error){
		std::cout << "\t\t  error on closing account " << std::endl ;
	}
}
void AccountManager::do_withdrowal(){
	int error=-1;     int choice=-1;
	int accNumber=-1; int amount=-1;
	
	if(USE_CLS) system("cls");
	choice= askAccountType("Withdrawal");
	accNumber= askAccountNumber();
	amount= askAmount();

	switch(choice){
	case 1 : error = (Withdrawal(amount,accNumber,"savings")?  0 : 1); break;
	case 2 : error = (Withdrawal(amount,accNumber,"checking")? 0 : 1); break;
	}

	if(error){
		std::cout << "\t\t  error on Withdrawal " << std::endl ;
	}

}
void AccountManager::do_deposit(){
	int error=-1;     int choice=-1; 
	int accNumber=-1; double amount=-1;
	
	if(USE_CLS) system("cls");
	choice= askAccountType("Deposit");
	accNumber= askAccountNumber();
	amount= askAmount();

	switch(choice){
	case 1 : error = (deposit(amount,accNumber,"savings")?  0 : 1); break;
	case 2 : error = (deposit(amount,accNumber,"checking")? 0 : 1); break;
	}

	if(error){
		std::cout << "\t\t  error on Deposit " << std::endl ;
	}

}
void AccountManager::change_day(){
	wayToManageTheDate.addOneDay();
}
void AccountManager::change_month(){
	for(int i=0;i<30;i++)
		change_day();
}
void AccountManager::show_pointers(){
	printf("Savings : ");
	for(int i=0;i<NUMB_ACCOUNT;i++)
		printf("%p ",mySavingsAccountArray[i]);
	printf("\nChecking : ");
	for(int i=0;i<NUMB_ACCOUNT;i++)
		printf("%p ",myCheckingAccountArray[i]);

}
void AccountManager::show_members(){
	printf("Savings : ");
	for(int i=0;i<NUMB_ACCOUNT;i++)
		if(mySavingsAccountArray[i])
			mySavingsAccountArray[i]->show();
	printf("\nChecking : ");
	for(int i=0;i<NUMB_ACCOUNT;i++)
		if(myCheckingAccountArray[i])
			myCheckingAccountArray[i]->show();
		
}

void AccountManager::run(){
	int choice = -1;
	
	while(choice){
		if(USE_CLS) system("cls");
		showMenu();
		do{
			if(_kbhit())
				choice=_getch()-'0';
		}while(choice < 0 || 8 < choice);

		std::cout << std::endl;
		switch(choice){ 

		case 1 : add_account();   break;
		case 2 : close_account(); break;
		case 3 : do_withdrowal(); break;
		case 4 : do_deposit();    break;
		case 5 : change_day();    break;
		case 6 : change_month();  break;
		case 7 : show_pointers(); break;
		case 8 : show_members(); 
		}
		if(choice) choice = -1; // quit if finish (0 had been pressed)


	}
}
void AccountManager::insert(SavingsAccount *new_savings_account){
	int index=0;
	while(mySavingsAccountArray[index] != 0 && index < NUMB_ACCOUNT)
		index++;
	
	mySavingsAccountArray[index] = new_savings_account;
	mySavingsAccountArray[index]->show();
}
void AccountManager::insert (CheckingAccount *new_checking_account){
	int index=0;
	while(myCheckingAccountArray[index] != 0 && index < NUMB_ACCOUNT)
		index++;

	myCheckingAccountArray[index] = new_checking_account;
	myCheckingAccountArray[index]->show();
}
bool AccountManager::close(int account_number, std::string account_type){
	if(NUMB_ACCOUNT < account_number)
		return false;

	if(!account_type.compare("checking") && myCheckingAccountArray[account_number-1]){
		myCheckingAccountArray[account_number-1]->~CheckingAccount();
		myCheckingAccountArray[account_number-1]=NULL;
	}

	else if(!account_type.compare("savings") && mySavingsAccountArray[account_number-1]){
		mySavingsAccountArray[account_number-1]->~SavingsAccount();
		mySavingsAccountArray[account_number-1]=NULL;
	}

	else{ printf("true error"); return false;} // string entry is wrong or there is not instanciate obj

	return true;
}
int  AccountManager::calculateInterest(){
	int interest=0;
	for(int i=0;i<NUMB_ACCOUNT  ;i++){
		if( mySavingsAccountArray[i] )
			interest += mySavingsAccountArray[i]->getInterests();
		if( myCheckingAccountArray[i] )
			interest += myCheckingAccountArray[i]->getInterests();
	}
	return interest;
}
bool AccountManager::Withdrawal(double amount, int account_number, std::string account_type){
	if(account_type.compare("checking")==0)
		for(int i=0;i<NUMB_ACCOUNT;i++)
			if(myCheckingAccountArray[i]){
				myCheckingAccountArray[i]->withdrawal(amount,account_number);
				return true;
			}
			else;

	else if(account_type.compare("savings")==0)
		for(int i=0;i<NUMB_ACCOUNT;i++)
			if(mySavingsAccountArray[i]){
				mySavingsAccountArray[i]->withdrawal(amount,account_number);
				return true;
			}
			else;
	else return false; // string entry is wrong 
	return false; // account number not found

}
bool AccountManager::deposit (double amount, int account_number, std::string account_type){
	if(account_type.compare("checking")==0)
		for(int i=0;i<NUMB_ACCOUNT;i++)
			if(myCheckingAccountArray[i]){
				printf("myCheckingAccountArray[%d]->withdrawal(%2.2f,%d)  executing\n",i,amount,account_number);
				if(myCheckingAccountArray[i]->deposit(amount,account_number))
					return true;
			}
			else;

	else if(account_type.compare("savings")==0)
		for(int i=0;i<NUMB_ACCOUNT;i++)
			if(mySavingsAccountArray[i]){
				printf("mySavingsAccountArray[%d]->withdrawal(%2.2f,%d)  executing\n",i,amount,account_number);
				if(mySavingsAccountArray[i]->deposit(amount,account_number))
					return true;
			}
			else;

	else{ printf("Didin't found any myCheckingAccountArray or mySavingsAccountArray like that\n"); return false;} // string entry is wrong 
	return false; // nothing has been done but entry was regonise
}



AccountManager::AccountManager(void){
	mySavingsAccountArray = new SavingsAccount*[NUMB_ACCOUNT];
	for(int i=0;i<NUMB_ACCOUNT;i++) mySavingsAccountArray[i]=NULL;
	myCheckingAccountArray = new CheckingAccount*[NUMB_ACCOUNT];
	for(int i=0;i<NUMB_ACCOUNT;i++) myCheckingAccountArray[i]=NULL;
}
AccountManager::~AccountManager(void){

}
