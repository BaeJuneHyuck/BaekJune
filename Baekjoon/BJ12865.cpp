#include <iostream>
using namespace std;

// 입력 물품수 N , 무게 K 
//      N줄에 무게와 가치
// 출력 최대 가치
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
	// DP[i][j] i 번째 물건까지 사용가능, j의 무게제한에서 최대
	for (int j = 0; j <= K; j++) {//0번째 물건사용? 
		DP[0][j] = 0;
	}
	for (int i = 1 ; i <= N; i++){
		for (int j = 0; j <= K; j++) {
			if (j < weight[i]) {
				DP[i][j] = DP[i-1][j]; // i번째를 무게제한에 의해 사용불가능
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - weight[i]] + value[i]);
			}
		}
	}
	cout << DP[N][K];
	return 0;
}
