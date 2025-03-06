#include<iostream>
#include<vector>

int n5, m5, arr5N[1000000], arr5M[1000000], res[2000000];

void main5()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n5 >> m5;

	for (int i = 0; i < n5; ++i)
		std::cin >> arr5N[i];

	for (int i = 0; i < m5; ++i)
		std::cin >> arr5M[i];

	int pos = 0, n = 0, m = 0;
	while (!(n >= n5 && m >= m5))
	{
		if (n >= n5) {
			res[pos++] = arr5M[m++];
			continue;
		}

		if (m >= m5) {
			res[pos++] = arr5N[n++];
			continue;
		}


		if (arr5N[n] < arr5M[m])
			res[pos++] = arr5N[n++];
		else
			res[pos++] = arr5M[m++];
	}

	for (int i = 0; i < m + n; ++i)
		std::cout << res[i] << " ";
	std::cout << '\n';

}