#include "CutCard.h"
#include"Grid.h"
CutCard::CutCard(ApplicationManager* pApp) : Action(pApp) // A Constructor
{

}

void CutCard::ReadActionParameters() // Reads AddCardAction action parameters ( cardPosition)
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("click on the cell");
	cardcell = pIn->GetCellClicked();
	if (!cardcell.IsValidCell())
	{
		pOut->PrintMessage("the clicked card cell is invalid");
		return;
	}
	pOut->ClearStatusBar();
}

void CutCard::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if (pGrid->GetCard(cardcell) != NULL)
	{
		pGrid->SetClipboard(pGrid->GetCard(cardcell));
		pGrid->RemoveObjectFromCell(cardcell);
	}

	else
		pGrid->PrintErrorMessage("the selected cell has no card object");

}

CutCard:: ~CutCard()
{

}