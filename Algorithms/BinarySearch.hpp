#include <iostream>

template <typename T>
int binarySearch(const T* arr, unsigned size, const T& key)
{
	unsigned l = 1, h = size - 1;
	while (l <= h)
	{
		unsigned mid = (l + h) / 2;
		if (arr[mid] == key)
			return mid;
		else if (key < arr[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}
