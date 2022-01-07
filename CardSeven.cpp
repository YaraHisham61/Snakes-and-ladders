#include "CardSeven.h"

CardSeven::CardSeven(const CellPosition& pos):Card(pos) // set the cell position of the card
{
	cardNumber = 7;  // set the inherited cardNumber data member with the card number (7 here)
}

void CardSeven::ReadCardParameters(Grid* pGrid)
{
	/*
		This card's class has no data members
		so we don't need any input from the user
	*/

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardSeven: The next player in grid will restart the game");  //Printing to a descriptive message to the user
	pOut->ClearStatusBar();   //Clearing the status bar
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pPlayer=pGrid->GetCurrentPlayer();
	Player* nextPlayer=pGrid->GetNextPlayer(pPlayer);
	if (nextPlayer != NULL)
	{
		CellPosition ncell(1);
		pGrid->UpdatePlayerCell(nextPlayer, ncell);
	}
}

CardSeven::~CardSeven()
{
}
