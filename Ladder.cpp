#include "Ladder.h"

Ladder::Ladder(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() != -1 || endCellPos.VCell() != -1)
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
//bool Ladder::risingladder(CellPosition& startCellPos, CellPosition& endCellPos)
//{
//	if (startCellPos.GetCellNumFromPosition(startCellPos) < endCellPos.GetCellNumFromPosition(endCellPos))
//		return true;
//	else
//		return false;
//
//}
//
//bool Ladder::verticalladder(CellPosition& startCellPos, CellPosition& endCellPos)
//{
//	if (startCellPos.HCell() == endCellPos.HCell())
//		return true;
//	return false;
//}
//
//bool Ladder::validstartladdercell(CellPosition& startCellPos)
//{
//	if (startCellPos.VCell() == 0)
//		return false;
//	return true;
//}

bool Ladder::overlappingladder(GameObject* Obj)
{
	Ladder* newladder = dynamic_cast<Ladder*>(Obj);
	if (newladder)
	{
		if (position.HCell() == newladder->GetPosition().HCell())
		{
			for (int i = endCellPos.VCell(); i >= position.VCell(); i--) // to allocate cells from bottom up
			{
				if (i == newladder->GetPosition().VCell() || i == newladder->GetEndPosition().VCell())
				{
					return true;
				}
			}
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

void Ladder::Save(ofstream& OutFile, int type, string file)
{
	if (type == 0)
	{
		OutFile << position.GetCellNum() << "   " << endCellPos.GetCellNum() << endl;
	}
	else
		return;
}

void Ladder::Load(ifstream& infile, int type, string file)
{
	if (type == 0)
	{
		int cellnum, endcellnum;
		infile >> cellnum >> endcellnum;
		position = CellPosition::GetCellPositionFromNum(cellnum);
		endCellPos = CellPosition::GetCellPositionFromNum(endcellnum);
	}
}

Ladder::~Ladder()
{
}
