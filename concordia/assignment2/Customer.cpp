#include "Customer.h"
#include "myFunctions.h"

void Customer::showCostumer(){
	std::cout << "\t\tº costumer . . . . . . . : " << name; setCursorToPosX(64,"º\n");
	std::cout << "\t\tº tel  . . . . . . . . . : " << tel; setCursorToPosX(64,"º\n");
	std::cout << "\t\tº birthdate  . . . . . . : ";
	birthDate.showDate(); setCursorToPosX(64,"º\n");
}

Customer::Customer(std::string paramName,std::string paramTel,Date paramBirthDate, bool askConsole){
	if(askConsole){
		std::cout << "please, enter your name : ";
		std::cin >> paramName;fflush(stdin);
		std::cout << "please, enter your tel : ";
		std::cin >> paramTel;fflush(stdin);
		std::cout << "please, enter your birthDate ";
		paramBirthDate = Date(0,0,0,true);

	}
	name=paramName;
	tel = paramTel;
	birthDate = paramBirthDate;	
}
Customer::~Customer(){}
