#include <iostream>
#include <vector>
#include <random>

const constexpr int SIZE = 2e6 + 10;

std::mt19937 rnd(04062001);
std::vector<int> v;
int a, n;

void quicksort(std::vector<int>& v) {
	if (v.size() <= 1)
		return;
	int pivot = v[rnd() % v.size()];
	std::vector<int> l, r, m;
	for (auto x : v) {
		if (x < pivot)
			l.push_back(x);
		else if (x > pivot)
			r.push_back(x);
		else
			m.push_back(x);
	}
	quicksort(l);
	quicksort(r);
	v = l;
	for (auto x : m)
		v.push_back(x);
	for (auto x : r)
		v.push_back(x);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);	

	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a;
		v.push_back(a);
	}

	quicksort(v);

	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << " ";

}

