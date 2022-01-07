#pragma once
#include "Card.h"
class CardSix : public Card
{
	CellPosition tocell;
public:
	CardSix(const CellPosition& pos);
	virtual void ReadCardParameters(Grid* pGrid);
	virtual void Apply(Grid* pGrid, Player* pPlayer);
	virtual ~CardSix();
};

