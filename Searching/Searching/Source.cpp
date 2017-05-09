#define _CRT_SECURE_NO_WARNINGS
#include "Binary.h"
#include "Sequential.h"
#include "AVLTree.h"

//reference http://dblab.duksung.ac.kr/ds/pdf/Chap13.pdf
int main() {

	// Task.1

	Sequential seqSearch;
	Binary binSearch;
	clock_t start; // declare clock_t for counting duration time
	double seqDuration; //duration time for sequential search
	double binDuration; //duration time for binary search

	const int SIZE = 1000;
	//int target;

	//static sorted array containing the numbers 1 to 1000
	static int intArray[SIZE] = {};
	for (int i = 0; i < SIZE; i++) {
		intArray[i] = i + 1;
	}

	

	start = clock();
	for (int i = 0; i < SIZE; i++) {
		if (seqSearch.Search(intArray, SIZE, i + 1)) {
			cout << "Searched number " << (i + 1) << " by using Sequential Search" << endl;
		}
	}
	seqDuration = (clock() - start) / (double)CLOCKS_PER_SEC;

	start = clock();
	for (int i = 0; i < SIZE; i++) {
		if (binSearch.Search(intArray, SIZE, i + 1)) {
			cout << "Searched number " << (i + 1) << " by using Binary Search" << endl;
		}
	}
	binDuration = (clock() - start) / (double)CLOCKS_PER_SEC;

	cout << endl;
	cout << "Sequential Searching takes " << seqDuration << " seconds" << endl;
	cout << "Binary Searching takes " << binDuration << " seconds" << endl;


	// Task.2


	AvlTree avlTree;
	const char* fileName = "dictionary.txt";
	ifstream is;
	is.open(fileName, ifstream::binary);
	if (is) {
		string line;
		char *value;
		while (getline(is, line)) {
			value = new char[line.length() - 1];
			strcpy(value, line.c_str());
			//reading all the words in a dictionary file 
			avlTree.Insert(value);
		}
	}
	else {
		cout << "Could not read file!!" << endl;
	}
	is.close();

	//Display avl tree.
	cout << endl << "===============================================================================================" << endl;
	cout << avlTree << endl;

	const char* checkFile = "mispelled.txt";
	is.open(checkFile, ifstream::binary);
	if (is) {
		string line;
		char *value;
		string target;

		cout << endl << "======== List of misspelled word========" << endl;
		while (getline(is, line)) {
			//Remove all speciall characters from text.
			for (int i = 0; i < line.size(); i++) { //65 = A 90 = Z 96 = a 122 = z 32 = " "
				if ((line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122) || line[i] == 32) {
					target.push_back(tolower(line[i]));
				}
			}

			//Through istringstream, split word by space. 
			istringstream iss(target);
			string word;
			while (iss >> word) {
				value = new char[word.length() - 1];
				strcpy(value, word.c_str());

				//spell check from avl tree. 
				if (!avlTree.SpellCheck(value)) {
					cout << "Misspelled: " << word << endl;
				}
			}
		}
	}
	else {
		cout << "Could not read file!!" << endl;
	}

	_getch();

	return 0;
}