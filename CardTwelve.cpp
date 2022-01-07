#include "CardTwelve.h"

CardTwelve::CardTwelve(const CellPosition& pos):Card(pos)  // set the cell position of the card
{
	cardNumber = 12;  // set the inherited cardNumber data
}

void CardTwelve::ReadCardParameters(Grid* pGrid)
{
	/*
		This card's class has no data members
		so we don't need any input from the user
	*/
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardTwelve: Your most expensive station will belong to the player has the least amount of coins in his wallet");  //Printing to a descriptive message to the user
	pOut->ClearStatusBar();
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); //Calling Apply() of the base class Card to print a message that you reached this card number
	
}

CardTwelve::~CardTwelve()
{
}
