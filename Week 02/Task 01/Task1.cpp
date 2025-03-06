#include <iostream>

void main1() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int arr[100], n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n- i - 1; ++j) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}

		for (int j = 0; j < n; ++j)
			std::cout << arr[j] << " ";
		std::cout << '\n';
	}

	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << '\n';
}