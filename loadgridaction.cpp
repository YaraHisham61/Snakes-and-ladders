#include "loadgridaction.h"
#include"Action.h"
#include"Grid.h"
#include"fstream"
loadgridaction::loadgridaction(ApplicationManager* pApp):Action(pApp)
{
}

void loadgridaction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("enter file name to load from: ");
	file = pIn->GetSrting(pO) + ".txt";
}

void loadgridaction::Execute()
{
	ReadActionParameters();
		ifstream infile;
	infile.open("test.txt", ios::in);
	if (infile.is_open())
	{
		pManager->GetGrid()->LoadAll(infile, 0, file);
		pManager->GetGrid()->LoadAll(infile, 1, file);
		pManager->GetGrid()->LoadAll(infile, 2, file);
		infile.close();
		Grid* pGrid = pManager->GetGrid();
		Output* pO = pManager->GetGrid()->GetOutput();
		pO->PrintMessage("load finish");
		//pO->ClearStatusBar();

	}
	else
		pManager->GetGrid()->PrintErrorMessage("Error to load file");
}

loadgridaction::~loadgridaction()
{
}
