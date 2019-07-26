#include <iostream>

using namespace std;
int DP[100001];
int arr[100001];
int max(int a, int b) { return a > b ? a : b; }

int main() {
	int N, i = 0, j = 0;
	cin >> N;
	for (i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DP[0] = arr[0]; 
	int maxsum = DP[0];
	for (i = 1; i < N; i++) {
		DP[i] = max(DP[i - 1] + arr[i], arr[i]);
		if (DP[i] > maxsum) maxsum = DP[i];
	}
	for (int x = 0; x < N; x++) {
		cout << DP[x] << " ";
	}
	cout << maxsum;
	system("pause");
	return 0;
}