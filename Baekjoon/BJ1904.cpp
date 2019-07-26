#include <iostream>
#include <math.h>
using namespace std;

int DP[1000001];

int main() {
	
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;

	int N;
	cin >> N;
	for (int i = 4; i <= N; i++) {
		DP[i] = (DP[i - 1] + DP[i - 2]) % 15746;
	}
	cout << DP[N]<<endl;
	
	system("pause");
	return 0;
}
