#include <iostream>
#include "Poker.h"

int Poker::checkRoyalFlush( Hand& p1, Hand& p2 )
{
    if ( p1.checkRoyalFlush() )
        return 1;
    else if ( p2.checkRoyalFlush() )
        return 2;

    return 0;
}

int Poker::checkStraightFlush( Hand& p1, Hand& p2 )
{
    if ( p1.checkStraightFlush() )
        return 1;
    else if ( p2.checkStraightFlush() )
        return 2;

    return 0;
}

int Poker::getFourOfAKindWinner( Hand& p1, Hand& p2 )
{
    Hand::FourOfAKind* p1FOAK = p1.getFourOfAKind();
    Hand::FourOfAKind* p2FOAK = p2.getFourOfAKind();

    if ( p1FOAK != nullptr && p2FOAK != nullptr )
    {
        int power1 = p1FOAK->getFourOfKindPower();
        int power2 = p2FOAK->getFourOfKindPower();
        if ( power1 == power2 )
        {
            int fifthPower1 = p1FOAK->getPairPower();
            int fifthPower2 = p2FOAK->getPairPower();

            if ( fifthPower1 == fifthPower2 )
            {
                // no winner //
            }
            else if ( fifthPower1 > fifthPower2 )
                return 1;
            else if ( fifthPower2 > fifthPower1 )
                return 2;
        }
        else if ( power1 > power2 )
            return 1;
        else if ( power2 > power1 )
            return 2;
    }
    else if ( p1FOAK != nullptr )
    {
        return 1;
    }
    else if ( p2FOAK != nullptr )
    {
        return 2;
    }
    return 0;
}

int Poker::getFullHouseWinner( Hand& p1, Hand& p2 )
{
    Hand::FullHouse* p1FullHouse = p1.getFullHouse();
    Hand::FullHouse* p2FullHouse = p2.getFullHouse();
    if ( p1FullHouse != nullptr && p2FullHouse != nullptr )
    {
        int power1 = p1FullHouse->getThreeOfKindPower();
        int power2 = p2FullHouse->getThreeOfKindPower();

        if ( power1 == power2 )
        {
            int pairPower1 = p1FullHouse->getPairPower();
            int pairPower2 = p2FullHouse->getPairPower();

            if ( pairPower1 == pairPower2 )
            {
                // no winner //
            }
            else if ( pairPower1 > pairPower2 )
                return 1;
            else if ( pairPower2 > pairPower1 )
                return 2;
        }
        else if ( power1 > power2 )
            return 1;
        else if ( power2 > power1 )
            return 2;
    }
    else if ( p1FullHouse != nullptr )
        return 1;
    else if ( p2FullHouse != nullptr )
        return 2;

    return 0;
}

int Poker::getFlushWinner( Hand& p1, Hand& p2 )
{
    if ( p1.checkSameSuit() && p2.checkSameSuit() )
    {
        // no winner //
    }
    else if ( p1.checkSameSuit() )
        return 1;
    else if ( p2.checkSameSuit() )
        return 2;

    return 0;
}

int Poker::getStrightWinner( Hand& p1, Hand& p2 )
{
    if ( p1.checkSameSuit() && p2.checkSameSuit() )
    {
        // no winner //
    }
    else if ( p1.checkSameSuit() )
        return 1;
    else if ( p2.checkSameSuit() )
        return 2;

    return 0;
}

