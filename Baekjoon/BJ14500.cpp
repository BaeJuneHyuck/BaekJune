#pragma warning(disable:4996)
#include <cstdio>
int n, m;
int map[501][501];
bool visited[501][501];
int ans = 0;
int max(int a, int b) { return a > b ? a : b; }

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,+1 };

void dfs(int i, int j, int depth, int sum) {
	if (depth == 4) {
		ans = max(ans, sum);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nexti = i + dx[d];
		int nextj = j + dy[d];
		if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m || visited[nexti][nextj]) continue;
		visited[nexti][nextj] = true;
		dfs(nexti, nextj, depth + 1, sum+map[nexti][nextj]);
		visited[nexti][nextj] = false;
	}
	return;
}

int dTx[][4] = { {0,0,0,1}, {0,1,2,1}, {0,1,1,1}, {0,1,2,1} };
int dTy[][4] = { {0,1,2,1},{0,0,0,1},{0,0,1,-1},{0,0,0,-1} };
void T(int i, int j) {
	//4종류의 T에 대해서 
	/*
	
1
1 1
1

1 1 1
  1


  1
1 1
  1


  1
1 1 1

	*/
	for (int shape = 0; shape < 4; shape++) {
		int sum = 0;
		for (int d = 0; d < 4; d++) {
			int nexti = i + dTx[shape][d];
			int nextj = j + dTy[shape][d];
			if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= m) continue;
			sum += map[nexti][nextj];
		}
		ans = max(ans, sum);
	}
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 1 , map[i][j]);
			visited[i][j] = false;
			T(i, j);
		}
	}
	printf("%d", ans);
	return 0;
}