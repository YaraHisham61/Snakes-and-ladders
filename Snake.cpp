#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() != -1 || endCellPos.VCell() != -1)
		this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}

bool Snake::overlappingsnake(GameObject* Obj)// to check if 2 snakes overlap each other
{
	Snake* newSnake = dynamic_cast<Snake*>(Obj);
	if (position.HCell() == newSnake->GetPosition().HCell())// the snake are vertical so they must have same hcell to check if they may overlap
	{
		if (newSnake)
		{
			if (position.VCell() <= newSnake->endCellPos.VCell() && newSnake->position.VCell() <= endCellPos.VCell())//the condition of overlapping
				return true;
		}
	}
	return false;
	//the fucntion return true if the two snakes overlap and false if they dont
}



void Snake::Draw(Output* pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);

}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}
