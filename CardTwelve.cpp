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
}

void CardTwelve::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer); //Calling Apply() of the base class Card to print a message that you reached this card number
	pPlayer=pGrid->GetCurrentPlayer();
	int MostExpensiveStation=-1;
	int y = 0;
	Card* OwnedStations[3];
	if (CardNine::getowner() == pPlayer)
	{
		MostExpensiveStation = CardNine::getcardprice();
	}
	if (CardTen::getowner() == pPlayer)
	{
		if (MostExpensiveStation < CardTen::getcardprice())
		{
			MostExpensiveStation = CardTen::getcardprice();
			y = 1;
		}
	}
	if (CardEleven::getowner() == pPlayer)
	{
		if (MostExpensiveStation < CardEleven::getcardprice())
		{
			MostExpensiveStation = CardEleven::getcardprice();
			y = 2;
		}
	}
	switch (y)
	{
		case 0:
		{
			CardNine::setowner(pGrid->GetLeastWallet());
			break;
		}
		case 1:
		{
			CardTen::setowner(pGrid->GetLeastWallet());
			break;
		}
		case 2:
		{
			CardEleven::setowner(pGrid->GetLeastWallet());
			break;
		}

	}
}

CardTwelve::~CardTwelve()
{
}
