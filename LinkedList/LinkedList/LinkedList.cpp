#include "LinkedList.h"

// Constructor 
LinkedList::LinkedList() {
	head = new Node;
	head->line = "HEAD NODE";
	head->next = NULL;
	listLength = 0;
}

// Destructor 
LinkedList::~LinkedList()
{
	Node* p = head;
	Node* q = head;
	while (listLength >= 0)
	{
		p = q;
		q = p->next;
		delete p;
		--listLength;
	}
}

void LinkedList::Insert(string line, int position)
{
	Node* newNode = new Node;
	newNode->line = line;

	//determine the position with range
	if (position <= 0 || position > listLength + 1)
	{
		system("cls");
		cout << "\t[LINE OUT OF RANGE]" << endl;
		return;
	}
	// if there is no next node
	if (!head->next)
	{
		//set the new Node
		head->next = newNode;
		++listLength;
		system("cls");
		cout << "\t[LINE " << position << " ADDED]" << endl;
		return;
	}

	int count = 0;
	Node* p = head;
	Node* q = head;

	while (q) // q == quit
	{
		if (count == position)
		{
			p->next = newNode;
			
			newNode->next = q;
			++listLength;
			system("cls");
			cout << "\t[LINE " << position << " ADDED]" << endl;
			return;
		}
		p = q;
		q = p->next;
		++count;
	}

	if (count == position)
	{
		p->next = newNode;
		newNode->next = q;
		++listLength;
		system("cls");
		cout << "\t[LINE " << position << " ADDED]" << endl;
		return;
	}

	system("cls");
	cout << "\t[LINE COULD NOT BE ADDED]" << endl;
	return;
}

//Substitute line 
void LinkedList::Substitute(string line, int position)
{
	if (position <= 0 || position > listLength)
	{
		system("cls");
		cout << "\t[INVALID LINE ENTERED]" << endl;
		return;
	}

	Node* p = head;
	Node* q = head;

	q = p->next;

	// Variable for the line number
	int lineNumber = 1;

	// Find the position in the list
	while (lineNumber != position)
	{
		p = q;
		q = p->next;
		++lineNumber;
	}
	// Update the line:
	q->line = line;
	system("cls");
	cout << "\t[LINE " << position << " SUBSTITUTED]" << endl;

}

//Delete line :
void LinkedList::Delete(int position, int endPosition)
{
	Node* p = head;
	Node* q = head;

	q = p->next;

	//set up a variable to display the line number
	int lineNumber = 1;

	//Delete has no range
	if (endPosition == 0)
	{

		// First check if position is a valid positions
		if (position <= 0 || position > listLength)
		{
			system("cls");
			cout << "\t[INVALID LINE ENTERED]" << endl;
			return;
		}

		// find position
		while (lineNumber != position)
		{
			p = q;
			q = p->next;
			++lineNumber;
		}

		p->next = q->next;
		delete q;
		listLength--;
		system("cls");
		cout << "\t[LINE " << position << " DELETED]" << endl;
		return;
	}
	//Delete has a range
	else
	{
		// valid chaeck
		if (endPosition <= 0 || endPosition > listLength)
		{
			system("cls");
			cout << "\t[INVALID LINE ENTERED]" << endl;
			return;
		}

		while (lineNumber != position)
		{
			p = q;
			q = p->next;
			++lineNumber;
		}

		for (int i = endPosition; i >= position; --i)
		{
			this->Delete(i);
		}
		system("cls");
		cout << "\t[LINES " << position << " to " << endPosition << " DELETED]" << endl;
		return;
	}

}

//View 
void LinkedList::View(int position, int endPosition)
{
	Node* p = head;
	Node* q = head;

	q = p->next;

	// variable to display the line number
	int lineNumber = 1;

	//View is run
	if (position == 0 && endPosition == 0)
	{
		while (lineNumber <= listLength)
		{
			p = q;
			cout << lineNumber;

			if (lineNumber < 10)
			{
				cout << "   ";
			}
			else if (lineNumber < 100)
			{
				cout << "  ";
			}
			else
			{
				cout << " ";
			}
			cout << "| " << p->line << endl;

			//go to next node:
			q = p->next;
			++lineNumber;
		}
	}
	//List line # is run:
	else if (endPosition == 0)
	{
		//First check if optional positions are valid positions:
		if (position <= 0 || position > listLength)
		{
			system("cls");
			cout << "\t[INVALID LINE ENTERED]" << endl;;
			return;
		}

		//find the line:
		while (lineNumber != position)
		{
			p = q;
			q = p->next;
			++lineNumber;
		}

		p = q;
		//then print the line #
		cout << lineNumber;

		//determine # to make output look nice:
		if (lineNumber < 10)
		{
			cout << "   ";
		}
		else if (lineNumber < 100)
		{
			cout << "  ";
		}
		else
		{
			cout << " ";
		}
		cout << "| " << p->line << endl;
	}
	//List Line Range is run:
	else
	{
		//First check if optional positions are valid positions:
		if (position <= 0 || position > listLength || endPosition <= 0 || endPosition > listLength)
		{
			system("cls");
			cout << "\t[INVALID LINE ENTERED]" << endl;
			return;
		}

		//find the first line:
		while (lineNumber != position)
		{
			p = q;
			q = p->next;
			++lineNumber;
		}
		//print out each line until range is hit:
		while (lineNumber <= endPosition)
		{
			p = q;
			//output line #:
			cout << lineNumber;

			//determine # to make output look nice:
			if (lineNumber < 10)
			{
				cout << "   ";
			}
			else if (lineNumber < 100)
			{
				cout << "  ";
			}
			else
			{
				cout << " ";
			}
			cout << "| " << p->line << endl;

			//go to next node:
			q = p->next;
			++lineNumber;
		}
	}
}

//handles the printout of the linked list (used to output to file)
ostream& operator<<(ostream& output, LinkedList& list)
{
	//get the current head node:
	Node* currNode = list.head;
	currNode = currNode->next;
	int linecount = 1;

	//While the current node is not null:
	while (linecount <= list.listLength)
	{
		//send the line to the output:
		output << currNode->line << endl;
		//move to the next node:
		currNode = currNode->next;
		++linecount;
	}
	//return the output:
	return output;
}