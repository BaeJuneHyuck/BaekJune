
#pragma warning(disable:4996)
#include <cstdio>
#include <string.h>
using namespace std;

int T, n;
int arr[5001];
int DP[5001][5001];
int sum[5001];//0부터 i까지 합

int min(int a, int b) { return a > b ? b : a; }

int solve(int start, int end) {// DP[s][e] s부터 e까지 합칠때 최소 비용
	int& ans = DP[start][end];
	if (ans != -1) return ans;
	if (end - start == 1)return ans = arr[start] + arr[end];
	ans = 9876543210;
	int last;
	for (int k = 0; k < end - start; k++) {// ABCD면 A BCD, AB CD, ABC D
		ans = min(ans, solve(start, start + k) + solve(start + k + 1, end) );
	}
	ans = ans + sum[end] - sum[start-1]; // DP값에 합치는 비용 까지 합쳐서 기억
	return ans;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);

		memset(DP, -1, sizeof(DP));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			DP[i][i] = 0;
		}
		sum[0] = arr[0];
		for (int i = 1; i < n; i++) {
			sum[i] = sum[i - 1] + arr[i];
		}
		printf("%d\n", solve(0,n-1));
	}
	return 0;
}
