#include <iostream>
#include <string>
#include <queue>
using namespace std;

int arr[101][101];
int ans = 987654321;
int	h, w;//  height width
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

class node {
public:
	int r;
	int c;
	int m;
	node(int _r, int _c, int _m) :r(_r), c(_c), m(_m) {};
};

int main() {
	cin >> h >> w;
	for (int row = 0; row < h; row++) {
		string a;
		cin >> a;
		for (int col = 0; col < a.length(); col++) {
			arr[row][col] = a[col] - '0';
		}
	}

	bool visited[101][101];
	memset(visited, false, sizeof(visited));

	queue <node> q;
	q.push(node(0, 0, 1));
	visited[0][0] = true;

	while (!q.empty()) {
		node here = q.front();
		q.pop();

		int row = here.r;
		int col = here.c;
		int move = here.m;

		cout << "[" << move << "]" << col << ", " << row << endl;
		if (row == h - 1 && col == w - 1) {
			ans = move;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nextr = row + dx[i];
			int nextc = col + dy[i];
			if (nextr < 0 || nextr >= h || nextc < 0 || nextc >= w) continue;
			if (visited[nextr][nextc] == false && arr[nextr][nextc] == 1) {
				visited[nextr][nextc] = true;
				q.push(node(nextr, nextc, move + 1));
			}
		}
	}

	cout << ans;
	system("pause");
	return 0;
}