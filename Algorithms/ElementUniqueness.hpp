#include <iostream>
#include <algorithm>

template <typename T>
bool elementUniqueness(T* arr, unsigned size)
{
	std::sort(arr, arr + size);
	for (unsigned i = 0; i < size-1; i++)
	{
		if (arr[i] == arr[i + 1])
			return false;
	}
	return true;
}