#include "stdafx.h"

void exercice1(){
	//   ***  variables  ***
	int entry;
	int myInt[3]={0};
	char myChar[4]={'\0'}; // 4 is for the '\0'
	
	//   ***  get correct entry  ***
	do{
		std::cout << "please insert your integer : " ;
		std::cin >> entry;
	}while(!validEntry(entry));

	//  ***  separate the entry in 3 integers  ***      if y have as entry 123456
	myInt[0] = entry / 10000;	// here I take 12
	entry -= myInt[0]*10000;	// here I remove 12
	myInt[1] = entry / 100;		// here I take 34
	entry -= myInt[1]*100;		// here I remove 34
	myInt[2] = entry;			// here I take 56
	
	//  *** check if it's a letter either put an "+"  ***
	for(int i=0;i<3;i++)
		myInt[i]=changeIfNotLetter(myInt[i]);
	for(int i=0;i<3;i++)
		myChar[i]=myInt[i];

	//  ***  show the result  ***
	std::cout << std::endl << "what you entered corespond to : " << myChar << std::endl << std::endl;
	system("pause");
}
bool validEntry(int a){
	if( a >= 100000 && a < 1000000 ) // cases problem if the entry is "000000" or "012345"
		return true;
	std::cout << "please enter a 6 digit number" << std::endl;
	return false;
}
int changeIfNotLetter(int a){
	if(a < 'A' || 'Z' < a)
		a = '+';

	return a;
}