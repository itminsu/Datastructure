#pragma once
#ifndef _SORTING_H
#define _SORTING_H
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

class Sorting {
private:
	clock_t start; // declare clock_t for counting duration time
	clock_t end;
	double duration; //duration time
public:
	Sorting();
	~Sorting();
	void BubbleSort(int* rand, int size);
	void SelectionSort(int* rand, int size);
	void InsertionSort(int* rand, int size);
	void ShellSort(int* rand, int size);
	void MergeSort(int* rand, int size);
	void QuickSort(int* rand, int size);


	void ExternalMergeSort(string fname, int size, int limitation);
	void ExternalMerge(string leftSource, string rightSource, string leftDest, string rightDesc, int limitLine, int maxBlockSize, int size);
	//generate result text file

	void GenerateFile(int* rand, int size, string fname, char type);
	void GenerateFileForExternalMerge(string* rand, int size, string fname); //for external mergesort (string array)

	void ReadStringDataFromFile(string* file, int start, int end, string fname, int& lineNum);
	void GetLineCountFromFile(string fname, int& totalLine);
	double GetDuration();
};


#endif