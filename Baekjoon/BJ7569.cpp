#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class point {
public:
	int x;
	int y;
	int z;
	int day;
	point(int _x, int _y, int _z,  int _d) {
		x = _x;
		y = _y;
		z = _z;
		day = _d;
	}
};

int input[101][101][101];
int visited[101][101][101];

const int dx[6] = { 0, 0, 1, -1, 0, 0 };
const int dy[6] = { 1, -1, 0, 0, 0, 0 };
const int dz[6] = { 0, 0, 0, 0, 1, -1 };
queue<point> q;
int M, N, H;
int maxday = -1;

int visit(int x, int y, int z, int d) {
	int nx, ny, nz;
	int ret= 0;
	for (int i = 0; i < 6; i++) {
		nx = x + dx[i]; ny = y + dy[i]; nz = z + dz[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
		{
			ret++;
			continue;
		}
		if (input[nx][ny][nz] == 0 && visited[nx][ny][nz] == -1) {
			q.push(point(nx, ny, nz, d + 1));
			visited[nx][ny][nz] = d + 1;
			if (d + 1 > maxday) maxday = d + 1;
		}
	}
	return ret;
}

void print() {
	cout << "---------------------\n";
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << visited[j][i][h] << " "; 
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> M >> N >> H;
	bool no0 = true;
	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> input[i][j][h];
				if (input[i][j][h] == 1) q.push(point(i, j, h, 0));
				if (input[i][j][h] == 0) no0 = false;
			}
		}
	}
	if (no0) {
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		print();
		point current = q.front();
		q.pop();
		int x = current.x;
		int y = current.y;
		int z = current.z;
		int d = current.day;
		visit(x, y, z, d);
	}

	for (int h = 0; h < H; h++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j][h]== -1 && input[i][j][h] == 0) {
					cout << -1;
					system("pause");
					return 0;
				}
			}
		}
	}
	cout << maxday;
	system("pause");
	return 0;
}