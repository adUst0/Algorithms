#include <algorithm>

template <typename T>
void quickSelect(T* array, int size, int k) {
	if (size < 2) return;

	T pivot = array[random() % size];
	int left = 0, right = size - 1;
	
	for (int i = 0; i < size; i++) {
		if (array[i] < pivot) {
			std::swap(array[i], array[left++]);
		}
	}

	if (k < left) {
		quickSelect(array, left, k);
	}
	else {
		for (int i = size - 1; i >= left; i--) {
			if (array[i] > pivot) {
				std::swap(array[i], array[right--]);
			}
		}
		if (k > right) {
			quickSelect(array + right + 1, size - right - 1, k - right - 1);
		}
	}
}