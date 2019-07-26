#include <iostream>
#include <math.h>
using namespace std;

long long int DP[101][10];

int main() {
	for (int i = 0; i < 10; i++) {
		DP[1][i] = 1;
	}
	int N;
	cin >> N;

	//DP
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) DP[i][j] = DP[i - 1][1] % 1000000000;
			else if (j == 9) DP[i][j] = DP[i - 1][8] % 1000000000;
			else {
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
			}
		}
	}

	long long int sum = 0;

	for (int i = 1; i < 10; i++) {
		sum = (sum + DP[N][i] ) % 1000000000;
	}

	cout << sum << endl;
	system("pause");
	return 0;
}
