#include "AvlTree.h"

using namespace std;

//reading all the words in a dictionary file 
//Insert value into the AVL tree
void AvlTree::Insert(char *value) {
	Insert(root, value);
}

void AvlTree::Insert(NodePtr &avlNode, char *value) {
	//If root node is null, the value is stored in root node.
	if (avlNode == NULL)
	{
		avlNode = new AvlNode;
		avlNode->data = value;
		avlNode->left = NULL;
		avlNode->right = NULL;
	}
	//If value is less than root data, the value is stored in left nood.
	else if (strcmp(value, avlNode->data) < 0) // value < root data
	{
		Insert(avlNode->left, value);
		avlNode = Balance(avlNode);
	}
	//If value is less than root data, the value is stored in right nood.
	else if (strcmp(value, avlNode->data) > 0) // value > root data
	{
		Insert(avlNode->right, value);
		avlNode = Balance(avlNode);
	}
}

//Get height of node 
//length of longest path from current node down to a leaf
//Reference
//AVL Trees, AVL Sort: https://www.youtube.com/watch?v=FNeL18KsWPc
int AvlTree::Height(AvlNode *temp) {
	int height = 0;
	if (temp != NULL) {
		int leftHeight = Height(temp->left);
		int rightHeight = Height(temp->right);
		//get Height of current node.
		// height is max(height of left child, height of right child) + 1;
		int maxHeight = max(leftHeight, rightHeight);
		height = maxHeight + 1;
	}
	return height;
}

//Get balance factor.
//If height of left sub-tree is greater than height of right sub-tree,
//it returns positive height. 
//else, it returns negative height.
//It calculate 
int AvlTree::BalanceFactor(AvlNode *temp)
{
	int leftHeight = Height(temp->left);
	int rightHeight = Height(temp->right);
	int balanceFactor = leftHeight - rightHeight;
	return balanceFactor;
}

//Balancing AVL Tree
//Reference
//AVL Trees Tutorial, https://www.youtube.com/watch?v=5C8bLQBjcDI
AvlNode *AvlTree::Balance(AvlNode *temp)
{
	int balance_factor = BalanceFactor(temp);
	//If balance_factor is positive, left subtree is greater than right tree
	if (balance_factor > 1)
	{
		//If the left node's height is positive,
		//it needs Left-Left rotation.
		if (BalanceFactor(temp->left) > 0)
			temp = LLRotation(temp);
		//If it negative, it needs Left-Right rotation.
		else
			temp = LRRotation(temp);
	}
	//If balance_factor is negative, right tree is greater than left tree
	else if (balance_factor < -1)
	{
		//If it is positive, it needs Right-Left rotation
		if (BalanceFactor(temp->right) > 0)
			temp = RLRotation(temp);
		//If it is negative, it needs Right-Right rotation
		else
			temp = RRRotation(temp);
	}
	return temp;
}


//Left- Left Rotation
//Insert into the left sub-tree of the left child
//Reference
//AVL tree: https://en.wikipedia.org/wiki/AVL_tree
AvlNode *AvlTree::LLRotation(AvlNode *parent)
{
	AvlNode *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

//Right- Right Rotation
//Insert into the right sub-stree of the right child
AvlNode *AvlTree::RRRotation(AvlNode *parent)
{
	AvlNode *temp;
	temp = parent->right; //make right node to root
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

//Left - Right Rotation
// Insert into the right sub-tree of the left child
AvlNode *AvlTree::LRRotation(AvlNode *parent)
{
	AvlNode *temp;
	temp = parent->left;
	//it makes to left-left case from right-right rotation.
	parent->left = RRRotation(temp);
	return LLRotation(parent);
}


//Right- Left Rotation
//Insert into the left sub-tree of the right child.
AvlNode *AvlTree::RLRotation(AvlNode *parent)
{
	AvlNode *temp;
	temp = parent->right;
	parent->right = LLRotation(temp);
	return RRRotation(parent);
}

//Display AVL Tree
void AvlTree::Display(ostream &output, NodePtr &avlNode, int indent)
{
	if (avlNode != NULL)
	{
		Display(output, avlNode->right, indent + 15);

		output << setw(indent) << avlNode->data << endl;

		Display(output, avlNode->left, indent + 15);
	}

}

//SpellCheck function
//get value and call find function
bool AvlTree::SpellCheck(char *value) {
	bool result = false;
	Find(root, value, result);

	return result;
}

//find function for searching value.
//If searching value is less than current node value, go into left child.
void AvlTree::Find(NodePtr avlNode, char *value, bool &result) {
	if (avlNode == NULL) {
		result = false;
	}
	else {
		//searching value is less than current node value,
		//so search left sub-tree.
		if (strcmp(value, avlNode->data) < 0) {
			Find(avlNode->left, value, result);
		}
		else {
			if (strcmp(value, avlNode->data) > 0) {
				Find(avlNode->right, value, result);
			}
			else {
				result = true;
			}
		}
	}
}

//overload output operator
ostream& operator<<(ostream &output, AvlTree &avlTree)
{
	avlTree.Display(output, avlTree.root, 0);

	return output;
}