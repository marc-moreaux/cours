// assignment1.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"

int menu();

int _tmain(int argc, _TCHAR* argv[])
{
	int menuChoice=0;
	srand(time(NULL));

	while(menuChoice=menu()){
		switch(menuChoice){
			case 1 : exercice1(); break;
			case 2 : exercice2(); break;
			case 3 : exercice3(); break;
		}
	}

	return 0;
}



int menu(){
	int choice=-1;
	system("cls");
	std::cout << "\t *** WELCOME TO THE ASSIGNMENT 1 ***" << std::endl << std::endl;
	
	std::cout << "  to do exercice 1 press 1  " << std::endl ;
	std::cout << "  to do exercice 2 press 2  " << std::endl ;
	std::cout << "  to do exercice 3 press 3  " << std::endl ;
	std::cout << std::endl << "  to exit press 0  " << std::endl ;

	do{
		if(_kbhit())
			choice=_getch()-'0';
	}while(choice < 0 || 3 < choice);
	system("cls");

	return choice;
}


