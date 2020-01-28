#pragma warning(disable:4996)
#include <cstdio>
#include <string.h> // memset
using namespace std;

int N;
int r[501];
int c[501];
int DP[501][501];
int min(int a, int b) { return a > b ? b : a; }

int solve(int start, int end) {
	printf("solve %d %d\n", start, end);
	int& ans = DP[start][end];
	if (end - start == 1) return ans = r[start] * c[start] * c[end];
	if (ans != -1) return ans;
	// ABCD (0,3)¿Ã∏È  A BCD , AB CD, ABC D 
	// ABCDE(0,4)∏È  A BCDE, AB CDE, ABC DE, ABCD E
	ans = 9876543210;
	for (int k = 0; k < end - start; k++) {// 
		printf("k=%d solve [%d][%d], solve[%d][%d]\n", k, start, start + k, start + k + 1, end);
		ans = min(ans, solve(start, start+k) + solve(start + k + 1, end) + r[start] * c[start+k] * c[end]); // 
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	memset(DP, -1, sizeof(DP));

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &r[i], &c[i]);
		DP[i][i] = 0;
	}
	
	printf("%d", solve(0,N-1));
	return 0;
}