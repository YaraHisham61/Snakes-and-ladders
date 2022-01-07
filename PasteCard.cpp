#include "PasteCard.h"
#include"Grid.h"
#include "Card.h"
#include "Cell.h"
PasteCard::PasteCard(ApplicationManager* pApp) : Action(pApp) // A Constructor
{

}

void PasteCard::ReadActionParameters() // Reads AddCardAction action parameters ( cardPosition)
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

void PasteCard::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	if ((cardcell.GetCellNum() < 99 && cardcell.GetCellNum() > 1))
	{
		

			Card* pcard = pGrid->GetClipboard();
			if (!pcard)
			{
				pGrid->PrintErrorMessage("the cell already include a card and the past command in ignored");
					return;
			}
		pcard->SetPosition(cardcell);
			pGrid->AddObjectToCell(pcard);
	}
	else
	{
		pGrid->PrintErrorMessage("the starting and the ending cell cant include cards");
	}
}

PasteCard:: ~PasteCard()
{

}