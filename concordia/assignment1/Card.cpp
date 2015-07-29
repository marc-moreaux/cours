#include "stdafx.h"


std::string nameSuit[]={"Heart","Diamond","Spade","Club"};
std::string nameValue[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

std::string Card::getSuit(){return suit;}
void Card::setSuit(std::string myString){suit = myString;}
int  Card::getNumber(){return number;}
void Card::setNumber(int a){number = a;}
void Card::showCard(){
	std::cout << "your card is : " << nameValue[number-1] << " " << suit <<std::endl ;
}
Card::Card(){
	number = rand()%12+1;
	suit  = nameSuit[rand()%4];
}
Card::Card(int a,std::string myString){
		bool isTrue = false;
		for(int i=0;i<4;i++)
			if(!myString.compare(nameSuit[i])) // 0 is equal
				isTrue = true; 

		if(isTrue)
			suit = myString; 
		else 
			suit = nameSuit[rand()%4];
			

		if(0 < a && a < 14)
			number= a;
		else 
			number = rand()%12+1;
	}
