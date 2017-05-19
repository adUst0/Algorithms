template <typename T>
bool ternary_search(T* arr, int size, T val) {
	if (size < 1) return false;

	int mid1 = size / 3;
	int mid2 = 2 * size / 3;

	if (arr[mid1] == val) return true;
	if (arr[mid2] == val) return true;

	if (val < arr[mid1]) return ternary_search(arr, mid1, val);
	if (arr[mid2] < val) return ternary_search(arr + mid2+1, size - 1 - mid2, val);
	return ternary_search(arr + mid1 + 1, mid2 - mid1 - 1, val);

}