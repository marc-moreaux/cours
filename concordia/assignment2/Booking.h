#pragma once
#define ROOM_QUANTITY 10
#include "RoomReservation.h"
#include <vector>

class Booking
{
public:
	int reserve(RoomReservation* myReservation,bool askConsole=false);
	int getRoomFromReservation(int myReservationNumber);// function to get the room number from the reservation
	bool cancel(int myReservationNumber,bool askConsole=false);
	void showReservation(int myReservationNumber,bool askConsole=false);
	void showBookingCalendar();
	void showVectorOfRoomReservation();
	Booking();
	~Booking();

private :
	int**bookingCalendar; // number of days * number of rooms
	std::vector<RoomReservation*> roomBookings;
	
};

