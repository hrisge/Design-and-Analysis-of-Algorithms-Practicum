#include <iostream>

template <typename T>
void insertionSort(T* arr, unsigned size)
{
	if (size < 2)
		return;

	for (int i = 1; i < size; i++)
	{
		T key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}