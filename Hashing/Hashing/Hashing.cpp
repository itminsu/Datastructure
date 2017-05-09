#define _CRT_SECURE_NO_WARNINGS
#include "Hashing.h"
#include "Node.h"

using namespace std;

Node *hashTable[50];

//InitializeHashtable.
//set null for default value.
void Hashing::InitializeHashTable() {
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		hashTable[i] = nullptr;
	}
}

//Hash function which returns the calculated index.
int Hashing::Hashfn(string keyString)
// Accepts an input string and returns the calculated index (to use later with a hash table)
{
	int i, sum, address;

	sum = 0;
	int len = keyString.length();
	for (i = 0; i < len; i++)
		sum += (int)keyString[i]; // cast each character of the string as int to get ascii value
								  // the modulus, or remainder, of integer division gives a result between 0 and SIZE-1, 
								  //perfect for an index
	address = sum % HASH_TABLE_SIZE;

	return address;
}

//Insert value into hash table.
//If there is already data in hash table, make chain.
void Hashing::Insert(string data) {

	int hashIndex = Hashfn(data);

	Node *node = new Node();
	char *value = new char[data.length() - 1];
	strcpy(value, data.c_str());
	node->data = value;

	if (hashTable[hashIndex] == NULL) {
		node->next = nullptr;
		hashTable[hashIndex] = node;
	}
	else {
		Node *currNode = hashTable[hashIndex];
		Node *prevNode = NULL;

		while (currNode != NULL)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (prevNode != NULL)
		{
			prevNode->next = node;
		}
	}
}


//SpellCheck function
//First get hashIndex from Hashfn function and get first node from hash table.
//and then looking for value until end of chain.
bool Hashing::SpellCheck(string value) {
	int hashIndex = Hashfn(value);

	Node *node = hashTable[hashIndex];
	while (node != NULL) {
		if (node->data == value) {
			return true;
		}
		node = node->next;
	}

	return false;
}


//Display Hashing Table 
void Hashing::Display()
{
	for (int i = 0; i < HASH_TABLE_SIZE; i++) {
		Node* node = hashTable[i];
		if (node != NULL) {
			cout << "[" << i << "] :" << node->data;
			node = node->next;
			while (node != NULL) {
				cout << " -> " << node->data;
				node = node->next;
			}
			cout << endl;
		}
	}
}
