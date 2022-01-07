#include "inputDiceValueAction.h"
#include"Grid.h"
#include"Player.h"
inputDiceValueAction::inputDiceValueAction(ApplicationManager* pApp):Action(pApp)
{

}

void inputDiceValueAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pout->PrintMessage("please enter a dice value between 1-6");
	dicenum = pin->GetInteger(pout);
	pout->ClearStatusBar();

}

void inputDiceValueAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (dicenum>0&&dicenum<=6)
	{
		if (pGrid->GetEndGame())
		{
			return;
		}
		Player* pl = pGrid->GetCurrentPlayer();
		pl->Move(pGrid, dicenum);
		pGrid->AdvanceCurrentPlayer();
	}
	else
	{
		pGrid->PrintErrorMessage("Invalid dice number, operation cancelled");
		return;
	}


}

inputDiceValueAction::~inputDiceValueAction()
{
}
