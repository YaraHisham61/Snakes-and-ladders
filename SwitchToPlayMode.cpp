#include "SwitchToPlayMode.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
#include "Player.h"
SwitchToPlayMode::SwitchToPlayMode(ApplicationManager* pApp) :Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

SwitchToPlayMode::~SwitchToPlayMode()
{
}

void SwitchToPlayMode::ReadActionParameters() // Reads parameters required for action to execute 
{


}

void SwitchToPlayMode::Execute()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	for (int i = 0; i < 4; i++)
	{
		Player* player = pGrid->GetCurrentPlayer();
		player->SetWallet(100);
		player->SetturnCount(0);
		pGrid->AdvanceCurrentPlayer();

	}
	pGrid->SetCurrentplayer(0);
	pOut->CreatePlayModeToolBar();

}
