#include "DeleteGameObject.h"
#include "Input.h"
#include "Output.h"
#include "Grid.h"
DeleteGameObject::DeleteGameObject(ApplicationManager* pApp):Action(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

DeleteGameObject::~DeleteGameObject()
{
}

 void DeleteGameObject::ReadActionParameters() // Reads parameters required for action to execute 
 {

	 Grid* pGrid = pManager->GetGrid();
	 Output* pOut = pGrid->GetOutput();
	 Input* pIn = pGrid->GetInput();
	 pOut->PrintMessage("please select the cell to delete its gameobject");
	  deletecell = pIn->GetCellClicked();
	 if (deletecell.IsValidCell() == false)
	 {
		 pOut->PrintMessage("the selected cell is invalid");
		 return;
	 }
 }

 void DeleteGameObject::Execute()
 {
	 ReadActionParameters();
	 Grid* pGrid = pManager->GetGrid();
	 pGrid->RemoveObjectFromCell(deletecell);

 }