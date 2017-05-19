#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T *array, int size) {
	for (int i = 0; i < size; i++) {
		bool hasSwaps = false;
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j+1] < array[j]) {
				swap(array[j+1], array[j]);
				hasSwaps = true;
			}
		}
		if (!hasSwaps) break;
	}
}

int main(){

	return 0;
}
