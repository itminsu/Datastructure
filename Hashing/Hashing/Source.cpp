#include "Node.h"
#include "Hashing.h"
using namespace std;

//reference http://dblab.duksung.ac.kr/ds/pdf/Chap13.pdf
//http://interactivepython.org/runestone/static/pythonds/SortSearch/Hashing.html
int main() {

	//Declare Hahing object and do initialization
	Hashing hashing;
	hashing.InitializeHashTable();


	//Read file through ifstream.
	const char* fileName = "dictionary.txt";
	ifstream is;
	is.open(fileName, ifstream::binary);
	if (is) {
		string line;
		while (getline(is, line)) {
			//read each word and insert into hash table.
			hashing.Insert(line);
		}
	}
	else {
		cout << "Could not read file!!" << endl;
	}
	is.close();

	//Display Hashing Table.
	cout << "============= Hash Table==========" << endl;
	hashing.Display();

	const char* checkFile = "mispelled.txt";
	is.open(checkFile, ifstream::binary);
	if (is) {
		string line;
		char *value;
		string target;

		cout << endl << "======== List of misspelled word========" << endl;
		while (getline(is, line)) {
			//Remove all speciall characters from text.
			for (int i = 0; i < line.size(); i++) {
				if ((line[i] >= 65 && line[i] <= 90) || (line[i] >= 97 && line[i] <= 122) || line[i] == 32) {
					target.push_back(tolower(line[i]));
				}
			}

			//Through istringstream, split word by space. 
			istringstream iss(target);
			string word;
			while (iss >> word) {
				//spell check reused. 
				if (!hashing.SpellCheck(word)) {
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


