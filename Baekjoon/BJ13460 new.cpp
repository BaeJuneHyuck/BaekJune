// 구슬 충돌처리 아이디어 참고 : https://rebas.kr/725

#include <iostream>
#include <queue>

using namespace std;
int M, N;
char map[11][11];
bool visit[11][11][11][11]; 
struct point { int rx, ry, bx, by, count; };
queue<point> q;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,-1,0,1 };

void move(int &x, int &y, int dx, int dy, int& c) {
	while (map[x + dx][y + dy] != '#' && map[x][y] != 'O') {
		x += dx;
		y += dy;
		c += 1;
	}
}

void bfs() {
	while (!q.empty()) {
		int rx = q.front().rx;
		int ry = q.front().ry;
		int bx = q.front().bx;
		int by = q.front().by;
		int count = q.front().count;
		q.pop();
		// cout << "q:" << rx << ry << "," << bx << by << "/" << count << endl;
		if (count >= 10)break;
		for (int i = 0; i < 4; i++) {
			int nRx = rx, nRy = ry, nBx = bx, nBy = by;
			int rc = 0, bc = 0, nc = count+1; // 구슬이동횟수을 기억, 겹쳣을때 활용
			move(nRx, nRy, dx[i], dy[i], rc); // 빨구
			move(nBx, nBy, dx[i], dy[i], bc); // 파구
			if (map[nBx][nBy] == 'O') continue; // 파란구슬이 들어가면 안됨
			if (map[nRx][nRy] == 'O') { // 종료
				cout << nc;
				return;
			}
			if (nRx == nBx && nRy == nBy) { // 구슬이 겹쳤다
				if (rc > bc) {// 빨간구슬이 더많이 움직엿다면 빨간구슬위치 이동
					nRx -= dx[i];
					nRy -= dy[i];
				}
				else {
					nBx -= dx[i];
					nBy -= dy[i];
				}
			}
			if (visit[nRx][nRy][nBx][nBy])continue;
			visit[nRx][nRy][nBx][nBy] = true;
			q.push({ nRx,nRy,nBx,nBy,nc });
		}
	}
	cout << "-1";
}

int main() {
	int rx, ry, bx, by;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') { rx = i, ry = j; }
			if (map[i][j] == 'B') { bx = i, by = j; }
		}
	}
	q.push({ rx, ry, bx, by, 0 });
	visit[rx][ry][bx][by] = true;
	bfs();
	return 0;
}