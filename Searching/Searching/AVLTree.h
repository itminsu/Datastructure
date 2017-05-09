#ifndef AVLTREE_H
#define AVLTREE_H

#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "AVLNode.h"

using namespace std;

typedef AvlNode* NodePtr;

class AvlTree
{
private:
	NodePtr root;

public:
	AvlTree() :root(NULL) {}

	void Insert(char *value);
	void Insert(NodePtr &avlNode, char *value);

	bool SpellCheck(char *value);
	void Find(NodePtr avlNode, char *value, bool &result);
	void Display(ostream &output, NodePtr &avlNode, int indent);

	int Height(AvlNode *);
	int BalanceFactor(AvlNode *);
	AvlNode* Balance(AvlNode *);
	AvlNode* RRRotation(AvlNode *);
	AvlNode* LLRotation(AvlNode *);
	AvlNode* LRRotation(AvlNode *);
	AvlNode* RLRotation(AvlNode *);

	friend ostream& operator<<(ostream &output, AvlTree &avlTree);


};
#endif