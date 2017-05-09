#ifndef HASHING_H
#define HASHING_H

#include <iostream> 
#include <string>
#include <sstream>

using namespace std;


#define HASH_TABLE_SIZE 47  // Size of the sample hash table - note the use of a prime number


class Hashing
{
public:
	void InitializeHashTable();
	int Hashfn(string keyString);
	void Insert(string data);

	bool SpellCheck(string data);
	void Display();

};
#endif