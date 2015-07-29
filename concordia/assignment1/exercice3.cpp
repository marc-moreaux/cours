#include "stdafx.h"


void exercice3(){
	Card card[]={ Card(1,"Diamond") , Card(8,"Heart") , Card(12,"Spade") };

	std::cout << "1st card listed number is : " << card[0].getNumber() << std::endl;
	std::cout << "I can set it to 3 ... " ; card[0].setNumber(3);
	std::cout << "Now card number is : " << card[0].getNumber() << std::endl;

	card[0].showCard();
	card[1].showCard();
	card[2].showCard();

	system("pause");
}
