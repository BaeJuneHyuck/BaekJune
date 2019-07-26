#include <iostream>

using namespace std;
int arr[1001];
int DP[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// DP[i] , arr[i]를 제일 끝으로 가지는 가장 길이가 긴 증가 수열의 길이
	DP[0] = 1;
	for (int i = 1; i < N; i++) {
		int temp = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				temp = temp > (DP[j] + 1) ? temp : (DP[j] + 1);
			}
		}
		DP[i] = temp;
	}
	
	int max = -1;
	for (int i = 0; i < N; i++) {
		cout << DP[i] << " ";
		if (max < DP[i]) max = DP[i];
	}
	cout << DP[N-1];
	system("pause");
	return 0;
}