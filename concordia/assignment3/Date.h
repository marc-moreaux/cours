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
	int getDateOf360();
	void addOneDay();
	void operator= (const Date myDate);
	Date(int day=1,int month=1,int year=2000,bool askConsole=false);
	~Date();

private :
	int day,month,year;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
};

