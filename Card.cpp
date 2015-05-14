#include "Card.h"

#include <iostream>

Card::Card( std::string s )
{
    if ( s.length() != 2 )
    {
        throw "bad card name";
    }
    else
    {
        mCard = s[0];
        mSuit = s[1];

        if ( mSuit != 'H' && mSuit != 'D' && mSuit != 'C' && mSuit != 'S' )
        {
            throw "Unknown card suit";
        }

        if ( mCard >= '2' && mCard <= '9' )
        {
            mCardType = (eCardType)(mCard - 48); // '2' == 2 -> '9' == 9 //
        }
        else
        {
            switch ( mCard )
            {
                case 'T':
                    mCardType = eCardType::CARDT;
                    break;
                case 'J':
                    mCardType = eCardType::CARDJ;
                    break;
                case 'Q':
                    mCardType = eCardType::CARDQ;
                    break;
                case 'K':
                    mCardType = eCardType::CARDK;
                    break;
                case 'A':
                    mCardType = eCardType::CARDA;
                    break;
                default:
                    throw "Unknown card type";
            }
        }
    }
}





