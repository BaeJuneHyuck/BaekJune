#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

class point {
public:
	int x;
	int y;
	int day;
	point(int _x, int _y, int _d) {
		x = _x;
		y = _y;
		day = _d;
	}
};

int input[1001][1001];
int visited[1001][1001];
queue<point> q;
int M, N;
int maxday = -1;

int visit(int x, int y, int d) {
	if (x < 0 || x >= N || y < 0 || y >= M)return 1;

	//cout << x << "," << y << "," << d << ":: "<< input[x][y]<<endl;
	if (input[x][y + 1] == 0 && visited[x][y + 1] == -1) {
		q.push(point(x, y + 1, d + 1));
		visited[x][y + 1] = d + 1;
	}
	if (y>0 && input[x][y - 1] == 0 && visited[x][y - 1] == -1) {
		q.push(point(x, y - 1, d + 1));
		visited[x][y - 1] = d + 1;
	}
	if (input[x + 1][y] == 0 && visited[x + 1][y] == -1) {
		q.push(point(x + 1, y, d + 1));
		visited[x + 1][y] = d + 1;
	}
	if (x>0 && input[x - 1][y] == 0 && visited[x - 1][y] == -1) {
		q.push(point(x - 1, y, d + 1));
		visited[x - 1][y] = d + 1;
	}
	return 0;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << input[j][i];
		}
		cout << endl;
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input[i][j];
			if (input[i][j] == 1) q.push(point(i, j, 0));
		}
	}

	while (!q.empty()) {
		point current = q.front();
		q.pop();
		int x = current.x;
		int y = current.y;
		int d = current.day;
		if (visit(x, y, d) == 0) {
			if (d > maxday) maxday = d;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == -1 && input[i][j] == 0) {
				cout << -1;
				system("pause");
				return 1;
			}
		}
	}
	system("pause");
	cout << maxday;
	return 0;
}