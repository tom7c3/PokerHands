#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include "Hand.h"

class Poker
{
  public:

	int checkRoyalFlush( Hand& p1, Hand& p2 );
	int checkStraightFlush( Hand& p1, Hand& p2 );
	int getFourOfAKindWinner( Hand& p1, Hand& p2 );\
	int getFullHouseWinner( Hand& p1, Hand& p2 );
	int getFlushWinner( Hand& p1, Hand& p2 );
	int getStrightWinner( Hand& p1, Hand& p2 );
	int getThreeOfAKindWinner( Hand& p1, Hand& p2 );
	int getTwoPairWinner( Hand& p1, Hand& p2 );
	int getOnePairWinner( Hand& p1, Hand& p2 );
	int getHighestCardWinner( Hand& p1, Hand& p2 );
	int getWinner( Hand& p1, Hand& p2 );

//	@Test
//	public void test()
//	{
//		System.out.println("THIS IS TEST");
//		try
//		{
//			Card card = new Card("ADE");
//			assertEquals("ASDASD", true, card.isAce());
//			card = new Card("5D");
//			assertEquals("ASDASD", false, card.isAce());
//		}
//		catch( Exception e )
//		{
//			System.out.println(e);
//		}
//	}

	int getPlayer1Wins( std::string fileName );

//	public static void main(String[] args) throws Exception
//	{
//		System.out.println( getPlayer1Wins("poker.txt") );
//	}

//	@Test
//	public void shouldReturn3()
//	{
//		try
//		{
//			assertEquals(3, getPlayer1Wins("test1.txt") );
//		}
//		catch ( Exception e )
//		{
//			fail(e.getMessage());
//		}
//	}
//
//	@Rule
//	public ExpectedException exception = ExpectedException.none();
//
//	@Test
//	public void shouldThrowUnknownCardSuit() throws Exception
//	{
//		exception.expect(Exception.class);
//	    exception.expectMessage("Unknown card suit");
//
//	    getPlayer1Wins("test2.txt");
//	}
//
//	@Test
//	public void shouldThrowUnknownCardType() throws Exception
//	{
//		exception.expect(Exception.class);
//	    exception.expectMessage("Unknown card type");
//
//	    getPlayer1Wins("test3.txt");
//	}
//
//	@Test
//	public void shouldThrowMoreThan10Cards() throws Exception
//	{
//		exception.expect(Exception.class);
//	    exception.expectMessage("More than 10 cards");
//
//	    getPlayer1Wins("test4.txt");
//	}
//
//	@Test
//	public void shouldThrowBadCardName() throws Exception
//	{
//		exception.expect(Exception.class);
//	    exception.expectMessage("bad card name");
//
//	    getPlayer1Wins("test5.txt");
//	}
//
//	@Test
//	public void shouldThrowFileNotFound() throws Exception
//	{
//		exception.expect(FileNotFoundException.class);
//	    //exception.expectMessage("bad card name");
//
//	    getPlayer1Wins("notFoundFile");
//	}


};
