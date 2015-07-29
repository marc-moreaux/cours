#pragma once
#include "Date.h"

class Customer
{
public:
	void showCostumer();
	Customer(std::string paramName = "\'no name\'",std::string paramTel="00000000",Date paramBirthDate = Date(), bool askConsole=false) ;
	~Customer();

private:
	Date birthDate;
	std::string name;
	std::string tel;

};

