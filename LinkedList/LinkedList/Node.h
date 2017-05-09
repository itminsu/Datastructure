#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

class Node
{
	// A node is an individual list entry
public:
	int data; // actual data element
	Node *next; // pointer to the next entry in the list

	Node() : next(NULL), data(-1) {} // default Node values
};
#endif