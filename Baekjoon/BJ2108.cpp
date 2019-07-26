// 백준 2108번, 통계학
/*
2초, 256MB

첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다. 
입력되는 정수의 절댓값은 4,000을 넘지 않는다.

산술평균 : N개의 수들의 합을 N으로 나눈 값 . 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값/  여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
범위 : N개의 수들 중 최댓값과 최솟값의 차이
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

int main() {
	
	int hist[8001] = { 0, };
	int *arr;
	int sum = 0;
	int N,mid, mode = 0;
	int min = 4001;
	int max = -4001;

	cin >> N;
	arr = new int[N](); // ()하면 0으로 초기화됨 
	sorted = new int[N]();

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
		
		// 값 0은 자리0, 값1~4000은 자리(-1~-4000) 4001~8001은 (1~4000)
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