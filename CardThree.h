#pragma once
#include "Card.h"

/* [ CardThree ] Summary:
	Its Apply() Function: Gives an extra dice roll for the current player
	Its Parameters: It has no parameters/data members
*/

class CardThree : public Card
{
public:
	CardThree(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardThree();
};
