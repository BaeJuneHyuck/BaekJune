#include <iostream>
using namespace std;

int main() {
	int N, M;
	int input[101];
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	int best = 0;
	int c1, c2, c3;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int l = j + 1; l < N; l++) {
				int sum = input[i] + input[j] + input[l];
				if (sum <= M && sum > best) {
					best = sum;
				}
			}
		}
	}
	cout << best;

	system("pause");
	return 0;
}