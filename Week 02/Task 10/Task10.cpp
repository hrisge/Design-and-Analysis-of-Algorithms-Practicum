#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const constexpr long long MAX = 100000;

int n, k;
int a[MAX];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

    int left = 0, sum = 0, maxSum = -1;

    for (int right = 0; right < n; right++) {
        sum += a[right];

        while (sum > k && left <= right) {
            sum -= a[left];
            left++;
        }

        if (sum <= k) {
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;
    return 0;
}