#include "CardTwo.h"
#include"Ladder.h"

CardTwo::CardTwo(const CellPosition& pos):Card(pos)  // set the cell position of the card
{
	cardNumber = 2;  // set the inherited cardNumber data member with the card number (2 here)
}

void CardTwo::ReadCardParameters(Grid* pGrid)
{
	/*
		This card's class has no data members
		so we don't need any input from the user
	*/
	Output* pOut = pGrid->GetOutput();
	pOut->PrintMessage("New CardTwo: You will be moved to the next ladder (if found) ");  //Printing to a descriptive message to the user

	pOut->ClearStatusBar();  //Clearing the status bar
}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	pPlayer = pGrid->GetCurrentPlayer();
	Ladder* pLadder= pGrid->GetNextLadder(position);   //Searching for the next ladder postion in the grid
	if (pLadder == NULL)   
	{
		Output* pOut = pGrid->GetOutput();
		pOut->PrintMessage("No ladders found ahead");
		return;   //As no ladders found ahead, so we won't change the postion of the player
	}
	else
	{
		Card::Apply(pGrid, pPlayer);  //Calling Apply() of the base class Card to print a message that you reached this card number
		CellPosition NewPos = pLadder->GetPosition();  //Setting the new postion of the player to be the postion of the next ladder
		pGrid->UpdatePlayerCell(pPlayer, NewPos); //Moving the player to the new postion (start cell of the next ladder) 

		GameObject* pGameObject = pPlayer->GetCell()->GetGameObject();  //Checking if the new cell has a game object to apply?
		if (pGameObject)
		{

			pGameObject->Apply(pGrid, pPlayer);
		}
	}

}

CardTwo::~CardTwo()
{
}
