#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const constexpr long long MAX = 1000000;

char str[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin.getline(str, MAX);

	int len = strlen(str), currCount = 0, best = 0;
	char bestChar = str[0];

	for (int i = 0; i < len; ++i) {

		if ((str[i] < 'a' || str[i] > 'z') && !currCount) {
			continue;
		}
		else if ((str[i] < 'a' || str[i] > 'z') && (currCount > best)) {
			best = currCount;
			bestChar = str[i - 1];
			currCount = 0;
			continue;
		}
		else if ((str[i] < 'a' || str[i] > 'z') && (currCount == best && str[i - 1] > bestChar)) {
			bestChar = str[i];
			currCount = 0;
			continue;
		}

		if (str[i] == str[i - 1]) {
			++currCount;
			continue;
		}

		else if (currCount > best) {
			best = currCount;
			bestChar = str[i-1];
		}

		else if (currCount == best && str[i-1] > bestChar)
			bestChar = str[i];

		currCount = 1;
	}

	if (currCount > best) {
		best = currCount;
		bestChar = str[len - 1];
	}
	else if (currCount == best && (bestChar < str[len - 1]))
		bestChar = str[len - 1];


	std::cout << best << " " << bestChar;
	
	return 0;
}