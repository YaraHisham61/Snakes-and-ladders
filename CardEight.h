#pragma once
#include "Card.h"

/* [ CardEight ] Summary:
	Its Apply() Function:
	Its Parameters: It has no parameters/data members
*/

class CardEight : public Card
{
	static int GetOutCoins;

public:
	CardEight(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardEight();
};