int Poker::getThreeOfAKindWinner( Hand& p1, Hand& p2 )
{
    Hand::ThreeOfAKind* p1TOAK = p1.getThreeOfAKind();
    Hand::ThreeOfAKind* p2TOAK = p2.getThreeOfAKind();

    if ( p1TOAK != nullptr && p2TOAK != nullptr )
    {
        int power1 = p1TOAK->getThreeOfKindPower();
        int power2 = p2TOAK->getThreeOfKindPower();

        if ( power1 == power2 )
        {
            int fourthPower1 = p1TOAK->getFourthPower();
            int fourthPower2 = p2TOAK->getFourthPower();

            if ( fourthPower1 == fourthPower2 )
            {
                int fifthPower1 = p1TOAK->getFifthPower();
                int fifthPower2 = p2TOAK->getFifthPower();

                if ( fifthPower1 == fifthPower2 )
                {
                    // no winner //
                }
                else if ( fifthPower1 > fifthPower2 )
                    return 1;
                else if ( fifthPower2 > fifthPower1 )
                    return 2;
            }
            else if ( fourthPower1 > fourthPower2 )
                return 1;
            else if ( fourthPower2 > fourthPower1 )
                return 2;
        }
        else if ( power1 > power2 )
            return 1;
        else if ( power2 > power1 )
            return 2;
    }
    else if ( p1TOAK != nullptr )
        return 1;
    else if ( p2TOAK != nullptr )
        return 2;

    return 0;
}

int Poker::getTwoPairWinner( Hand& p1, Hand& p2 )
{
    Hand::TwoPair* p1TP = p1.getTwoPair();
    Hand::TwoPair* p2TP = p2.getTwoPair();

    if ( p1TP != nullptr && p2TP != nullptr )
    {
        int powerFirst1 = p1TP->getFirstPairPower();
        int powerFirst2 = p2TP->getFirstPairPower();

        if ( powerFirst1 == powerFirst2 )
        {
            int powerSecond1 = p1TP->getSecondPairPower();
            int powerSecond2 = p2TP->getSecondPairPower();

            if ( powerSecond1 == powerSecond2 )
            {
                int fifthPower1 = p1TP->getFifthPower();
                int fifthPower2 = p2TP->getFifthPower();

                if ( fifthPower1 == fifthPower2 )
                {
                    // no winner //
                }
                else if ( fifthPower1 > fifthPower2 )
                    return 1;
                else if ( fifthPower2 > fifthPower1 )
                    return 2;
            }
            else if ( powerSecond1 > powerSecond2 )
                return 1;
            else if ( powerSecond2 > powerSecond1 )
                return 2;
        }
        else if ( powerFirst1 > powerFirst2 )
            return 1;
        else if ( powerFirst2 > powerFirst1 )
            return 2;
    }
    else if ( p1TP != nullptr )
        return 1;
    else if ( p2TP != nullptr )
        return 2;

    return 0;
}

int Poker::getOnePairWinner( Hand& p1, Hand& p2 )
{
    Hand::OnePair* p1OP = p1.getOnePair();
    Hand::OnePair* p2OP = p2.getOnePair();

    if ( p1OP != nullptr && p2OP != nullptr )
    {
        int powerPair1 = p1OP->getPairPower();
        int powerPair2 = p2OP->getPairPower();

        if ( powerPair1 == powerPair2 )
        {
            int powerThird1 = p1OP->getThirdPower();
            int powerThird2 = p2OP->getThirdPower();

            if ( powerThird1 == powerThird2 )
            {
                int powerFourth1 = p1OP->getFourthPower();
                int powerFourth2 = p2OP->getFourthPower();

                if ( powerFourth1 == powerFourth2 )
                {
                    int fifthPower1 = p1OP->getFifthPower();
                    int fifthPower2 = p2OP->getFifthPower();

                    if ( fifthPower1 == fifthPower2 )
                    {
                        // no winner //
                    }
                    else if ( fifthPower1 > fifthPower2 )
                        return 1;
                    else if ( fifthPower2 > fifthPower1 )
                        return 2;
                }
                else if ( powerFourth1 > powerFourth2 )
                    return 1;
                else if ( powerFourth2 > powerFourth1 )
                    return 2;
            }
            else if ( powerThird1 > powerThird2 )
                return 1;
            else if ( powerThird2 > powerThird1 )
                return 2;
        }
        else if ( powerPair1 > powerPair2 )
            return 1;
        else if ( powerPair2 > powerPair1 )
            return 2;
    }
    else if ( p1OP != nullptr )
        return 1;
    else if ( p2OP != nullptr )
        return 2;

    return 0;
}

