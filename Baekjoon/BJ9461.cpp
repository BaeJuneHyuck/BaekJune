#include <iostream>
#include <math.h>
using namespace std;

long long int DP[101];

int main() {

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;
	DP[4] = 2;
	DP[5] = 2;
	for (int i = 6; i <= 100; i++) {
		DP[i] = DP[i - 5] + DP[i - 1];
		cout << DP[i] << endl;
	}
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;
		cout << DP[N] << endl;
	}
	
	system("pause");
	return 0;
}
