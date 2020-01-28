#include <iostream>
using namespace std;

// �Է� ��ǰ�� N , ���� K 
//      N�ٿ� ���Կ� ��ġ
// ��� �ִ� ��ġ
int weight[102];
int value[102];
int N = 0, K = 0, Best = 0;
int DP[101][100001] = { 0, };

int max(int a, int b) { return a > b ? a : b; }

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int w, v;
		cin >> w >> v;
		weight[i] = w;
		value[i] = v;
	}
	// DP[i][j] i ��° ���Ǳ��� ��밡��, j�� �������ѿ��� �ִ�
	for (int j = 0; j <= K; j++) {//0��° ���ǻ��? 
		DP[0][j] = 0;
	}
	for (int i = 1 ; i <= N; i++){
		for (int j = 0; j <= K; j++) {
			if (j < weight[i]) {
				DP[i][j] = DP[i-1][j]; // i��°�� �������ѿ� ���� ���Ұ���
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	cout << DP[N][K];
	return 0;
}
