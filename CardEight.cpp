#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos):Card(pos) // set the cell position of the card
{
	cardNumber = 8;  // set the inherited cardNumber data member with the card number (8 here)
}

int CardEight::GetOutCoins = 0;

void CardEight::ReadCardParameters(Grid* pGrid)
{
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("New Card Eight: Enter the amount of coins to get out from the prison");
	GetOutCoins = pIn->GetInteger(pOut);
	pOut->ClearStatusBar();
}

void CardEight::Apply(Grid* pGrid, Player* pPlayer)
{
	int choice;
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	pPlayer = pGrid->GetCurrentPlayer();
	pOut->PrintMessage("If you want to stay in prison press 0, if you want to pay coins to get out press 1");
	choice = pIn->GetInteger(pOut);
	if (choice == 0)
	{
		pOut->PrintMessage("You will stay in prison for 3 turns");
		pPlayer->setgame(2);
	}
	else if(choice == 1)
	{
		if (pPlayer->GetWallet() > GetOutCoins)
		{
			pPlayer->SetWallet(pPlayer->GetWallet() - GetOutCoins);
		}
		else
		{
			pOut->PrintMessage("You don't have enough money to get out from prison");
			pOut->PrintMessage("You will stay in prison for 3 turns");
			pPlayer->setgame(2);
		}
	}
}

CardEight::~CardEight()
{
}

