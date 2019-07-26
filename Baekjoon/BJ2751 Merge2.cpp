// 백준 2751 수정렬하기 2
/*
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

머지나 힙 정렬 : O(n logN)
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
	// 사이즈가 1일때 까지 쪼개서
	// 다쪼개지면 비교해서 정렬하고 합치기
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
