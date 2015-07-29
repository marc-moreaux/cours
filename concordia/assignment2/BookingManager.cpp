#include "BookingManager.h"
#include <conio.h>

void BookingManager::showMenu(){
	std::cout << std::endl << std::endl << std::endl ;
	std::cout << "\t\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป"<< std::endl ;
	std::cout << "\t\tบ                                                           บ" << std::endl ;
	std::cout << "\t\tบ     1 - reserve a room                                    บ" << std::endl ;
	std::cout << "\t\tบ     2 - remove a reservation                              บ" << std::endl ;
	std::cout << "\t\tบ     3 - show info from reservation number                 บ" << std::endl ;
	std::cout << "\t\tบ     4 - show book reservation                             บ" << std::endl ;
	std::cout << "\t\tบ     5 - show all reservation ever made                    บ" << std::endl ;
	std::cout << "\t\tบ     0 - quit                                              บ" << std::endl ;
	std::cout << "\t\tบ                                                           บ" << std::endl ;
	std::cout << "\t\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ"<< std::endl ;
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
