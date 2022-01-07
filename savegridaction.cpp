#include "savegridaction.h"
#include"Action.h"
#include"Grid.h"
#include<fstream>
savegridaction::savegridaction(ApplicationManager* pApp):Action(pApp)
{
}

void savegridaction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pManager->GetGrid()->GetInput();
	Output* pO = pManager->GetGrid()->GetOutput();
	pO->PrintMessage("enter file name : ");
	file = pIn->GetSrting(pO) + ".txt";
}

void savegridaction::Execute()
{
	ReadActionParameters();
	ofstream OutFile;
	OutFile.open("test.txt", ios::out);
	if (OutFile.is_open())
	{
		pManager->GetGrid()->SaveAll(OutFile, 0, file);
		pManager->GetGrid()->SaveAll(OutFile, 1, file);
		pManager->GetGrid()->SaveAll(OutFile, 2, file);
		OutFile.close();
		Grid* pGrid = pManager->GetGrid();
		Output* pO = pManager->GetGrid()->GetOutput();
		pO->PrintMessage("save finish");
		//pO->ClearStatusBar();
	}
	else
		pManager->GetGrid()->PrintErrorMessage("Error to save file");
}


savegridaction::~savegridaction()
{
}
