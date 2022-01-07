#pragma once
#include "Card.h"
class CardSeven : public Card
{
	/* [ CardSeven ] Summary:
	Its Apply() Function:
	Its Parameters: It has no parameters/data members
	*/

public:
	CardSeven(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSeven();

};