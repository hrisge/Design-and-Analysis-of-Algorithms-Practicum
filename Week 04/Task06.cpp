#include <iostream>
#include <cmath>

int main() {

	long long A, B, K, M, X, P;
	std::cin >> A >> K >> B >> M >> X;
	long long l = 1, r = 3 * (X/(A+B - (A/ K) - (B / M))), mid;
	while (l < r) {
		mid = (l + r) / 2;
		long long total = (A + B) * mid - (mid / K) * A - (mid / M) * B;
		if (total < X) 
			l = mid + 1;
		else
			r = mid;
	}
	std::cout << l;

}