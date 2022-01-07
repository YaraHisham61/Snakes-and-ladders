#include "CardFour.h"

CardFour::CardFour(const CellPosition& pos) :Card(pos)  // set the cell position of the card
{
	cardNumber = 4;   // set the inherited cardNumber data member with the card number (4 here)
}

void CardFour::ReadCardParameters(Grid* pGrid)
{
	/*
		This card's class has no data members
		so we don't need any input from the user
	*/

	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardFour: You will be prevented frrom rolling the dice the next turn");  //Printing to a descriptive message to the user
	pOut->ClearStatusBar();   //Clearing the status bar 
}

void CardFour::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);  //Calling Apply() of the base class Card to print a message that you reached this card number
	//Not done yet
}

CardFour::~CardFour()
{
}
