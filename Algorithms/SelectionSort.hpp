#include <iostream>

template <typename T>
void selectionSort(T* arr, unsigned size)
{
	if (size < 2)
		return;

	for (int i = 0; i < size - 1; i++)
	{
		unsigned minInd = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minInd])
				minInd = j;
		}

		if (minInd != i)
			std::swap(arr[minInd], arr[i]);
	}
}