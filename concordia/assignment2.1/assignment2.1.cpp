// assignment2.1.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	Date myDate = Date();
	Date myDate2 = Date(2,45,2001);
	myDate.showDate();
	printf("\n");
	myDate2.showDate();
	
	system("pause");

	return 0;
}

