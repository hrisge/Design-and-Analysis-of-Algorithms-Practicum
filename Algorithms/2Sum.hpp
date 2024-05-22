#include <iostream>
#include <algorithm>

template <typename T>
bool twoSum(T * arr,unsigned size,const T& sum)
{
	std::sort(arr, arr + size);
	int i = 0, j = size - 1;
	
	while (i < j)
	{
		if (arr[i] + arr[j] == sum)
			return true;
		else if (arr[i] + arr[j] > sum)
			j--;
		else
			i++;
	}
	return false;
}