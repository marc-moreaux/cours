#pragma once
#include <iostream>

class Date
{
public:
	void showDate();
	Date(int day=1,int month=1,int year=2000);
	~Date();

private :
	int day,month,year;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
};