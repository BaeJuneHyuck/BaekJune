#include <iostream>
#include <string>
#include <queue>
using namespace std;

int n, m;
int arr[1001][1001];// 10 6 = 1mb
int dist[1001][1001][2];//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0 , -1 };

class node {
public:
	int row;
	int col;
	int power;
	node(int _r, int _c, int _p) :
		row(_r), col(_c),power(_p) {}
};

int main() {
	cin >> n >> m;
	for (int row = 0; row < n; row++) {
		string in;
		cin >> in;
		for (int col = 0; col < m; col++) {
			arr[row][col] = in[col] - '0';
		}
	}

	/*
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cout << arr[row][col] << " ";
		}cout << endl;
	}
	*/
	queue<node> q;
	q.push(node(0, 0, 1));//0,0에서 power 가진채로 시작
	dist[0][0][1] = 1;// "0,0을 power 가진채로 도달하는 최소 경로는 1" 을 기억해두기
	while (!q.empty()) {
		node here = q.front();
		q.pop();
		
		int row = here.row;
		int col = here.col;
		int power = here.power;

		if (row == n - 1 && col == m - 1) {
			cout << dist[row][col][power];
			system("pause");
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nextrow = row + dr[i];
			int nextcol = col + dc[i];
			if (nextrow < 0 || nextrow >= n || nextcol < 0 || nextcol >= m)continue;
			if (arr[nextrow][nextcol] == 0 && dist[nextrow][nextcol][power] == 0) {
				q.push(node(nextrow, nextcol, power));
				dist[nextrow][nextcol][power] = dist[row][col][power] + 1;
			}
			else if (arr[nextrow][nextcol] == 1 && power) {
				q.push(node(nextrow, nextcol, !power));
				dist[nextrow][nextcol][!power] = dist[row][col][power] + 1;
			}
		}
	}

	cout << "-1";

	system("pause");
	return 0;
}