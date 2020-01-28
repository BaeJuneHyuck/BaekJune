#pragma warning(disable:4996)
#include <cstdio>
#include <queue>
#include <string.h> //memcpy
int N, M, ans = 0;
int map[8][8];
int wallMap[8][8];
int di[] = { 0, 0, -1, 1 };
int dj[] = { 1, -1,0, 0 };
using namespace std;

void gas() {
	queue<pair<int, int>> q;
	int spreadMap[8][8];
	memcpy(spreadMap, wallMap, sizeof(spreadMap));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) { // 초기 바이러스 위치를 저장
			if (spreadMap[i][j] == 2) {
				q.push(make_pair(i, j));
			}
		}
	}
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nexti = i + di[d];
			int nextj = j + dj[d];
			if (nexti < 0 || nexti >= N || nextj < 0 || nextj >= M) continue;
			if (spreadMap[nexti][nextj] == 0) {
				spreadMap[nexti][nextj] = 2; //바이러스 감염
				q.push(make_pair(nexti, nextj));
			}
		}
	}
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (spreadMap[i][j] == 0) safe++;
		}
	}
	if (ans < safe)ans = safe;
}

void makeWall(int wall) {
	if (wall == 3) { // 3개의 벽이 만들어졋을경우 bfs시도
		gas();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (wallMap[i][j] == 0) {
				wallMap[i][j] = 1;
				makeWall(wall + 1);
				wallMap[i][j] = 0;
			}
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				memcpy(wallMap, map, sizeof(wallMap));// 맵 처음 작성시 복사후 벽쌓기시작
				wallMap[i][j] = 1;
				makeWall(1);
				wallMap[i][j] = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}