#include "binary.h"

using namespace std;

bool Binary::Search(int intArray[], int size, int target) {

	int bottom = 0;
	int top = size - 1;
	int mid;

	while (true) {
		mid = (bottom + top) / 2;

		if (intArray[mid] == target) {
			return true;
			break;
		}
		else if (top < bottom) { // empty list
			break;
		}
		else if (intArray[mid] < target) {
			bottom = mid + 1;
		}
		else if (intArray[mid] > target) {
			top = mid - 1;
		}
	}

	return false;
}
