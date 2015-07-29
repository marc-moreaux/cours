#include "Customer.h"
#include <string>



void Customer::showCostumer(){
	std::cout << "costumer : " << name << " tel : " << tel << " birthdate : ";
	birthDate.showDate();
}


Customer::Customer(){


}
/*Customer::Customer(std::string paramName,std::string paramTel,Date *paramBirthDate  = new Date ){
	name=paramName;
	tel = paramTel;
	birthDate = paramBirthDate;
}*/
Customer::~Customer(){}
