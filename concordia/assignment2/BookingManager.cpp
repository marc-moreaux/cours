#include "BookingManager.h"
#include <conio.h>

void BookingManager::showMenu(){
	std::cout << std::endl << std::endl << std::endl ;
	std::cout << "\t\t�����������������������������������������������������������ͻ"<< std::endl ;
	std::cout << "\t\t�                                                           �" << std::endl ;
	std::cout << "\t\t�     1 - reserve a room                                    �" << std::endl ;
	std::cout << "\t\t�     2 - remove a reservation                              �" << std::endl ;
	std::cout << "\t\t�     3 - show info from reservation number                 �" << std::endl ;
	std::cout << "\t\t�     4 - show book reservation                             �" << std::endl ;
	std::cout << "\t\t�     5 - show all reservation ever made                    �" << std::endl ;
	std::cout << "\t\t�     0 - quit                                              �" << std::endl ;
	std::cout << "\t\t�                                                           �" << std::endl ;
	std::cout << "\t\t�����������������������������������������������������������ͼ"<< std::endl ;
}

BookingManager::BookingManager(void){
	int choice = -1;
	
	while(choice){
		system("cls");
		showMenu();
		do{
			if(_kbhit())
				choice=_getch()-'0';
		}while(choice < 0 || 5 < choice);

		std::cout << std::endl;
		switch(choice){
		case 1 : 
			myBook.reserve(NULL,true);
			break;
		case 2 :
			myBook.cancel(0,true);
			break;
		case 3 :
			myBook.showReservation(0,true);
			break;
		case 4 :
			myBook.showBookingCalendar();
			break;
		case 5 :
			system("cls");
			myBook.showVectorOfRoomReservation();
			break;
		}
		if(choice)
			choice = -1;
	}
		
}
BookingManager::~BookingManager(void){
}
