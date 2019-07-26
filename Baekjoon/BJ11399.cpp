#include <iostream>

using namespace std;

int main() {
	int N;
	int arr[1001];
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 1; i++) {
		int minindex = i;
		for (int j = i + 1; j < N; j++) {
			if (arr[minindex] > arr[j]) {
				minindex = j;
			}
		}
		if (i != minindex) {
			int temp = arr[minindex];
			arr[minindex] = arr[i];
			arr[i] = temp;
		}
	}

	int sum = arr[0];
	for (int i = 1; i < N; i++) {
		arr[i] = arr[i] +  arr[i-1];
		sum = sum + arr[i];
	}
	cout << sum;

	system("pause");
	return 0;
}