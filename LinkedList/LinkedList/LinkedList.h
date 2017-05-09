#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <iostream>

using namespace std;

// A struct to handle the information being stored
struct Node
{
	string line;
	Node* next;
};

class LinkedList
{
private:
	Node* head;
public:
	int listLength;
	// Constructor 
	LinkedList();
	// Destructor 
	~LinkedList();

	void Insert(string line, int position);
	void Substitute(string line, int position);
	void Delete(int position, int endPosition = 0);
	void View(int position = 0, int endPosition = 0);

	friend ostream& operator<<(ostream& output, LinkedList& list);
};

#endif