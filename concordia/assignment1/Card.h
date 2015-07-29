#ifndef CARD_H_DEFINED
#define CARD_H_DEFINED

class Card{
	private :
		int number;
		std::string suit;

	public :
		std::string getSuit();
		void setSuit(std::string);
		int  getNumber();
		void setNumber(int);
		void showCard();
		Card();
		Card(int,std::string);
};

#endif