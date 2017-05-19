template <typename T>
bool binary_search(T* arr, int size, T val) {
	int left = 0, right = size - 1, mid = (left + right) / 2;

	while (left <= right) {
		if (arr[mid] == val) return true;
		else if (arr[mid] < val) left = mid + 1;
		else right = mid - 1;
		mid = (left + right) / 2;
	}

	return false;
}