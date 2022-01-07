#include "SwitchToPlayMode.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
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
	pOut->CreatePlayModeToolBar();

}