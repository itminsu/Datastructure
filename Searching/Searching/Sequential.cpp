#include "sequential.h"

using namespace std;

bool Sequential::Search(int intArray[], int size, int target) {

	for (int i = 0; i < size; i++) {

		if (intArray[i] == target) {
			return true;
			break;
		}

	}

	return false;
}
