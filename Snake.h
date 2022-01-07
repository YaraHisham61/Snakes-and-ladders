#pragma once

#include "GameObject.h"

class Snake : public GameObject // inherited from GameObject
{
	

	CellPosition endCellPos; // snake end cell

public:

	Snake(const CellPosition& startCellPos, const CellPosition& endCellPos); // A constructor for initialization
	/*bool decliningsnake(CellPosition& startCellPos, CellPosition& endCellPos);
	bool verticalsnake(CellPosition& startCellPos, CellPosition& endCellPos);
	bool validstartcell(CellPosition& startCellPos);*/
	bool overlappingsnake(GameObject* Obj);
	/*bool endcellobject(GameObject* Obj);*/


	virtual void Draw(Output* pOut) const; // Draws a snake from its start cell to its end cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the snake by moving player to snake's end cell

	CellPosition GetEndPosition() const; // A getter for the endCellPos data member

	virtual ~Snake(); // Virtual destructor
};
