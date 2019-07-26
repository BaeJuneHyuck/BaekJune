#include <iostream>
using namespace std;

int DP[10001];
int wine[10001];

int MAX(int a, int b) { return a > b ? a : b; }
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> wine[i];
	}

	DP[0] = wine[0];
	if(N>1) DP[1] = wine[0] + wine[1];
	if (N > 2) DP[2] = MAX(wine[0] + wine[1], MAX(wine[0]+wine[2], wine[1]+wine[2]));
	for (int i = 3; i < N; i++) {
		int c1 = DP[i - 1]; // 자기 포함 안함
		int c2 = DP[i - 3] + wine[i - 1] + wine[i]; // 자기앞, 자기 둘다 포함
		int c3 = DP[i - 2] + wine[i];// 자기앞 포함 안하고 자기는 포함
		DP[i] = MAX(c1, MAX(c2,c3));
		cout << "i :" << i << endl;
		cout << c1 << "," << c2 <<"," << c3 << endl;
	}
	for (int i = 0; i < N; i++) {
		cout << DP[i]<<" ";
	}
	cout << endl<<DP[N-1];
	system("pause");
	return 0;
}