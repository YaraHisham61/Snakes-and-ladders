#pragma once
#include "Player.h"
#include "Card.h"

// [ CardOne ] Summary:
// Its Apply() Function: Decrements the value of the passing player�s wallet by a value
// Its Parameters: The Wallet Value to decrease --> put it as a "data member" and read it in ReadCardParameters()

class CardNine : public Card
{
	// CardOne Parameters:
	static int cardprice;
	static int fees;
	 static bool counter;

public:
	static Player* Pplayer1;

	CardNine(const CellPosition& pos); // A Constructor takes card position

	virtual void ReadCardParameters(Grid* pGrid); // Reads the parameters of CardOne which is: walletAmount

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applies the effect of CardOne on the passed Player
													  // by decrementing the player's wallet by the walletAmount data member

	virtual ~CardNine(); // A Virtual Destructor
};