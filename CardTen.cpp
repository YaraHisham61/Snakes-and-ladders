#include"CardTen.h"

CardTen::CardTen(const CellPosition& pos) : Card(pos)
{ 
	cardNumber = 10;
	
}
int CardTen::fees = 0;
int CardTen::cardprice = 0;
bool CardTen::counter = true;
Player* CardTen::Pplayer1 = NULL;

void CardTen::ReadCardParameters(Grid* pGrid)
{
	if (getpriceandfees(cardprice, fees, cardNumber, counter, pGrid) && counter)
	{
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("the card parameters are read");
		counter = false;
	}
	
}

void CardTen::Apply(Grid* pGrid, Player* pPlayer)
{
	apply9to11(pGrid, pPlayer, Pplayer1, cardprice, fees);


}

CardTen::~CardTen()
{
}

