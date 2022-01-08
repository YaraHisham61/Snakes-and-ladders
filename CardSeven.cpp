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
}

void CardSeven::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	Output* pOut = pGrid->GetOutput();
	pPlayer=pGrid->GetCurrentPlayer();
	Player* NextPlayer = pGrid->GetNextPlayer(pPlayer);
	if (NextPlayer)
	{
		CellPosition ncell(1);
		pGrid->UpdatePlayerCell(NextPlayer, ncell);
	}
	else
	{
		pOut->PrintMessage("No Players found ahead");
		pOut->ClearStatusBar();
	}
}

CardSeven::~CardSeven()
{
}
