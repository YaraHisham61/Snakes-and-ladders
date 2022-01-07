#include "AddSnakeAction.h"

#include "Input.h"
#include "Output.h"
#include "Snake.h"

AddSnakeAction::AddSnakeAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddSnakeAction::~AddSnakeAction()
{
}

void AddSnakeAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New snake: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();
	if (startPos.IsValidCell()==false)
	{
		pOut->PrintMessage(" the clicked start cell is invalid");
		return;
	}

	// Read the endPos parameter
	pOut->PrintMessage("New snake: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();

	if (endPos.IsValidCell() == false)
	{
		pOut->PrintMessage("the clicked cell is invalid end cell");
		return;
	}
	Snake issnake(startPos, endPos);

	///TODO: Make the needed validations on the read parameters
	if (startPos.GetCellNumFromPosition(startPos) <= endPos.GetCellNumFromPosition(endPos))
	{
		pOut->PrintMessage("the start cell cant be bigger than end cell");
		return;
	}

	if (startPos.VCell() == 8)
	{
		pOut->PrintMessage("the start cell can not be in the first row");
		return;
	}
	if (startPos.HCell() != startPos.HCell())
	{
		pOut->PrintMessage("the snake cells must be in the same coulomn");
		return;
	}
	if (pGrid->overlapping(&issnake) == true)
	{
		pOut->PrintMessage("the snake cells must be overlapping");
		return;
	}

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddSnakeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();


	// Create a Ladder object with the parameters read from the user
	Snake* pSnake = new Snake(startPos, endPos);

	Grid* pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	if (pGrid->overlapping(pSnake) == true)
	{
		pGrid->PrintErrorMessage("the snake cells must be overlapping");
		return;
	}
	// Add the card object to the GameObject of its Cell:
	bool added = pGrid->AddObjectToCell(pSnake);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the ladder is created and added to the GameObject of its Cell, so we finished executing the AddLadderAction

}
