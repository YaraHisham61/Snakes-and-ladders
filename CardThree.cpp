#include "CardThree.h"

CardThree::CardThree(const CellPosition& pos):Card(pos)   // set the cell position of the card
{
	cardNumber = 3;   // set the inherited cardNumber data member with the card number (3 here)
}

void CardThree::ReadCardParameters(Grid* pGrid)
{
	/*
		This card's class has no data members
		so we don't need any input from the user
	*/

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardThree: You will get an extra dice roll");   //Printing to a descriptive message to the user
	pOut->ClearStatusBar();   //Clearing the status bar 
}

void CardThree::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);   //Calling Apply() of the base class Card to print a message that you reached this card number
	for (int i = 0;i < MaxPlayerCount - 1;i++)
	{
		pGrid->AdvanceCurrentPlayer();  //Giving the player extra dice roll by increasing players count
	}
}

CardThree::~CardThree()
{
}
