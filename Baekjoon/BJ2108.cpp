// ���� 2108��, �����
/*
2��, 256MB

ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. �� ���� N���� �ٿ��� �������� �־�����. 
�ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

������ : N���� ������ ���� N���� ���� �� . �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.
�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��/  ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.
���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
*/

#include <iostream>
#include <math.h>
using namespace std;

int *sorted;

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

int main() {
	
	int hist[8001] = { 0, };
	int *arr;
	int sum = 0;
	int N,mid, mode = 0;
	int min = 4001;
	int max = -4001;

	cin >> N;
	arr = new int[N](); // ()�ϸ� 0���� �ʱ�ȭ�� 
	sorted = new int[N]();

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
		
		// �� 0�� �ڸ�0, ��1~4000�� �ڸ�(-1~-4000) 4001~8001�� (1~4000)
		int index = 0;
		if (arr[i] < 0) index = -1 * arr[i];
		else if (arr[i] > 0) index = arr[i] + 4000;
		int temp = hist[index]++;
		if (temp >= mode) mode = temp;
	}
	
	mergeSort(arr, 0, N - 1);
	mid = arr[N / 2];
	cout << (sum / N)<<'\n';
	cout << mid << '\n';
	cout << mode << '\n';
	cout << abs(max-min) << '\n';

	system("pause");
	return 0;
}