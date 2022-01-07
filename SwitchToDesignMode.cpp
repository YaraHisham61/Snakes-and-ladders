#include "SwitchToDesignMode.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
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
	pOut->CreateDesignModeToolBar();
}