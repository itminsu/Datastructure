#include "Sorting.h"

using namespace std;

//Declare functions
void QuickSorting(int* arr, int left, int right);
void MergeSorting(int* rand, int left, int right);
void Merge(int* rand, int first, int mid, int last);

void QuickSortForExternal(string* arr, int left, int right);

//Default constructor.
Sorting::Sorting() {

}
//Default destructor.
Sorting::~Sorting() {

}

//Bubble sort
void Sorting::BubbleSort(int* rand, int size) {
	start = clock();

	int right = size - 1;
	int swap; //temp var to swap values
	while (right > 0) {
		int left = 0;
		while (left < right) { //keep moving point until end point.
			//If left value is greater than right, swap value. 
			if (rand[left] > rand[left + 1])
			{
				swap = rand[left];
				rand[left] = rand[left + 1];
				rand[left + 1] = swap;
			}
			left++;
		}
		//biggest value is moved to right side. 
		right--;
	}

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
}

//Selection Sorting
void Sorting::SelectionSort(int* rand, int size) {
	start = clock();

	int left = 0;
	int min;  //temp var for minimum value.
	int swap; //temp var to swap values.
	while (left < size - 1) {
		min = left; //set first value to minimul value. 

		int right = left + 1;
		while (right < size) {
			if (rand[right] < rand[min]) { //keep moving to find smaller value.
				min = right; //set smaller value to minimul value.
			}
			right++;
		}

		swap = rand[left];
		rand[left] = rand[min];
		rand[min] = swap;

		left++;
	}

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
}

//Insertin Sorting
void Sorting::InsertionSort(int* rand, int size) {
	start = clock();

	int i = 0;
	int currPoint; //temp var for current point.
	int swap; //temp var to swap values.
	while (i < size - 1) {
		currPoint = i;
		while (currPoint > 0 && rand[currPoint - 1] > rand[currPoint]) {
		//compare value of previous point with current value until previous value smaller than current point value. 
			swap = rand[currPoint];
			rand[currPoint] = rand[currPoint - 1];
			rand[currPoint - 1] = swap;
			currPoint--;
		}
		i++;
	}

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
}

//Shell Sorting
void Sorting::ShellSort(int* rand, int size) {
	start = clock();

	int i;
	int j;
	int gap; //temp var to divide array.
	int swap; //temp var to swap values.
	for (gap = size / 2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			swap = rand[i];
			for (j = i; j >= gap; j -= gap)
			{
				if (swap < rand[j - gap])
				{
					rand[j] = rand[j - gap];
				}
				else
				{
					break;
				}
			}
			rand[j] = swap;
		}
	}

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
}

//Merge sorting 
void Sorting::MergeSort(int* rand, int size) {
	start = clock();

	MergeSorting(rand, 0, size - 1);

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
}

void MergeSorting(int* rand, int left, int right) {

	if (left < right) {
		
		int middle = (left + right) / 2;

		MergeSorting(rand, left, middle);
		MergeSorting(rand, middle + 1, right);
		
		//do merge
		Merge(rand, left, middle, right);
	
	}

}
void Merge(int* rand, int first, int mid, int last) {

	int* leftArray = NULL;
	int* rightArray = NULL;
	int i, j, k;
	int n1 = mid - first + 1;
	int n2 = last - mid;
	leftArray = new int[n1];
	rightArray = new int[n2];
	for (i = 0; i < n1; i++)
		leftArray[i] = rand[first + i];
	for (j = 0; j < n2; j++)
		rightArray[j] = rand[mid + 1 + j];

	i = 0;
	j = 0;
	k = first;

	// Merge the two halves until one runs out
	while (i < n1 && j < n2)
	{
		if (leftArray[i] <= rightArray[j])
		{
			rand[k] = leftArray[i];
			i++;
		}
		else
		{
			rand[k] = rightArray[j];
			j++;
		}
		k++;
	}

	// Append the remaining elements to the end of array
	while (i < n1)
	{
		rand[k] = leftArray[i];
		i++;
		k++;
	}
	// Append the remaining elements to the end of array
	while (j < n2)
	{
		rand[k] = rightArray[j];
		j++;
		k++;
	}

	//delete temporary arrays
	delete[] leftArray;
	delete[] rightArray;
}

