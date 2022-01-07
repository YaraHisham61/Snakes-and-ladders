#include"CardEleven.h"

CardEleven::CardEleven(const CellPosition& pos) : Card(pos)
{
	counter = 0;
	cardNumber = 9;

}
int CardEleven::fees = 0;
int CardEleven::cardprice = 0;
bool CardEleven::counter = true;
Player* CardEleven::Pplayer1 = NULL;

void CardEleven::ReadCardParameters(Grid* pGrid)
{
	if (getpriceandfees(cardprice, fees, cardNumber, counter, pGrid) && counter)
	{
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("the card parameters are read");
		counter = false;
	}
}

void CardEleven::Apply(Grid* pGrid, Player* pPlayer)
{
	apply9to11(pGrid, pPlayer, Pplayer1, cardprice, fees);
}

CardEleven::~CardEleven()
{
}

