#include <iostream>

using namespace std;

int coin[11];

int main() {

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	
	int count = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (coin[i] > K) continue;
		count = count + K / coin[i];
		K = (K % coin[i]);
	}
	cout << count;
	system("pause");
	return 0;
}