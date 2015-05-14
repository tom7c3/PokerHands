#include "Hand.h"
#include "Card.h"

#include <iostream>

void Hand::addCard( Card card )
{
    if ( mCards.size() >= 5 )
    {
        throw "Player could have only 5 cards";
    }

    mCards.push_back(card);
}

Card Hand::getBestCard()
{
    Card card = mCards[0];

    for ( Card c : mCards )
    {
        if ( c.getType() > card.getType() )
            card = c;
    }

    return card;
}

int Hand::getBestCardPower( int next )
{
    int n = 0;
    int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    loadPowers( amount );

    for ( int i = 12; i >= 0; --i )
    {
//			if ( amount[i] == 1 )
        if ( amount[i] > 0 )
        {
            if ( ++n == next )
                return i;
        }
    }

    return 0;
}

Card Hand::getWorseCard()
{
    Card card = mCards[0];

    for ( Card c : mCards )
    {
        if ( c.getType() < card.getType() )
            card = c;
    }

    return card;
}

bool Hand::checkSameSuit()
{
    char suit = mCards[0].getSuit();

//		System.out.print(suit);

    for ( int i = 1; i < mCards.size(); ++i )
    {
        if ( mCards[i].getSuit() != suit )
            return false;
    }

    return true;
}

bool Hand::hasCard( Card::eCardType type )
{
    for ( Card c : mCards )
    {
        if ( c.getType() == type )
            return true;
    }

    return false;
}

bool Hand::checkRoyalFlush()
{
    if ( checkSameSuit() )
    {
        return hasCard( Card::eCardType::CARDT) && hasCard( Card::eCardType::CARDQ) &&
               hasCard( Card::eCardType::CARDK) && hasCard( Card::eCardType::CARDA);
    }

    return false;
}

bool Hand::checkStraightFlush()
{
    if ( checkSameSuit() )
        return hasStraight();

    return false;
}

void Hand::loadPowers( int table[] )
{
    for ( int i = 0; i < 5; ++i )
    {
        ++table[ mCards[i].getType() - 2 ];
    }
}

Hand::FourOfAKind* Hand::getFourOfAKind()
{
    FourOfAKind* foak = nullptr;
    int four = 0;
    int one = 0;

    int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    loadPowers( amount );

    four = getNextPower(amount, 9, 4);
    one = getNextPower(amount, 9, 1);

    if ( four >= 0 && one >= 0 )
    {
        foak = new FourOfAKind();
        foak->setFourOfKindPower(four + 2);
        foak->setFifthPower(one + 2);
    }
    return foak;
}

Hand::FullHouse* Hand::getFullHouse()
{
    FullHouse* fh = nullptr;
    int three = 0;
    int two = 0;

    int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    loadPowers( amount );

    three = getNextPower(amount, 12, 3);
    two = getNextPower(amount, 12, 2);

    if ( three >= 0 && two >= 0 )
    {
        fh = new FullHouse();
        fh->setThreeOfKindPower(three + 2);
        fh->setPairPower(two + 2);
    }

    return fh;
}

bool Hand::hasStraight()
{
    Card bestCard = getBestCard();
    Card worseCard = getWorseCard();

    if ( bestCard.getType() == Card::eCardType::CARDA && worseCard.getType() == Card::eCardType::CARD2 )
    {
        // there is chance for A2345 //
        return hasCard( Card::eCardType::CARD3 ) && hasCard( Card::eCardType::CARD4 ) && hasCard( Card::eCardType::CARD5 );
    }
    else
    {
        int power = worseCard.getType();
        for ( int i = 0; i < 5; ++i )
        {
            if ( !hasCard( (Card::eCardType)++power ) )
                return false;
        }

        return true;
    }
}

Hand::ThreeOfAKind* Hand::getThreeOfAKind()
{
    ThreeOfAKind* toak = nullptr;
    int three = 0;
    int fourth = 0;
    int fifth = 0;

    int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    loadPowers( amount );

    three = getNextPower( amount, 12, 3 );
    int i = 12;
    i = getNextPower( amount, i, 1 );
    fourth = i;
    i = getNextPower( amount, i - 1, 1 );
    fifth = i;

    if ( three >= 0 && fourth >= 0 && fifth >= 0 )
    {
        toak = new ThreeOfAKind();
        toak->setThreeOfKindPower(three + 2);
        toak->setFourthPower(fourth + 2);
        toak->setFifthPower(fifth + 2);
    }

    return toak;
}

Hand::TwoPair* Hand::getTwoPair()
{
    TwoPair* tp = nullptr;
    int first = 0;
    int second = 0;
    int fifth = 0;

    int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    loadPowers( amount );

    int i = 12;
    i = getNextPower( amount, i, 2 );
    first = i;
    i = getNextPower( amount, i - 1, 2 );
    second = i;
    i = getNextPower( amount, 12, 1 );
    fifth = i;

    if ( first >= 0 && second >= 0 && fifth >= 0 )
    {
        tp = new TwoPair();
        tp->setFirstPairPower(first + 2);
        tp->setSecondPairPower(second + 2);
        tp->setFifthPower(fifth + 2);
    }

    return tp;
}

int Hand::getNextPower( int table[], int i, int amount )
{
    for ( ; i >= 0; --i )
        if ( table[i] == amount )
            return i;

    return -1;
}

Hand::OnePair* Hand::getOnePair()
{
    OnePair* op = nullptr;
    int pair = 0;
    int third = 0;
    int fourth = 0;
    int fifth = 0;

    int amount[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    loadPowers( amount );

    pair = getNextPower( amount, 12, 2 );
    int i = 12;
    i = getNextPower( amount, i, 1 );
    third = i;
    i = getNextPower( amount, i - 1, 1 );
    fourth = i;
    i = getNextPower( amount, i - 1, 1 );
    fifth = i;

    if ( pair >= 0 && third >= 0 && fourth >= 0 && fifth >= 0 )
    {
        op = new OnePair();
        op->setPairPower(pair + 2);
        op->setThirdPower(third + 2);
        op->setFourthPower(fourth + 2);
        op->setFifthPower(fifth + 2);
    }

    return op;
}


















