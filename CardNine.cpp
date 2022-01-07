#include"CardNine.h"

CardNine::CardNine(const CellPosition& pos): Card(pos)
{ 
	cardNumber = 9;
	
}

int CardNine::fees = 0;
int CardNine::cardprice = 0;
bool CardNine::counter = true;
Player* CardNine::Pplayer1 = NULL;

void CardNine::ReadCardParameters(Grid* pGrid)
{
if (getpriceandfees(cardprice, fees, cardNumber, counter, pGrid)&&counter)
{
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("the card parameters are read");
	counter = false;
	}
	
}

void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	apply9to11(pGrid, pPlayer,  Pplayer1, cardprice, fees);	
}

CardNine::~CardNine()
{
}

