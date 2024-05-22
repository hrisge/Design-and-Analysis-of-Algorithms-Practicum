#include <iostream>
#include <algorithm>

template <typename T>
bool threeSum(T* arr, unsigned size, T sum)
{
	std::sort(arr, arr + size);
	for (int i = 0; i < size - 2; i++)
	{
		int p = i + 1, q = size - 1;
		while (p < q)
		{
			T currSum = arr[i] + arr[p] + arr[q];
			if (currSum == sum)
				return true;
			else if (currSum > sum)
				q--;
			else
				p++;
		}
	}
	return false;
}