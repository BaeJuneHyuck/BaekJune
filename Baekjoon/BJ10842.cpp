#pragma warning(disable:4996)
#include <cstdio>
#include <string.h>//memset
int DP[2001][2001];
int arr[2001];
int N, M, S, E;

int solve(int S, int E) {// 10 20 들어왓을때... 12 18이 1인걸 알면?
	int& ans = DP[S][E];
	if (ans != -1) {
		return ans;	//printf("%d dp사용");
	}
	if (E == S) {
		return ans = 1; //printf("길이 1"); 
	}
	if (arr[S] == arr[E]) {
		if (E - S == 1) return 1;
		else return ans = solve(S + 1, E - 1);
	}
	else return ans = 0;
}

int main() {
	memset(DP, -1, sizeof(DP));

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &S, &E);
		printf("%d\n" ,solve(S, E));
	}
	return 0;
}