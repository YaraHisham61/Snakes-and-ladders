#include "SwitchToDesignMode.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "CardEleven.h"
#include "CardNine.h"
#include "CardTen.h"
SwitchToDesignMode::SwitchToDesignMode(ApplicationManager* pApp) :Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

SwitchToDesignMode::~SwitchToDesignMode()
{
}

void SwitchToDesignMode::ReadActionParameters() // Reads parameters required for action to execute 
{

	
}

void SwitchToDesignMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut=pGrid->GetOutput();
	pOut->ClearStatusBar();
	pOut->CreateDesignModeToolBar();
	CardTen::Pplayer1 = NULL;
	CardEleven::Pplayer1 = NULL;
	CardNine::Pplayer1 = NULL;
	
	CellPosition StartCell(1);
	for (int i = 0; i < 4; i++)
	{
		Player* player = pGrid->GetCurrentPlayer();
		pGrid->UpdatePlayerCell(player, StartCell);
		player->SetturnCount(0);
		pGrid->AdvanceCurrentPlayer();

	}
}
