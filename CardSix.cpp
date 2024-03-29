#include "CardSix.h"

CardSix::CardSix(const CellPosition& pos):Card(pos)  // set the cell position of the card
{
	cardNumber = 6;  // set the inherited cardNumber data member with the card number (6 here)
}

void CardSix::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New Card six: Please click on a cell to move to ");  //Printing to a descriptive message to the user
	tocell = pIn->GetCellClicked(); //Setting the postion to the cell the user clicked on
	while (!(tocell.IsValidCell())) //Checking if the user clicked on a valid cell?
	{
		pOut->PrintMessage("Invalid cell, please click on valid cell to move to  ");
		tocell = pIn->GetCellClicked();
	}
	pOut->ClearStatusBar(); //Clearing the status bar 
}

void CardSix::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->UpdatePlayerCell(pPlayer, tocell); //Moving the player to the cell he clicked on

	GameObject* pGameObject = pPlayer->GetCell()->GetGameObject(); //Checking if the new cell has a game object to apply?
	if (pGameObject)
	{

		pGameObject->Apply(pGrid, pPlayer);
	}
}

CardSix::~CardSix()
{
}
