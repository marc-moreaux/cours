#include "RoomReservation.h"
#include "myFunctions.h"
#include <Windows.h>


void RoomReservation::showReservation(){
	std::cout << "\t\tษอออออออออออออออออออออออออออออออออออออออออออออออป";  std::cout << std::endl ;
	roomCostumer.showCostumer();
	std::cout << "\t\tบ arival date  . . . . . : "; arrivalDate.showDate(); setCursorToPosX(64,"บ\n");
	std::cout << "\t\tบ duration . . . . . . . : " << duration ; setCursorToPosX(64,"บ\n");
	std::cout << "\t\tบ room . . . . . . . . . : " << roomNumber ; setCursorToPosX(64,"บ\n");
	std::cout << "\t\tบ reservation number . . : " << reservationNumber ; setCursorToPosX(64,"บ\n");
	std::cout << "\t\tศอออออออออออออออออออออออออออออออออออออออออออออออผ" << std::endl ;
}

void RoomReservation::setDuration(int param){ duration = (param < 0) ? 1 : param;}
void RoomReservation::setRoomNumber(int param){roomNumber = (param < 0) ? 1 : param;}

Date RoomReservation::getArrivalDate(){return arrivalDate;}
int  RoomReservation::getDuration(){return duration;}
int  RoomReservation::getReservationNumber(){return reservationNumber;}
int  RoomReservation::getRoomNumber(){return roomNumber;}

RoomReservation::RoomReservation(Customer myCustomer, Date arrivalDate, int durationStay,bool askConsole){
	if(askConsole){
		myCustomer = Customer(" ","0",Date(),true);
		std::cout << "please, enter your arrivalDate ";
		arrivalDate = Date(0,0,0,true);
		std::cout << "please, enter duration of the stay ";
		do{
			std::cin >> durationStay;
			std::cin.clear();
			std::cin.ignore(256,'\n');
		}while(durationStay<=0);

	}
	
	roomCostumer = myCustomer;
	this->arrivalDate = arrivalDate;
	duration = durationStay;
	setRoomNumber(0);
	setDuration(duration);


	reservationCount++;
	reservationNumber = reservationCount;
}

int RoomReservation::reservationCount = 0;
RoomReservation::~RoomReservation(){}
