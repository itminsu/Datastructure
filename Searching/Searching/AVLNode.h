#ifndef AVLNODE_H
#define AVLNODE_H

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string.h>

using namespace std;

class AvlNode
{
	// A node is an individual list entry
public:
	char* data;
	AvlNode *left;
	AvlNode *right;

	AvlNode() : left(NULL), right(NULL), data(NULL) {} // default Node values
};
#endif