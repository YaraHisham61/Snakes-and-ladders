#pragma once
#include "Card.h"

/* [ CardTwelve ] Summary:
	Its Apply() Function:
	Its Parameters: It has no parameters/data members
*/

class CardTwelve : public Card
{

public:
	CardTwelve(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardTwelve();
};

