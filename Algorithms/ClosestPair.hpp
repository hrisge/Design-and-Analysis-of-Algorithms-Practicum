#include <iostream>
#include <algorithm>

template <typename T>
std::pair<T, T> closestPair(T* arr, unsigned size)
{
	if (size < 2)
		throw std::runtime_error("Invalid Array!");

	std::sort(arr, arr + size);
	T closest = arr[1] - arr[0];
	unsigned first = 0;
	for (unsigned i = 1; i < size - 1; i++)
	{
		if (arr[i + 1] - arr[i] < closest)
		{
			closest = arr[i + 1] - arr[i];
			first = i;
		}
	}
	std::pair<T, T> toReturn(arr[first], arr[first+1]);
	return toReturn;
}
