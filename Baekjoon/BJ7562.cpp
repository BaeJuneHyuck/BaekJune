#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

class knight {
public:
	int x;
	int y;
	int move;
	knight(int _x, int _y, int _m) {
		x = _x;
		y = _y;
		move = _m;
	}
};

const int dx[8] = { 1, 2 , 2 , 1 ,-1 ,-2 ,-1 ,-2 };
const int dy[8] = { 2, 1, -1, -2, -2, -1, 2, 1 };
bool visited[301][301];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int I, x, y, tx, ty;
		memset(visited, false, sizeof(visited));
		cin >>I>> x >> y >> tx >> ty;

		if (x == tx && y == ty) {
			cout << 0 <<endl;
			continue;
		}

		queue<knight> q;
		q.push(knight(x, y, 0));
		visited[x][y] = true;
		
		bool end = false;
		while (!q.empty()) {
			knight current = q.front();
			q.pop();

			for (int i = 0; i < 8; i++) {
				int nextX = current.x + dx[i];
				int nextY = current.y + dy[i];
				int m = current.move;
				if (visited[nextX][nextY]) continue;
				if (nextX < 0 || nextX >= I || nextY < 0 || nextY >= I) continue;
				//cout << "[" << nextX << "," << nextY << "]\n";
				if (nextX == tx && nextY == ty) {
					cout << m + 1 <<endl;
					end = true;
					break;
				}
				visited[nextX][nextY] = true;
				q.push(knight(nextX, nextY, m + 1));
			}
			if (end) break;
		}
	}

	system("pause");
	return 0;
}
