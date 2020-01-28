#pragma warning(disable:4996)
#include <cstdio>
int N;

class minHeap {
	int *arr;
	int size;
public:
	minHeap() {
		arr = new int[100001];
		size = 0;
	}
	void swap(int& x, int& y) {
		int temp = x;
		x = y;
		y = temp;
	}
	void push(int x) {
		arr[++size] = x;
		for(int i = size ; i > 1 ; i/=2){
			if (arr[i / 2] > x) {
				swap(arr[i / 2], arr[i]);
			}
			else break;
		}
	}
	int pop() {
		if (size == 0) return 0;
		int ret = arr[1];

		int movingnode = arr[size];
		arr[1] = movingnode;
		size--;

		for (int i = 1; i * 2 <= size;) {
			if (arr[i] < arr[2 * i] && arr[i] < arr[2 * i + 1]) break;
			else if (arr[i * 2] < arr[i * 2 + 1]) {
				swap(arr[i * 2], arr[i]);
				i = i * 2;
			}
			else {
				swap(arr[i * 2 + 1], arr[i]);
				i = i * 2 + 1;
			}
		}
		return ret;
	}
};


int main() {
	scanf("%d", &N);
	minHeap h;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		scanf("%d", &temp);
		if (temp == 0) printf("%d\n", h.pop());
		else h.push(temp);
	}
	return 0;
}