//Quick sorting
void Sorting::QuickSort(int* rand, int size) {
	start = clock();

	QuickSorting(rand, 0, size - 1);

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;
}

void QuickSorting(int* rand, int left, int right) {
	int i = left, j = right;
	int swap;
	int pivot = rand[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (rand[i] < pivot)
			i++;
		while (rand[j] > pivot)
			j--;
		if (i <= j) {
			swap = rand[i];
			rand[i] = rand[j];
			rand[j] = swap;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSorting(rand, left, j);
	if (i < right)
		QuickSorting(rand, i, right);
}

//part.2
//it is same with quicksorting but, string array to get line index from external mergesort
void QuickSortForExternal(string* rand, int left, int right) {
	int i = left, j = right;
	string swap;

	string pivot = rand[(left + right) / 2];
	int pivotVal = stoi(pivot.substr(0, pivot.find(",")));
	/* partition */
	while (i <= j) {
		int leftVal = stoi(rand[i].substr(0, rand[i].find(",")));
		int rightVal = stoi(rand[j].substr(0, rand[j].find(",")));

		while (leftVal < pivotVal) {
			i++;
			leftVal = stoi(rand[i].substr(0, rand[i].find(",")));
		}

		while (rightVal > pivotVal) {
			j--;
			rightVal = stoi(rand[j].substr(0, rand[j].find(",")));
		}

		if (i <= j) {
			swap = rand[i];
			rand[i] = rand[j];
			rand[j] = swap;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		QuickSortForExternal(rand, left, j);
	if (i < right)
		QuickSortForExternal(rand, i, right);
}

void Sorting::GetLineCountFromFile(string fname, int& totalLine) {
	ifstream is(fname, ifstream::binary);
	if (is) {
		//get total line numbers
		char c;
		int lineNumber = 1;
		while (is.get(c)) {
			if (c == '\n')
				++lineNumber;
		}
		totalLine = lineNumber;
	}

	is.close();
}

//Read data from file.
//It returns total line number and specific line number with user's limitation.
void Sorting::ReadStringDataFromFile(string* file, int start, int end, string fname, int& lineNum) {
	ifstream is(fname, ifstream::binary);
	lineNum = 0;
	if (is) {
		int currLine = 1;
		int index = 0;
		string line;
		while (getline(is, line)) {
			if (currLine >= start && currLine <= end && line != "") {
				file[index++] = line.erase(line.size() - 1);
				lineNum++;
			}

			if (currLine > end) {
				is.close();
				break;
			}

			currLine++;
		}
	}
	is.close();
}

//External merge sort
void Sorting::ExternalMergeSort(string fname, int size, int limitation) {
	remove("temp_storage1_1.txt"); 
	remove("temp_storage1_2.txt"); 
	start = clock();

	int startLine = 1;
	int endLine = limitation;
	string *temp = new string[limitation];

	bool flag = true;
	bool stopFlag = false;

	int fileLineNum = limitation;
	int tempLength = limitation;
	//At first, read number form file in blocks of 5000 number 
	// and sort them and then store two files.
	while (true) {

		if (startLine > size) { //size 20000
			break;
		}
		else if (endLine > size) {
			endLine = size;
			stopFlag = true;
		}

		//Read random number form file in blocks of 5000 number
		ReadStringDataFromFile(temp, startLine, endLine, fname, fileLineNum);

		////when file have numbers below 5000
		/*if (fileLineNum != tempLength) {
			tempLength = fileLineNum;
		}*/
		
		//sorting number by quick sorting. 
		QuickSortForExternal(temp, 0, tempLength - 1);

		//record number on file.
		if (flag) {
			GenerateFileForExternalMerge(temp, tempLength, "temp_storage1_1.txt"); //hold the input 
			flag = false;
		}
		else {
			GenerateFileForExternalMerge(temp, tempLength, "temp_storage1_2.txt"); //hold the input 
			flag = true;
		}
		delete[] temp;
		temp = new string[limitation];

		if (stopFlag)
			break;

		startLine += tempLength;
		endLine += tempLength;
	}

	//call merge!!
	ExternalMerge("temp_storage1_1.txt", "temp_storage1_2.txt", "temp_storage2_1.txt", "temp_storage2_2.txt", limitation, limitation/2 , size);

	end = clock();
	duration = (end - start) / (double)CLOCKS_PER_SEC;

}


//Merge through two files.
void Sorting::ExternalMerge(string leftSource, string rightSource, string leftDest, string rightDest, int limitLine, int maxBlockSize, int size) {

	//Delete destation files
	remove(leftDest.c_str());
	remove(rightDest.c_str());

	int leftCurrent = 0;
	int leftTotal = 0;
	int rightCurrent = 0;
	int rightTotal = 0;

	//temp_storage1_1.txt
	int leftStartFile = 1;
	int leftEndFile = maxBlockSize;
	
	//temp_storage1_2.txt
	int rightStartFile = 1;
	int rightEndFile = maxBlockSize;

	//Set start point
	int lPostIdx = 0;
	int lLimitIdx = maxBlockSize;

	int rPostIdx = 0;
	int rLimitIdx = maxBlockSize;

	int lMaxValue = 0;
	int rMaxValue = 0;

	bool flag = true;

	int lTotalLine;
	int rTotalLine;
	GetLineCountFromFile(leftSource, lTotalLine); 
	GetLineCountFromFile(rightSource, rTotalLine); 

	string* tempLeft = new string[maxBlockSize];
	string* tempRight = new string[maxBlockSize];
	ofstream output;
	while (true) {
		//Depends on flag, switch file to store data.
		if (flag) {
			output.open(leftDest, ofstream::app);
			flag = false;
		}
		else {
			output.open(rightDest, ofstream::app);
			flag = true;
		}


		if (leftTotal < lTotalLine) {
			ReadStringDataFromFile(tempLeft, leftStartFile, leftEndFile, leftSource, lMaxValue);
		}
		if (rightTotal < rTotalLine) {
			ReadStringDataFromFile(tempRight, rightStartFile, rightEndFile, rightSource, rMaxValue);
		}

		lLimitIdx = lLimitIdx > lMaxValue ? lMaxValue : lLimitIdx;
		rLimitIdx = rLimitIdx > rMaxValue ? rMaxValue : rLimitIdx;

		//Compare two values and store smaller one
		while (lPostIdx < lLimitIdx && rPostIdx < rLimitIdx) {

			int leftVal = stoi(tempLeft[lPostIdx].substr(0, tempLeft[lPostIdx].find(",")));
			int rightVal = stoi(tempRight[rPostIdx].substr(0, tempRight[rPostIdx].find(",")));

			if (leftVal <= rightVal)
			{
				output << tempLeft[lPostIdx] << endl;
				lPostIdx++;
				leftCurrent++;
				leftTotal++;
			}
			else
			{
				output << tempRight[rPostIdx] << endl;
				rPostIdx++;
				rightCurrent++;
				rightTotal++;
			}

			if (lPostIdx >= lLimitIdx && leftCurrent < limitLine) {
				lPostIdx = 0;
				delete[] tempLeft;
				tempLeft = new string[maxBlockSize];
				ReadStringDataFromFile(tempLeft, leftStartFile += maxBlockSize, leftEndFile += maxBlockSize, leftSource, lMaxValue);
				lLimitIdx = lLimitIdx > lMaxValue ? lMaxValue : lLimitIdx;
			}
			if (rPostIdx >= rLimitIdx && rightCurrent < limitLine) {
				rPostIdx = 0;
				delete[] tempRight;
				tempRight = new string[maxBlockSize];
				ReadStringDataFromFile(tempRight, rightStartFile += maxBlockSize, rightEndFile += maxBlockSize, rightSource, rMaxValue);
				rLimitIdx = rLimitIdx > rMaxValue ? rMaxValue : rLimitIdx;
			}
		}

		// Append the remaining elements to the end of array
		while (lPostIdx < lLimitIdx)
		{
			output << tempLeft[lPostIdx] << endl;
			lPostIdx++;
			leftCurrent++;
			leftTotal++;
			if (lPostIdx >= lLimitIdx && leftCurrent < limitLine) {
				lPostIdx = 0;
				delete[] tempLeft;
				tempLeft = new string[maxBlockSize];
				ReadStringDataFromFile(tempLeft, leftStartFile += maxBlockSize, leftEndFile += maxBlockSize, leftSource, lMaxValue);
				lLimitIdx = lLimitIdx > lMaxValue ? lMaxValue : lLimitIdx;
			}
		}
		// Append the remaining elements to the end of array
		while (rPostIdx < rLimitIdx)
		{
			output << tempRight[rPostIdx] << endl;
			rPostIdx++;
			rightCurrent++;
			rightTotal++;
			if (rPostIdx >= rLimitIdx && rightCurrent < limitLine) {
				rPostIdx = 0;
				delete[] tempRight;
				tempRight = new string[maxBlockSize];
				ReadStringDataFromFile(tempRight, rightStartFile += maxBlockSize, rightEndFile += maxBlockSize, rightSource, rMaxValue);
				rLimitIdx = rLimitIdx > rMaxValue ? rMaxValue : rLimitIdx;
			}
		}

		output.close();

		lPostIdx = 0;
		rPostIdx = 0;
		leftCurrent = 0;
		rightCurrent = 0;
		leftStartFile += maxBlockSize;
		leftEndFile += maxBlockSize;
		rightStartFile += maxBlockSize;
		rightEndFile += maxBlockSize;
		if (leftTotal >= lTotalLine - 1 && rightTotal >= rTotalLine - 1) {
			break;
		}

	}


	GetLineCountFromFile(leftDest, lTotalLine);
	GetLineCountFromFile(rightDest, rTotalLine);

	//If total size of one file is greater than size, that means sorting is completed. 
	if (lTotalLine > size || rTotalLine > size) {

		//Generate file for result. 
		ifstream source;
		if (lTotalLine < 0) {
			source.open(rightDest, ios::binary);
		}
		else {
			source.open(leftDest, ios::binary);
		}
		ofstream dest("7.EMS.txt", ios::binary);

		dest << source.rdbuf();

		source.close();
		dest.close();
	}

	//recursion
	else {
		ExternalMerge(leftDest, rightDest, leftSource, rightSource, limitLine + limitLine, maxBlockSize, size);
	}
}


//Generate text file for result and external merge sorting..
void Sorting::GenerateFile(int* rand, int size, string fname, char type) {

	ofstream myfile;
	myfile.open(fname);
	

	for (int j = 0; j < size; j++) {
		myfile << rand[j];
		if (type == 'E') {
			myfile << ",Line" << j + 1;
		}
		myfile << endl;
	}

	myfile.close();
}

//Generate text file from string array. 
void Sorting::GenerateFileForExternalMerge(string* rand, int size, string fname) {

	ofstream myfile;
	myfile.open(fname, ofstream::app);

	for (int j = 0; j < size; j++) {
		myfile << rand[j];
		myfile << endl;
	}

	myfile.close();
}


//Get duration time.
//it retruns duration time.
double Sorting::GetDuration() {
	return duration;
}