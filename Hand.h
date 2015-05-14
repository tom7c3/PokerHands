#pragma once

#include <vector>
#include "Card.h"

class Hand
{
  public:

	class FourOfAKind
	{
      public:

		void setFourOfKindPower(int power) { mFourOfKindPower = power; }
		void setFifthPower( int power ) { mFifthPower = power; }

		int getFourOfKindPower() { return mFourOfKindPower; }
		int getPairPower() { return mFifthPower; }

      private:

		int mFourOfKindPower = 0;
		int mFifthPower = 0;
	};

	class FullHouse
	{
      public:

		void setThreeOfKindPower(int power) { mThreeOfKindPower = power; }
		void setPairPower( int power ) { mPairPower = power; }

		int getThreeOfKindPower() { return mThreeOfKindPower; }
		int getPairPower() { return mPairPower; }

      private:

		int mThreeOfKindPower = 0;
		int mPairPower = 0;
	};

	class ThreeOfAKind
	{
      public:

		void setThreeOfKindPower(int power) { mThreeOfKindPower = power; }
		void setFourthPower( int power ) { mFourthPower = power; }
		void setFifthPower( int power ) { mFifthPower = power; }

		int getThreeOfKindPower() { return mThreeOfKindPower; }
		int getFourthPower() { return mFourthPower; }
		int getFifthPower() { return mFifthPower; }

      private:

		int mThreeOfKindPower = 0;
		int mFourthPower = 0;
		int mFifthPower = 0;
	};

	class TwoPair
	{
      public:

		void setFirstPairPower(int power) { mFirstPairPower = power; }
		void setSecondPairPower( int power ) { mSecondPairPower = power; }
		void setFifthPower( int power ) { mFifthPower = power; }

		int getFirstPairPower() { return mFirstPairPower; }
		int getSecondPairPower() { return mSecondPairPower; }
		int getFifthPower() { return mFifthPower; }

      private:

		int mFirstPairPower = 0;
		int mSecondPairPower = 0;
		int mFifthPower = 0;
	};

	class OnePair
	{
      public:

		void setPairPower(int power) { mPairPower = power; }
		void setThirdPower( int power ) { mThirdPower = power; }
		void setFourthPower( int power ) { mFourthPower = power; }
		void setFifthPower( int power ) { mFifthPower = power; }

		int getPairPower() { return mPairPower; }
		int getThirdPower() { return mThirdPower; }
		int getFourthPower() { return mFourthPower; }
		int getFifthPower() { return mFifthPower; }

      private:

		int mPairPower = 0;
		int mThirdPower = 0;
		int mFourthPower = 0;
		int mFifthPower = 0;
	};

	void addCard( Card card );

	Card getBestCard();
	int getBestCardPower( int next );
	Card getWorseCard();

	bool checkSameSuit();
	bool hasCard( Card::eCardType type );
	bool checkRoyalFlush();
	bool checkStraightFlush();
	bool hasStraight();

	void loadPowers( int table[] );
	int getNextPower( int table[], int i, int amount );

	OnePair* getOnePair();
	TwoPair* getTwoPair();
	ThreeOfAKind* getThreeOfAKind();
	FourOfAKind* getFourOfAKind();
	FullHouse* getFullHouse();

//	public void printHand()
//	{
//		for ( Card c : mCards )
//		{
//			System.out.print(c.getCard());
//			System.out.print(c.getSuit());
//			System.out.print(" ");
//		}
//		//System.out.println();
//	}

	std::vector<Card> mCards;
	//Card[] mCards;
	//private eRank
};
