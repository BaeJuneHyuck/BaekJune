#include <iostream>

using namespace std;

int min(int a, int b) { return a > b ? b : a; }

int main() {
	int T;
	cin >> T;
	while (T--) {
		int K;
		int arr[501], DP[501][501], sum = 0;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> arr[i];
		}



		cout << DP[1][K] << endl;
	}
	cin >> T;
	return 0;
}