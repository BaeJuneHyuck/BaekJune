/* ���̵��
// ���� �ϴ� ���������ְ� (connected component)
// 2�� �������� �ΰ� �� ����
// ���� �� ������ ���鰣�� �ִܰŸ� ���� ���ؼ�
// �ּҰ� ����
*/
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <cstring> // memset

using namespace std;

int N;
int arr[101][101];
int colorarr[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int color = 0;

vector<vector<tuple<int, int>>> island;// island[color] (x, y) , ������ color�� ���� ���� x,y�� ����
class node {
public:
	int r;
	int c;
	int m;
	node(int _r, int _c, int _m) :r(_r), c(_c), m(_m) {}
};

void fill(int row, int col, int color) {
	colorarr[row][col] = color;

	bool is_edge = false;
	for (int i = 0; i < 4; i++) {
		int nextrow = row + dx[i];
		int nextcol = col + dy[i];
		if (nextrow < 0 || nextrow > N || nextcol < 0 || nextcol > N) continue;
		if (arr[nextrow][nextcol] == 1 && colorarr[nextrow][nextcol] == 0) {
			fill(nextrow, nextcol, color);
		}
		if (arr[nextrow][nextcol] == 0) {
			is_edge = true;
		}
	}
	if(is_edge)
		island[color].push_back(make_tuple(row, col));
	return;
}

int main() {
	cin >> N;
	island = vector<vector<tuple<int, int>>> (N*N);
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> arr[row][col];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (arr[row][col] == 1 && colorarr[row][col] == 0) fill(row,col,++color);
		}
	}

	/*
	cout << endl;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cout << colorarr[row][col] << " ";
		}
		cout << endl;
	}*/

	int ans = 987654321;
	for (int i = 1; i <= color; i++) {
		for (int j = i + 1; j <= color; j++) {
			// ��缶 ����(color) �߿��� i ��, j�� �� �����ؼ�

			cout << "------ {" << i << "," << j << "} ------- \n";	
			cout << "i = " << i << " :" << island[i].size()<<endl;
			cout << "j = " << j << " :" << island[j].size()<<endl;
			for (int x = 0; x < island[i].size(); x++) {
				for (int y = 0; y < island[j].size(); y++) {
					// ���� �����ڸ� �ĺ� from, to�� ���ؼ� bfs
					// ��� �Ÿ��� ���ؼ� �ּ��ΰ� ����
					tuple<int, int> from = island[i][x];
					tuple<int, int> to = island[j][y];
					int from_row = get<0>(from);
					int from_col = get<1>(from);
					int target_row = get<0>(to);
					int target_col = get<1>(to);
					cout << "[" << from_col << "," << from_row << "] -> [" << target_col << "," << target_row << "]\n";
					bool visited[101][101];
					memset(visited, false, sizeof(visited));

					queue <node> q;
					q.push(node(from_row, from_col, 0));
					visited[from_row][from_col] = true;

					while (!q.empty()) {
						node here = q.front();
						q.pop();

						int row = here.r;
						int col = here.c;
						int move = here.m;

						// �����ּҺ��� ū�� ���ʿ� ���� �ɼ������� ������ �ð� ����
						if (move >= ans) continue;
						
						bool arrive = false;
						for (int i = 0; i < 4; i++) {
							if (row == target_row + dx[i] && col == target_col + dy[i]) {
								if (move < ans) ans = move;
								cout << "�����ּ�:" << move << endl;
								arrive = true;
							}
						}
						
						if(!arrive){
							for (int i = 0; i < 4; i++) {
								int nextr = row + dx[i];
								int nextc = col + dy[i];
								if (nextr < 0 || nextr >= N || nextc < 0 || nextc >= N) continue;
								if (visited[nextr][nextc] == false && arr[nextr][nextc] == 0) {
									visited[nextr][nextc] = true;
									q.push(node(nextr, nextc, move + 1));
								}
							}
						}
					}

				}
			}

		}
	}
	
	cout << ans << endl;

	system("pause");
	return 0;
}