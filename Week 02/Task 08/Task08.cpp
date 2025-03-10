#include <iostream>
#include <algorithm>

const constexpr long long MAX = 1000000;

int n, k, stairs[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;
	for (long long i = 0; i < n; i++)
		std::cin >> stairs[i];

	std::sort(&stairs[0], &stairs[n]);

	int currLen = 1, bestLen = 0;
	long long currHigh = 1;

	for (int i = 1; i < n; ++i) {
		if (stairs[i] == stairs[i - 1])
			continue;
		
		else if (stairs[i] - stairs[i - 1] <= k) {
			currLen++;
			continue;
		}
		
		else if (currLen > bestLen)
			bestLen = currLen;

		currLen = 1;
	}

	if (currLen > bestLen)
		bestLen = currLen;

	std::cout << bestLen;
	return 0;
}