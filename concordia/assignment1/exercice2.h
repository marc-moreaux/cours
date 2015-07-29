#ifndef EXERCICE2_H_DEFINED
#define EXERCICE2_H_DEFINED


void exercice2();

class Plateau{
	public :
		Plateau();
		Plateau(int size, int number, int lastIndice);
		void showPlateau();
		void showIndices();
		void linkList(Plateau*);
		bool operator==(Plateau);
		bool isLinked();
		bool alreadyCheck();
		void setCheck(bool);
		Plateau* getNext();


	private :
		int size,number;
		int firstIndice, lastIndice;
		Plateau* next;
		bool check;
};




#endif