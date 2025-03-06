#include <iostream>

int arr2[1000], n2;

void main2()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n2;
	for (int i = 0; i < n2; ++i)
		std::cin >> arr2[i];

	for (int i = 1; i < n2; ++i) {
		for (int j = i; j > 0; --j) {
			if (arr2[j] < arr2[j - 1])
				std::swap(arr2[j], arr2[j - 1]);
			else
				break;
		}

		for (int j = 0; j < n2; ++j)
			std::cout << arr2[j] << " ";
		std::cout << '\n';
	}
}