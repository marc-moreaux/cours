#include "Date.h"

void Date::setDay(int paramDay){
	int monthsCorrespondance[] = {31,29,31,30,31,30,31,31,30,31,30,31};	
	day = paramDay;	
	if(day == 29 && month == 2 && year%4 != 0){//bisextil year (bisextil year is every 4 year, 2012 is bisextil, 2012%4 == 0 )
		std::cout << "Error on day because of besextil year, day set to 28" << std::endl;
		day=28;
	}
	if(day < 0 || monthsCorrespondance[month+1] <= day ){
		std::cout << "Error on day, day set to 1" << std::endl;
		day=1;
	}
}
void Date::setMonth(int paramMonth){
	month = paramMonth;
	if(month < 0 || 12 <= month){
		std::cout << "Error on month, month set to 1 (january)" << std::endl;
		month = 1;
	}
}
void Date::setYear(int paramYear){
	year = paramYear;
	if(year < 0){
		std::cout << "Error on year, year set to 2000"  << std::endl ;
		year = 2000;
	}
}

void Date::showDate(){
	std::cout << day << "/" << month << "/" << year ;
}


Date::Date(int paramDay,int paramMonth,int paramYear){
	setYear(paramYear);
	setMonth(paramMonth);
	setDay(paramDay);
}
Date::~Date(){}
