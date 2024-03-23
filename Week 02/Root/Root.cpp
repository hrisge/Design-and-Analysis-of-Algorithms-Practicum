#include <iostream>

const constexpr int MAX_SIZE = 1 << 16;

int main()
{
	double array[MAX_SIZE];
	int size = 0;
	while (std::cin >> array[size])
	{
		array[size] = sqrt(array[size]);
		size++;
	}
	for (int i = size - 1; i >= 0; i--)
		std::cout << array[i] << std::endl;
	
}