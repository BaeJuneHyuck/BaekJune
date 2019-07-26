#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
// ��ǥ �����ϱ�

using namespace std;

tuple<int, int> arr[100001];
tuple<int, int> sorted[100001];

void merge(tuple<int, int> arr[], int left, int mid, int right, int tuple) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		int val_i, val_j;
		if (tuple) {
			val_i = get<1>(arr[i]);
			val_j = get<1>(arr[j]);
		}
		else {
			val_i = get<0>(arr[i]);
			val_j = get<0>(arr[j]);
		}
		
		if (val_i <= val_j) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= right; l++) {
			sorted[k++] = arr[l];
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			sorted[k++] = arr[l];
		}
	}

	for (l = left; l <= right; l++) {
		arr[l] = sorted[l];
	}
}

void mergeSort(tuple<int, int> arr[], int left, int right, int tuple) {
	// ����� 1�϶� ���� �ɰ���
	// ���ɰ����� ���ؼ� �����ϰ� ��ġ��
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(arr, left, mid, tuple);
		mergeSort(arr, mid + 1, right, tuple);
		merge(arr, left, mid, right,tuple);
	}
}

int main() {
	int N;
	scanf_s("%d" ,&N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = make_tuple(x, y);
	}
	mergeSort(arr, 0, N - 1, 0);
	mergeSort(arr, 0, N - 1, 1);
	
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", get<0>(sorted[i]), get<1>(sorted[i]));
	}
	
	system("pause");
	return 0;
}