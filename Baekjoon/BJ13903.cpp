#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C, N;
int arr[1001][1001];
int visited[1001][1001];
int dr[11];
int dc[11];

class node {
public:
	int r;
	int c;
	int m;
	node(int _r, int _c, int _m) :r(_r), c(_c), m(_m) {}
};

int main() {
	cin >> R >> C;
	for (int row = 0; row < R; row++) {
		for (int col = 0; col < C; col++) {
			cin >> arr[row][col];
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> dr[i] >> dc[i];
	}
	
	memset(visited, -1, sizeof(visited));
	queue<node> q;
	for (int col = 0; col < C; col++) {
		if (arr[0][col] == 1) {
			q.push(node(0, col, 0));
			visited[0][col] = 0;
		}
	}
	
	int ans = -1;
	while (!q.empty()) {
		node here = q.front();
		q.pop();

		int row = here.r;
		int col = here.c;
		int move = here.m;
		if (row == R - 1) {
			ans = move;
			break;
		}
		for (int i = 0; i < N; i++) {
			int nextrow = row + dr[i];
			int nextcol = col + dc[i];
			if (nextrow < 0 || nextrow >= R || nextcol < 0 || nextcol >= C) continue;
			if (visited[nextrow][nextcol] != -1 || arr[nextrow][nextcol] == 0) continue;
			q.push(node(nextrow, nextcol, move + 1));
			visited[nextrow][nextcol] = move + 1;
		}
	}
	cout << ans;
	system("pause");
	return 0;
}