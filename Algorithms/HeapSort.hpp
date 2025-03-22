#include <iostream>

template <typename T>
void heapify(T* a, int curr){
	int par = curr / 2;
	if (!par)
		return;

	if (a[curr] > a[par]) {
		std::swap(a[curr], a[par]);
		heapify(par);
	}
}

template <typename T>
void soak(T* a, int curr, int size) {
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

template <typename T>
void heapSort(T* a, int n) {
    for (int i = 1; i <= n; ++i)
		heapify(i);

	for (int i = n; i > 0; --i) {
		std::swap(a[1], a[i]);
		soak(1, i - 1);
	}
}


