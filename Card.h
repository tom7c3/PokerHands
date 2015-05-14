#pragma once

#include <string>

class Card
{
  public:

    enum eCardType
	{
		CARD2 = 2,
		CARD3,
		CARD4,
		CARD5,
		CARD6,
		CARD7,
		CARD8,
		CARD9,
		CARDT,
		CARDJ,
		CARDQ,
		CARDK,
		CARDA
	};

    Card( std::string s );

	char getCard() { return mCard; }
	char getSuit() { return mSuit; }

    eCardType getType() { return mCardType; }

  private:

    char mCard;
	char mSuit;

	eCardType mCardType;
};
