// 그유명한 N queen 문제
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N;
int result = 0;

void bfs(vector<vector<int>>& map, int row) {
	//cout << "호출\n";
	if (row == N) {
		if (true) {
			/*
			for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					cout << map[row][col] << " ";
				}cout << endl;
			}
			cout << endl;
			*/
			result++;
		}
	}else{
		vector<tuple<int, int>> removed;
		for (int col = 0; col < N; col++) {
			if (map[row][col] != 0) continue;
			map[row][col] = 1;
			int r = row;
			int c = col;
			while (1) {
				r++;
				c--;
				if (r < 0 || r >= N || c < 0 || c >= N)break;
				if (map[r][c] != 0) continue;
				map[r][c] = -1;
				removed.push_back(make_tuple(r, c));
			}

			r = row;
			c = col;
			while (1) {
				r++;
				c++;
				if (r < 0 || r >= N || c < 0 || c >= N)break;
				if (map[r][c] != 0) continue;
				map[r][c] = -1;
				removed.push_back(make_tuple(r, c));
			}
			
			r = row;
			c = col;
			while (1) {
				r++;
				if (r < 0 || r>= N)break;
				if (map[r][c] != 0) continue;
				map[r][c] = -1;
				removed.push_back(make_tuple(r, c));
			}
			
			bfs(map, row + 1);

			map[row][col] = 0;
			for (int i = 0; i < removed.size(); i++) {
				tuple<int, int> cord = removed[i];
				map[get<0>(cord)][get<1>(cord)] = 0;
			}
		}
	}
}

int main() {
	cin >> N;
	//int map[16][16];
	vector<vector<int>>map(N + 1);
	for (int i = 0; i <= N; i++) {
		map[i] = vector<int>(N + 1);
	}
	bfs(map, 0);
	cout << result;
	system("pause");
	return 0;
}