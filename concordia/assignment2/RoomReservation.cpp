#include "RoomReservation.h"
#include "myFunctions.h"
#include <Windows.h>


void RoomReservation::showReservation(){
	std::cout << "\t\t�����������������������������������������������ͻ";  std::cout << std::endl ;
	roomCostumer.showCostumer();
	std::cout << "\t\t� arival date  . . . . . : "; arrivalDate.showDate(); setCursorToPosX(64,"�\n");
	std::cout << "\t\t� duration . . . . . . . : " << duration ; setCursorToPosX(64,"�\n");
	std::cout << "\t\t� room . . . . . . . . . : " << roomNumber ; setCursorToPosX(64,"�\n");
	std::cout << "\t\t� reservation number . . : " << reservationNumber ; setCursorToPosX(64,"�\n");
	std::cout << "\t\t�����������������������������������������������ͼ" << std::endl ;
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
