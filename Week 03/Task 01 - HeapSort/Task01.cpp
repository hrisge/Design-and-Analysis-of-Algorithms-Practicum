#include <iostream>

const constexpr int SIZE = 2e6 + 10;

int a[SIZE], n;

void heapify(int curr){
	int par = curr / 2;
	if (!par)
		return;

	if (a[curr] > a[par]) {
		std::swap(a[curr], a[par]);
		heapify(par);
	}
}

void soak(int curr, int size) {
	int child = 2 * curr;
	if (child > size) 
		return;

	if (child + 1 <= size && a[child + 1] > a[child])
		child = child + 1;

	if (a[curr] < a[child]) {
		std::swap(a[curr], a[child]);
		soak(child, size);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];

	for (int i = 1; i <= n; ++i)
		heapify(i);

	for (int i = n; i > 0; --i) {
		std::swap(a[1], a[i]);
		soak(1, i - 1);
	}

	for (int i = 1; i <= n; ++i)
		std::cout << a[i]<<" ";
	std::cout << std::endl;

}

