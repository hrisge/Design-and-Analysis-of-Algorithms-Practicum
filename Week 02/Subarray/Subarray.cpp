#include <iostream>

const constexpr int MAX_SIZE = 10000;

int main()
{
	long long array[MAX_SIZE];
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
		std::cin >> array[i];

	long long res = 0;

	for (int i = 0; i < n; i++)
	{
		long long sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += array[j];
			if ((j - i) % 2 == 0)
				res += sum;
		}
	}

	std::cout << res;
}