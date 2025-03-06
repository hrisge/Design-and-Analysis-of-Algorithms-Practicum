#include<iostream>
#include<vector>

int n4, r, arr4[300000];

void main4()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n4 >> r;

	for (int i = 0; i < n4; ++i)
		std::cin >> arr4[i];

	long count = 0, toStart = 1;
	for (int i = 0; i < n4 - 1; ++i)
	{
		for (int j = toStart; j < n4; ++j)
		{
			if (arr4[j] - arr4[i] > r)
			{
				count += n4 - j;
				toStart = j;
				break;
			}
		}
		if (arr4[n4 - 1] - arr4[i] < r)
			break;
	}

	std::cout << count;
}