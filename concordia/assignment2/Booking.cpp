#include "Booking.h"
#include <Windows.h>
#include "myFunctions.h"

int Booking::reserve(RoomReservation* myReservation,bool askConsole){
	if(askConsole){ // initialise a RoomReservation.
		myReservation = new RoomReservation(Customer(),Date(),0,true);
	}
	
	
	int roomOK = 0;
	// check avalibility of room on the duration.
	if( 360 < myReservation->getDuration()+myReservation->getArrivalDate().getArrivalDateOf360()){
		std::cout << "reservation off size !!! ( quitting in 3 sec ) " ;setCursorToPosrelativeXY(-9,0);
		showMyTimer(3);
		return 0;
	}

	for(int i=1;i<ROOM_QUANTITY+1;i++){ // check all the rooms (from 1 because 0 is no room)
		roomOK = 0;
		for(int j=0;j<myReservation->getDuration();j++) // check the duration
			if( bookingCalendar[myReservation->getArrivalDate().getArrivalDateOf360() + j ][i] == 0 ) 
				roomOK++;
		if(roomOK == myReservation->getDuration() ){ // the reservation can be done
			for(int k=0;k<myReservation->getDuration();k++) // to calendar
				bookingCalendar[myReservation->getArrivalDate().getArrivalDateOf360() + k ][i] = myReservation->getReservationNumber() ;
			roomBookings.push_back(myReservation);// to vector
			myReservation->setRoomNumber(i);
			return i+1;			
		}
	}

	return 0;
}
int Booking::getRoomFromReservation(int myReservationNumber){
	for(int i=0;i<roomBookings.size();i++)
		if(roomBookings[i]->getReservationNumber() == myReservationNumber )
			return roomBookings[i]->getRoomNumber();

	return -1;
}
bool Booking::cancel(int myReservationNumber,bool askConsole){
	if(askConsole){
		std::cout << " what is your reservation number : ";
		do{
			std::cin >> myReservationNumber;
			std::cin.clear();
			std::cin.ignore(256,'\n');
		}while(myReservationNumber <= 0);
	}


	for(int i=0;i<roomBookings.size();i++)
		if(roomBookings[i]->getReservationNumber() == myReservationNumber ){ // this is the reservation to remove
			for(int j=0;j<roomBookings[i]->getDuration();j++)
				bookingCalendar[roomBookings[i]->getArrivalDate().getArrivalDateOf360()+j][roomBookings[i]->getRoomNumber()-1]=0;
			roomBookings[i]->setRoomNumber(0);
			roomBookings[i]->showReservation();
			std::cout << "reservation has been cancelled ( quitting in 3 sec ) " ;setCursorToPosrelativeXY(-9,0);
			showMyTimer(3);
			return true;
		}
	std::cout << "reservation could not be cancelled ( quitting in 3 sec ) ";setCursorToPosrelativeXY(-9,0);
	showMyTimer(3);
	return false;
}
void Booking::showReservation(int myReservationNumber,bool askConsole){
	if(askConsole){
		std::cout << " what is your reservation number : ";
		do{	
			std::cin.clear();
			std::cin.ignore(256,'\n') ;
			std::cin >> myReservationNumber;
		}while(myReservationNumber < 0);
	}
	for(int i=0;i<roomBookings.size();i++)
		if(roomBookings[i]->getReservationNumber() == myReservationNumber )
			roomBookings[i]->showReservation();
	system("pause");
		
}
void Booking::showBookingCalendar(){
	int month;
	std::cout << "wich month do you want to view ? (choose between 1 and 12) : ";
	do{
		std::cin >> month;
			std::cin.clear();
		std::cin.ignore(256,'\n') ;
	}while(month<1||12<month);

	system("cls");
	std::cout << std::endl;
	std::cout << "\t\tFOR MONTH " << month << " YOU HAVE : " << std::endl;
	std::cout << std::endl;
 	std::cout << "        " << (unsigned char)186;      for(int i=0;i<30;i++) std::cout << (i+1<10?" " : "") << i+1 << " ";      std::cout << std::endl;
	std::cout << " "; for(int i=0;i<7;i++) std::cout << (unsigned char)205;    std::cout << (unsigned char)206;     for(int i=0;i<89;i++) std::cout << (unsigned char)205;
	
	for(int j=1;j<ROOM_QUANTITY+1;j++){
		std::cout << "\n room " <<  (j<10?" " : "") << j << (unsigned char)186;
		for(int i=0;i<30;i++){
			std::cout << (bookingCalendar[(i+1)+((month-1)*30)][j]<10?" " : "") ;
			if(bookingCalendar[(i+1)+((month-1)*30)][j] == 0)
				std::cout << ". ";
			else 
				std::cout << bookingCalendar[(i+1)+((month-1)*30)][j] << " " ;
		}
	}
	std::cout << std::endl << std::endl;
	system("pause");
}
void Booking::showVectorOfRoomReservation(){
	for(int i=0;i<roomBookings.size();i++)
		roomBookings[i]->showReservation();
	system("pause");
}

Booking::Booking(){
	bookingCalendar = new int*[360]; // 360 = number of days / year
	for(int i=0;i<361;i++)
		bookingCalendar[i] = new int[ROOM_QUANTITY+1];

	for(int i=0;i<361;i++)
		for(int j=0;j<ROOM_QUANTITY+1;j++)
			bookingCalendar[i][j]=0;
	
}
Booking::~Booking(){
}
