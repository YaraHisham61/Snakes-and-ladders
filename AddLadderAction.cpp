#include "AddLadderAction.h"

#include "Input.h"
#include "Output.h"
#include "Ladder.h"

AddLadderAction::AddLadderAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddLadderAction::~AddLadderAction()
{
}

void AddLadderAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Ladder: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.IsValidCell()==false)
	{
		pOut->PrintMessage(" the clicked start cell is invalid");
		return;
	}

	// Read the endPos parameter
	pOut->PrintMessage("New Ladder: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (endPos.IsValidCell() == false)
	{
		pOut->PrintMessage("the clicked cell is invalid end cell");
		return;
	}
	Ladder isladder(startPos, endPos);

	///TODO: Make the needed validations on the read parameters
	if (startPos.GetCellNumFromPosition(startPos) >= endPos.GetCellNumFromPosition(endPos)) 
	{
		pOut->PrintMessage("the start cell is smaller than end cell");
		return;
	}

	if (startPos.VCell() == 0)
	{
		pOut->PrintMessage("the start cell can not be in the first row");
		return;
	}
	if (startPos.HCell() != endPos.HCell())
	{
		pOut->PrintMessage("the ladder cells must be in the same coulomn");
		return;
	}
	pGrid->overlapping(&isladder);

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddLadderAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a Ladder object with the parameters read from the user
	Ladder * pLadder = new Ladder(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pLadder);

	// if the GameObject cannot be added
	if (! added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
