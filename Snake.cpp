#include "Snake.h"

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	if (endCellPos.HCell() != -1 || endCellPos.VCell() != -1)
		this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
//bool Snake::decliningsnake(CellPosition& startCellPos, CellPosition& endCellPos)
//{
//	if (startCellPos.GetCellNumFromPosition(startCellPos) > endCellPos.GetCellNumFromPosition(endCellPos))
//		return true;
//	else
//		return false;
//
//}
//
//bool Snake::verticalsnake(CellPosition& startCellPos, CellPosition& endCellPos)
//{
//	if (startCellPos.HCell() == endCellPos.HCell())
//		return true;
//	return false;
//}
//
//bool Snake::validstartcell(CellPosition& startCellPos )
//{
//	if (startCellPos.VCell() == 8)
//		return false;
//	return true;
//}

bool Snake::overlappingsnake(GameObject* Obj)
{
	Snake* newSnake = dynamic_cast<Snake*>(Obj);
	if (newSnake)
	{
		if (position.HCell() == newSnake->GetPosition().HCell())
		{
			for (int i = endCellPos.VCell(); i >= position.VCell(); i--) // to allocate cells from bottom up
			{
				if (i == newSnake->GetPosition().VCell() || i == newSnake->GetEndPosition().VCell())
				{
					return true;
				}
			}
		}

	}
	return false;
}

//bool Snake::endcellobject(GameObject* Obj)
//{
//	Snake* newSnake = dynamic_cast<Snake*>(Obj);
//	if (newSnake)
//	{if(endCellPos.)
//		///to check if the end cell of a snake is the start cell of another object
//	
//	return false;
//}

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

void Snake::Save(ofstream& OutFile, int type, string file)
{
		if (type == 1)
		{
			OutFile << position.GetCellNum() << "   " << endCellPos.GetCellNum() << endl;
		}
		else
			return;
}

void Snake::Load(ifstream& infile, int type, string file)
{
	if (type == 1)
	{
		int cellnum, endcellnum;
		infile >> cellnum >> endcellnum;
		position = CellPosition::GetCellPositionFromNum(cellnum);
		endCellPos = CellPosition::GetCellPositionFromNum(endcellnum);
	}
}

Snake::~Snake()
{
}
