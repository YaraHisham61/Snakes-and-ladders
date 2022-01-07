#include "NewGameAction.h"
#include"Action.h"
#include"Player.h"
#include"Grid.h"
#include"CardEleven.h"
#include"CardNine.h"
#include"CardTen.h"
#include"DeleteGameObject.h"
#include"Player.h"
#include"Grid.h"
#include"Cell.h"
NewGameAction::NewGameAction(ApplicationManager* pApp):Action(pApp)
{
}

void NewGameAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pin = pGrid->GetInput();
	Output* pout = pGrid->GetOutput();
	pin->GetCellClicked();
	pout->ClearStatusBar();
}

void NewGameAction::Execute()
{
	ReadActionParameters();
	CardNine::Pplayer1 = NULL;
	CardEleven::Pplayer1 = NULL;
	CardTen::Pplayer1 = NULL;

	Grid* pGrid = pManager->GetGrid();
	Input* inp = pGrid->GetInput();
	Output* out = pGrid->GetOutput();
	CellPosition StartCell(1);
	for (size_t i = 0; i < 4; i++)
	{
		Player *p = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(p, StartCell);
		p->setturncount(0);
		pGrid->AdvanceCurrentPlayer();

	}

}

NewGameAction::~NewGameAction()
{
}
