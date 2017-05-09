#include "Sorting.h"

using namespace std;

int main() {

	int countOfNumber;
	int COUNT_OF_NUMBER_FOR_EMS = 20000; //for EMS
	const int LIMITATION = 5000;
	Sorting sort; //delcare instance for sorting.

	cout << "Please enter a size of array: ";
	cin >> countOfNumber;

	srand(time(NULL)); // srand generate differnect random number everytime based on time.

	//generate random number for sorting
	int *originals = new int[countOfNumber];
	for (int a = 0; a < countOfNumber; a++)
	{
		originals[a] = rand();
	}

	//generate temp array
	int *temp = new int[countOfNumber];
	
//Start Bubble sorting.
	//Copy random number to temp array.
	memcpy(temp, originals, countOfNumber * sizeof(int));
	cout << "Bubble Sorting: ";

	//Generate file contain random value to compare
	remove("1.Unsorted_BubbleSorting.txt");

	sort.GenerateFile(temp, countOfNumber, "1.Unsorted_BubbleSorting.txt", 'N');

	sort.BubbleSort(temp, countOfNumber);
	cout << sort.GetDuration() << " seconds" << endl;
	
	//Generate result file.
	remove("1.BubbleSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "1.BubbleSorting.txt", 'N');

//Start Selection Sorting
	//Copy random number to temp array.
	memcpy(temp, originals, countOfNumber * sizeof(int));
	cout << "Selection Sorting: ";

	//Generate file contain random value to compare
	remove("2.Unsorted_SelectionSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "2.Unsorted_SelectionSorting.txt", 'N');

	sort.SelectionSort(temp, countOfNumber);
	cout << sort.GetDuration() << " seconds" << endl;

	//Generate result file.
	remove("2.SelectionSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "2.SelectionSorting.txt", 'N');

//Start Insertion Sorting
	//Copy random number to temp array.
	memcpy(temp, originals, countOfNumber * sizeof(int));
	cout << "Insertion Sorting: ";

	//Generate file contain random value to compare
	remove("3.Unsorted_InsertionSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "3.Unsorted_InsertionSorting.txt", 'N');

	sort.InsertionSort(temp, countOfNumber);
	cout << sort.GetDuration() << " seconds" << endl;

	//Generate result file.
	remove("3.InsertionSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "3.InsertionSorting.txt", 'N');

//Start Shell Sorting
	//Copy random number to temp array.
	memcpy(temp, originals, countOfNumber * sizeof(int));
	cout << "Shell Sorting: ";

	//Generate file contain random value to compare
	remove("4.Unsorted_ShellSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "4.Unsorted_ShellSorting.txt", 'N');

	sort.ShellSort(temp, countOfNumber);
	cout << sort.GetDuration() << " seconds" << endl;

	//Generate result file.
	remove("4.ShellSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "4.ShellSorting.txt", 'N');

//Start Merge Sorting
	//Copy random number to temp array.
	memcpy(temp, originals, countOfNumber * sizeof(int));
	cout << "Merge Sorting: ";

	//Generate file contain random value to compare
	remove("5.Unsorted_MergeSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "5.Unsorted_MergeSorting.txt", 'N');

	sort.MergeSort(temp, countOfNumber);
	cout << sort.GetDuration() << " seconds" << endl;
	
	//Generate result file.
	remove("5.MergeSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "5.MergeSorting.txt", 'N');

//Start Quick Sorting
	//Copy random number to temp array.
	memcpy(temp, originals, countOfNumber * sizeof(int));
	cout << "Quick Sorting: ";

	//Generate file contain random value to compare
	remove("6.Unsorted_QuickSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "6.Unsorted_QuickSorting.txt", 'N');

	sort.QuickSort(temp, countOfNumber);
	cout << sort.GetDuration() << " seconds" << endl;
	
	//Generate result file.
	remove("6.QuickSorting.txt");
	sort.GenerateFile(temp, countOfNumber, "6.QuickSorting.txt", 'N');

//Start External Merge Sorting
	//generate random number for sorting
	int *originalsEMS = new int[COUNT_OF_NUMBER_FOR_EMS];
	for (int a = 0; a < COUNT_OF_NUMBER_FOR_EMS; a++)
	{
		originalsEMS[a] = rand();
	}

	//generate temp array
	int *tempEMS = new int[COUNT_OF_NUMBER_FOR_EMS];

	//Copy random number to temp array.
	memcpy(tempEMS, originalsEMS, COUNT_OF_NUMBER_FOR_EMS * sizeof(int));
	cout << "External Merge Sorting: ";

	//Generate file contain random value to compare
	remove("7.Unsorted_EMS.txt");
	sort.GenerateFile(tempEMS, COUNT_OF_NUMBER_FOR_EMS, "7.Unsorted_EMS.txt", 'E');

	sort.ExternalMergeSort("7.Unsorted_EMS.txt", COUNT_OF_NUMBER_FOR_EMS, LIMITATION);
	cout << sort.GetDuration() << " seconds" << endl;

	cout << "Press any key to close....";
	_getch();

	return 0;

}


