#include <iostream>

int arr3[3000000], n3, count[1000] = { 0 }, res3[3000000];


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n3;
	for (int i = 0; i < n3; ++i)
		std::cin >> arr3[i];

	for (int i = 0; i < n3; ++i)
		count[arr3[i]]++;

	for (int i = 0; i < 1000; ++i)
		count[i] += count[i - 1];

	for (int i = n3 - 1; i >= 0; --i) {
		res3[count[arr3[i]] - 1] = arr3[i];
		count[arr3[i]]--;
	}

	for (int i = 0; i < n3; i++)
		std::cout << res3[i] << " ";
	std::cout << "\n";

}