int Poker::getHighestCardWinner( Hand& p1, Hand& p2 )
{
    int high11 = p1.getBestCardPower(1);
    int high12 = p2.getBestCardPower(1);

    if ( high11 == high12 )
    {
        int high21 = p1.getBestCardPower(2);
        int high22 = p2.getBestCardPower(2);

        if ( high21 == high22 )
        {
            int high31 = p1.getBestCardPower(3);
            int high32 = p2.getBestCardPower(3);

            if ( high31 == high32 )
            {
                int high41 = p1.getBestCardPower(4);
                int high42 = p2.getBestCardPower(4);

                if ( high41 == high42 )
                {
                    // no winner - should never be here//
                }
            }
            else if ( high31 > high32 )
                return 1;
            else
                return 2;
        }
        else if ( high21 > high22 )
            return 1;
        else
            return 2;
    }
    else if ( high11 > high12 )
        return 1;
    else
        return 2;

    return 0;	// should never be here //
}

int Poker::getWinner( Hand& p1, Hand& p2 )
{
    int winner;
    if ( (winner = checkRoyalFlush( p1, p2 )) > 0 )
    {
//			System.out.print("RoyalFlush: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    if ( (winner = checkStraightFlush( p1, p2 )) > 0 )
    {
//			System.out.print("StraightFlush: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    if ( (winner = getFourOfAKindWinner( p1, p2 )) > 0 )
    {
//			System.out.print("FourOfAKind: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }
//    for ( int i = 0; i < p1->mCards.size(); ++i )
//    {
//        std::cout << p1->mCards[i].getCard() << std::endl;
//    }
//
    if ( (winner = getFullHouseWinner( p1, p2 )) > 0 )
    {
//			System.out.print("FullHouse: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }
    if ( (winner = getFlushWinner( p1, p2 )) > 0 )
    {
//			System.out.print("Flush: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    if ( (winner = getStrightWinner( p1, p2 )) > 0 )
    {
//			System.out.print("Stright: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    if ( (winner = getThreeOfAKindWinner( p1, p2 )) > 0 )
    {
//			System.out.print("ThreeOfAKind: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    if ( (winner = getTwoPairWinner( p1, p2 )) > 0 )
    {
//			System.out.print("TwoPair: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    if ( (winner = getOnePairWinner( p1, p2 )) > 0 )
    {
//			System.out.print("OnePair: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");;
        return winner;
    }

    if ( (winner = getHighestCardWinner( p1, p2 )) > 0 )
    {
//			System.out.print("HighestCard: P" + winner + " (");
//			p1.printHand();
//			System.out.print(" : ");
//			p2.printHand();
//			System.out.println(")");
        return winner;
    }

    return 0;
}

int Poker::getPlayer1Wins( std::string fileName )
{
    int player1Wins = 0;
    int player2Wins = 0;

    std::ifstream file(fileName);

    try
    {
        std::string line;
        while ( std::getline(file, line) )
        {
            Hand player1;
            Hand player2;

            std::stringstream ss(line);
            std::vector<std::string> fields;

            for ( int i = 0; i < 10; ++i )
            {
//                    std::cout << "ASD" << std::endl;
                std::string s;
                ss >> s;
                fields.push_back( s );
//                std::cout << s << std::endl;
            }

//				if ( fields.length != 10 )
//				{
//					throw new Exception("More than 10 cards");
////					System.out.println("ERROR");
//				}

            try
            {
                for ( int i = 0; i < 5; ++i )
                    player1.addCard( Card(fields[i]) );
                for ( int i = 5; i < 10; ++i )
                    player2.addCard( Card(fields[i]) );
            }
            catch ( std::exception e )
            {
                throw e;
            }

            int winner = getWinner( player1, player2 );
            if ( winner == 1 )
                ++player1Wins;
            else if ( winner == 2 )
                ++player2Wins;
            else
            {
                // ERROR //
            }
        }
    }
    catch ( std::exception e )
    {

    }

//    	System.out.println( player1Wins + " : " + player2Wins );
    return player1Wins;
}





























