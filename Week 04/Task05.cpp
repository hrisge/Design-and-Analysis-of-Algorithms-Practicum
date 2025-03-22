#include <iostream>
#include <cmath>

int main() {

	long long n, f;
	std::cin >> n >> f;
	long long l = 1, r = std::sqrt(2*n), m;
	while (l < r) {
		m = (l + r) / 2;
		long sum = m * f + ((m * (m - 1)) / 2);
		if (sum < n)
			l = m + 1;
		else
			r = m;
	}
	std::cout << l<< std::endl;
}