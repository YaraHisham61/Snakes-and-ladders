#pragma once
#include "Card.h"

/* [ CardFour ] Summary:
	Its Apply() Function: 
	Its Parameters: It has no parameters/data members
*/

class CardFour : public Card
{
public:
	CardFour(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardFour();
};

