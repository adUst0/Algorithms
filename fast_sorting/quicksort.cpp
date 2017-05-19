#include <algorithm>

template <typename T>
void quickSort(T* array, int size) {
	if (size < 2) return;

	T pivot = array[random() % size];
	int left = 0, right = size - 1;
	
	for (int i = 0; i < size; i++)
		if (array[i] < pivot)
			std::swap(array[i], array[left++]);
	quickSort(array, left);

	for (int i = size - 1; i >= left; i--)
		if (array[i] > pivot) 
			std::swap(array[i], array[right--]);
	quickSort(array + right + 1, size - right - 1);
}