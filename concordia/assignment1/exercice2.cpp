#include "stdafx.h"




void exercice2(){
	//   *** variables ***
	char entry[50]={'\0'};
	Plateau** myPlateaus;
	int numberOfPlateau=0,indexOfNewPlateaus=0;

	//   ***  get the array  *** 
	std::cout << "please, enter a sequence of number in order to do the analisis : " << std::endl ;
	std::cin >> entry;

	
	//  *** get number of plateu and allocate "myPlateaus"
	for(int i=0; entry[i]!='\0';i++)
		if(entry[i]!=entry[i+1])
			numberOfPlateau++;
	myPlateaus = new Plateau*[numberOfPlateau];

	// *** fill array of myPlateaus
	for(int i=0,localSize=1; entry[i]!='\0';i++)
		if((entry[i]!=entry[i+1])){
			myPlateaus[indexOfNewPlateaus++] = new Plateau(localSize,entry[i]-'0',i+1);
			localSize = 1;
		}
		else
			localSize++;


	//  *** link equal Plateau ***
	for(int i=0;i<numberOfPlateau ;i++)
		for(int j=i+1;j<numberOfPlateau;j++)
			if( myPlateaus[i]->operator==( *myPlateaus[j] )){ // Do a linkedList
				myPlateaus[i]->linkList(myPlateaus[j]);
				break;
			}
			

	Plateau* ptOfShow = NULL;
	// show equal Plateau
	for(int i=0;i<numberOfPlateau ;i++)
		if( (myPlateaus[i]->isLinked()) && (!myPlateaus[i]->alreadyCheck()) && (ptOfShow = myPlateaus[i]) ){
			do{
				ptOfShow->setCheck(true);
				ptOfShow->showPlateau();
				ptOfShow->showIndices();
				std::cout << " ";
			}while( (ptOfShow->isLinked()) && (ptOfShow=ptOfShow->getNext()));

			std::cout << std::endl;
		}

	system("pause");
}





Plateau::Plateau(int newSize, int newNumber, int newLastIndice){
	size = newSize;
	number = newNumber;
	lastIndice = newLastIndice;
	firstIndice = newLastIndice - newSize+1;
	next = NULL;
	check = false;
}
Plateau::Plateau(){
	size = number = lastIndice = firstIndice = -1;
	next = NULL;
	check = false;
}
void Plateau::showIndices(){
	std::cout << "{" << firstIndice ;
	if(lastIndice!=firstIndice)
		std::cout << "," << lastIndice;
	std::cout << "}";
	
	
}
void Plateau::showPlateau(){
	std::cout << "[" << number ;
	for(int i=1;i<size;i++)
		std::cout << "," << number ;
	std::cout << "]";

}
void Plateau::linkList(Plateau*PlateauToLink){
	next = PlateauToLink;
}
bool Plateau::operator==(Plateau param){
	if(param.size==size && param.number==number)
		return true;
	return false;
}
bool Plateau::isLinked(){
	if (next)
		return true;
	return false;
}
Plateau* Plateau::getNext(){
	return next;
}
bool Plateau::alreadyCheck(){
	return check;
}
void Plateau::setCheck(bool check0){
	check = check0;
}