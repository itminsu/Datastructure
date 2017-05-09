#include <conio.h>
#include <fstream>
#include <regex>
#include "LinkedList.h"

int GetNumber(int whichNumber, string command, int currentLine)
{
	string num = "";
	int spaces = 0;

	//Loop through each char in the command
	for (char& c : command)
	{
		if (c == ' ')
			++spaces;
		else if (whichNumber == 1 && spaces <= 1 && isdigit(c))
			num += c;
		else if (whichNumber == 2 && spaces == 2 && isdigit(c))
			num += c;
	}
	if (num == "")
		return currentLine;
	else
		return stoi(num);
}

void RunCommand(string command, int currentLine, LinkedList& list)
{

	//Regex search strings
	//INSERT
	regex cmdI("[I,i]");
	regex cmdIn("[I,i] [0-9]+");
	//DELETE
	regex cmdD("[D,d]");
	regex cmdDn("[D,d] [0-9]+");
	regex cmdDnn("[D,d] [0-9]+ [0-9]+");
	//VIEW
	regex cmdV("[V,v]");
	//GOTO
	regex cmdG("[G,g]");
	regex cmdGn("[G,g] [0-9]+");
	//LIST
	regex cmdL("[L,l]");
	regex cmdLn("[L,l] [0-9]+");
	regex cmdLnn("[L,l] [0-9]+ [0-9]+");
	//SUBSTITUTE
	regex cmdS("[S,s]");
	regex cmdSn("[S,s] [0-9]+");

	//insert
	if (regex_match(command, cmdIn))
	{
		int num = GetNumber(1, command, currentLine);
		string inputString;
		cout << "Insert at line " << num << " > ";
		getline(cin, inputString);
		list.Insert(inputString, num);
	
		//show the list
		list.View();
	}
	else if (regex_match(command, cmdI))
	{
		string inputString;
		cout << "Insert at line " << currentLine << " > ";
		getline(cin, inputString);
		list.Insert(inputString, currentLine);

		//show the list
		list.View();
	}

	//delete range
	else if (regex_match(command, cmdDnn))
	{
		int number1 = GetNumber(1, command, currentLine);
		int number2 = GetNumber(2, command, currentLine);
		list.Delete(number1, number2);
		list.View();
	}

	//delete number
	else if (regex_match(command, cmdDn))
	{
		int number = GetNumber(1, command, currentLine);
		list.Delete(number);
		list.View();
	}
	//Delete node
	else if (regex_match(command, cmdD))
	{	
		list.Delete(currentLine);
		list.View();
	}
	//view list
	else if (regex_match(command, cmdV))
	{
		system("cls");
		list.View();
	}
	//substitute number
	else if (regex_match(command, cmdSn))
	{
		int num = GetNumber(1, command, currentLine);
		string inputString;
		cout << "Substitute at line " << num << " > ";
		getline(cin, inputString);
		list.Substitute(inputString, num);

		list.View();
	}
	else if (regex_match(command, cmdS))
	{
		string inputString;
		cout << "Substitute at line " << currentLine << " > ";
		getline(cin, inputString);
		list.Substitute(inputString, currentLine);

		list.View();
	}
	else if (regex_match(command, cmdLnn))
	{
		int number1 = GetNumber(1, command, currentLine);
		int number2 = GetNumber(2, command, currentLine);
		system("cls");

		list.View(number1, number2);
	}
	else if (regex_match(command, cmdLn))
	{
		int num = GetNumber(1, command, currentLine);
		system("cls");

		list.View(num);
	}
	else if (regex_match(command, cmdL))
	{
		system("cls");

		list.View(currentLine);
	}
	else
	{
		system("cls");

		//show the list
		list.View();
		cout << "\t[INVALID COMMAND]" << endl;
	}

}

void guideline()
{
	cout << "(Q:Quit, E:Exit(with Save), I:Insert, L:List, G:GoTo, S:Substitute, D:Delete, V:ViewList) " << endl;
}

int main(int argc, char* argv[])
{
	string inputFile;
	string outputFile;

	int currentLine = 1;

	if (argc == 3)
	{
		inputFile = argv[1];
		outputFile = argv[2];
	}
	else
	{
		cout << "Entered File path is wrong!! Please check file path!!";
		return 0;
	}

	//string inputFile;
	//string outputFile;
	////set up a variable to hold the current line:
	//int currentLine = 1;

	//if (argc < 2) {
	//	cout << "You didn't input file path argument" << endl;
	//	return 0;
	//}
	//else {
	//	inputFile = argv[1];
	//	outputFile = argv[2];
	//}

	////Using regex for file path to store.
	//regex e("([a-zA-Z]\:)([\\\\][A-Za-z_\-\s0-9\ \.]+)+.txt");
	//regex_match(inputFile, e);
	//if (m.size() <= 0) {
	//	cout << "Entered File path is wrong!! Please check file path!!";
	//	_getch();
	//	return 0;
	//}


	//generate a linked list:
	LinkedList list;

	//set up an input file stream:
	ifstream inFile(inputFile);

	if (inFile)
	{
		string fileLine;
		int lineCounter = 1;

		while (getline(inFile, fileLine))
		{
			list.Insert(fileLine, lineCounter);

			++lineCounter;
		}
	}

	system("cls");

	//generate the list
	list.View();

	//enter the main loop of the edit program
	bool editLoop = true;
	while (editLoop)
	{
		string command;

		//Display current line

		guideline();
		cout << "CURRENT LINE [" << currentLine << "]\n" << "COMMAND > " << flush;
		getline(cin, command);

		regex cmdGn("[G,g] [0-9]+");
		regex cmdG("[G,g]");

		if (command == "q" || command == "Q")
		{
			editLoop = false;
		}
		else if (regex_match(command, cmdG))
		{
			system("cls");
			currentLine = 1;

			//show the list:
			list.View();
		}
		else if (regex_match(command, cmdGn))
		{
			system("cls");
			int number = GetNumber(1, command, currentLine);
			if (number > 0 && number <= list.listLength)
				currentLine = number;
			else
				cout << "\t[INVALID LINE NUMBER]" << endl;

			list.View();
		}
		else if (command == "e" || command == "E")
		{
			editLoop = false;

			ofstream outFile;
			outFile.open(outputFile);
			outFile << list;
			outFile.close();

		}
		else
		{
			RunCommand(command, currentLine, list);
		}
	}

	cout << "Close program." << endl;
	return 0;
}