#include <iostream>
using namespace std;

template <typename T>
void selecionSort(T *array, int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIdx = -1, minElem = array[i];
		for (int j = i + 1; j < size; j++) {
			if (array[j] < minElem) {
				minElem = array[j];
				minIdx = j;
			}
		}
		if (minIdx != -1) {
			swap(array[i], array[minIdx]);
		}
	}
}

int main(){

	return 0;
}
