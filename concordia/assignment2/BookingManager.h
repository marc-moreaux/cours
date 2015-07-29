#pragma once
#include "Booking.h"

class BookingManager
{
public:
	void showMenu();
	void runBooking();

	BookingManager(void);
	~BookingManager(void);

private:
	Booking myBook;
};

