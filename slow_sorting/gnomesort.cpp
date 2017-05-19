#include <iostream>
using namespace std;

template <typename T>
void gnomeSort(T* array, int size) {
	for (int i = 0; i < size; i++)
		if (array[i+1] < array[i]) {
			swap(array[i], array[i+1]);
			i = i == 0 ? -1 : i-2;
		}
}

int main(){
	int arr[25];
	for (int i = 0; i < 25; i++) {
		arr[i] = rand() % 100 + 1;
		printf("%d ", arr[i]);
		if (i == 24) printf("\n");
	}

	gnomeSort(arr, 25);
	for (int i = 0; i < 25; i++) {
		printf("%d ", arr[i]);
		if (i == 24) printf("\n");
	}	

	return 0;
}
