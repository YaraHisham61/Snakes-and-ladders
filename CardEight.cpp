#include "CardEight.h"

CardEight::CardEight(const CellPosition& pos):Card(pos) // set the cell position of the card
{
	cardNumber = 8;  // set the inherited cardNumber data member with the card number (8 here)
}

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
	static int count = 0;
	Card::Apply(pGrid, pPlayer);
	Input* pIn = pGrid->GetInput();
	Output* pOut = pGrid->GetOutput();
	Prisoner = pGrid->GetCurrentPlayer();
	pOut->PrintMessage("If you want to stay in prison press 0, if you want to pay coins to get out press 1");
	choice = pIn->GetInteger(pOut);
	switch (choice)
	{
	case 0:
	{
		pOut->PrintMessage("You will stay in prison for 3 turns");
	
			if (pPlayer == Prisoner&&count<3)
			{
				pPlayer->setgame(false);
				count++;
			}
		break;
	}
	case 1:
	{
		if (pPlayer->GetWallet() < GetOutCoins)
		{
			pOut->PrintMessage("You don't have enough money to get out from prison");
			/*
			NOT FINISHED YET
			*/
		}
		else
		{
			pOut->PrintMessage("You are out of prison");
			pPlayer->SetWallet(pPlayer->GetWallet() - GetOutCoins);
		}
		break;
	}
	}
}

CardEight::~CardEight()
{
}

