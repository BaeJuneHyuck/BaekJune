#include <stdio.h>
#include <cstring>
#pragma warning(disable:4996);
using namespace std;

int path = 0;
int M, N;

int arr[501][501];
int dp[501][501];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int solve(int x, int y) {
	if (dp[x][y] != -1)return dp[x][y];// 0�� �ʱ�� ���ϸ� ��� 0���� �湮���� ���и��ؼ� DP�ƴ�
	if (x == M - 1 && y == N - 1) {
		return dp[x][y] = 1;
	}
	dp[x][y] = 0;// ����;;;
	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];

		if (arr[x][y] > arr[nextx][nexty] && (nextx >= 0) && (nexty >= 0) && (nextx < M) && (nexty < N)) {
			dp[x][y] += solve(nextx, nexty);
		}
	}
	return dp[x][y];
}

int main() {
	scanf("%d %d",&M, &N);// ���� M ���� N
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	memset(dp, -1, sizeof(dp));
	printf("%d", solve(0, 0));
	scanf("%d %d", &M, &N);// ���� M ���� N
	return 0;
}