#pragma once
#include "Date.h"
#include <Windows.h>
#include <string.h>


class Customer
{
public:
	void showCostumer();
	Customer();
	//Customer(std::string paramName = "\'no name\'",std::string paramTel="00000000",Date *paramBirthDate = NULL) ;
	~Customer();

private:
	Date birthDate;
	std::string name;
	std::string tel;

};

