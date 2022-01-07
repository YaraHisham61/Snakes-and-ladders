#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() != -1 || endCellPos.VCell() != -1)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}


bool Ladder::overlappingladder(GameObject* Obj)
{
	
	Ladder* newLadder = dynamic_cast<Ladder*>(Obj);
	if (position.HCell() == newLadder->GetPosition().HCell())// to check if the two ladders are in the same coulomn
	{
		if (newLadder)//if the newladder=null means that the cell has no ladder
		{
			if (position.VCell() >= newLadder->endCellPos.VCell() && newLadder->position.VCell() >= endCellPos.VCell())//to check the overlappin gog th eto ladders
				return true;
		}
	}
	return false;

		
}
void Ladder::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Ladder::Apply(Grid* pGrid, Player* pPlayer) 
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a ladder. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==
	
	// 1- Print a message "You have reached a ladder. Click to continue ..." and wait mouse click

	// 2- Apply the ladder's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	
}

CellPosition Ladder::GetEndPosition() const
{
	return endCellPos;
}

Ladder::~Ladder()
{
}
