#pragma once
#include <iostream>
#include <string>

class Date
{
public:
	void showDate();
	int getDay();
	int getMonth();
	int getYear();
	int getArrivalDateOf360();

	Date(int day=1,int month=1,int year=2000,bool askConsole=false);
	~Date();

private :
	int day,month,year;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
};

