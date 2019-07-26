// ���� 2751 �������ϱ� 2
/*
ù° �ٿ� ���� ���� N(1 �� N �� 1,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ������ 1,000,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

������ �� ���� : O(n logN)
*/
#include <iostream>

int sorted[1000001];

void merge(int arr[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
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
void mergeSort(int arr[], int left, int right) {
	// ����� 1�϶� ���� �ɰ���
	// ���ɰ����� ���ؼ� �����ϰ� ��ġ��
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

using namespace std;
int main() {
	int N;
	cin >> N;
	int *arr;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, N - 1);

	for (int i = 0; i < N; i++) {
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}
