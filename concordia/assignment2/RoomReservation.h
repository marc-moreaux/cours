#pragma once
#include "Customer.h"

class RoomReservation
{
public:
	void showReservation();
	Date getArrivalDate();
	int  getDuration();
	int  getReservationNumber();
	int  getRoomNumber();
	void setRoomNumber(int);

	RoomReservation(Customer myCustomer = Customer(), Date arrivalDate = Date(), int durationStay=1,bool askConsole=false) ;
	~RoomReservation();
	
private : 
	Customer roomCostumer;
	Date arrivalDate;
	int duration;
	int roomNumber;
	static int reservationCount;
	int reservationNumber;

	void setDuration(int);
};

