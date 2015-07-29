#include "Date.h"


void Date::setDay(int paramDay){
	day = paramDay;	
	if(day<0 || 30<day){
		std::cout << "Error on day, day set to 1" << std::endl;
		day=1;
	}	
}
void Date::setMonth(int paramMonth){
	month = paramMonth;
	if(month <= 0 || 12 < month){
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
int Date::getDay(){return day;}
int Date::getMonth(){return month;}
int Date::getYear(){return year;}
int Date::getArrivalDateOf360(){return day+(month-1)*30;}

void Date::showDate(){
	std::cout << day << "/" << month << "/" << year ;
}


Date::Date(int paramDay,int paramMonth,int paramYear,bool askConsole){
	if(askConsole){
		std::string entry;
		std::cout << " (enter date as 00/00/0000 ) : ";
		do{
			std::cin >> entry;
		}while( (entry.size()!=10) &&
			   !('0'<entry[0]&&entry[0]<='9' && '0'<entry[1]&&entry[1]<='9' && entry[2]=='/'
			&&   '0'<entry[3]&&entry[3]<='9' && '0'<entry[4]&&entry[4]<='9' && entry[5]=='/'
			&&   '0'<entry[6]&&entry[6]<='9' && '0'<entry[7]&&entry[7]<='9' && '0'<entry[8]&&entry[8]<='9'
			&&   '0'<entry[9]&&entry[9]<='9'));
		
		paramDay   = (entry[0]-'0')*10   + (entry[1]-'0') ;
		paramMonth = (entry[3]-'0')*10   + (entry[4]-'0') ;
		paramYear  = (entry[6]-'0')*1000 + (entry[7]-'0')*100 + (entry[8]-'0')*10 + (entry[9]-'0')  ;
	}
	setYear(paramYear);
	setMonth(paramMonth);
	setDay(paramDay);
}
Date::~Date(){}
