#ifndef NODE_H
#define NODE_H
#include <fstream>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <conio.h>
#include <string>

using namespace std;

class Node
{
	// A node is an individual list entry
public:
	char* data; // actual data element
	Node *next; // pointer to the next entry in the list

	Node() : next(NULL), data(NULL) {} // default Node values
};
#endif