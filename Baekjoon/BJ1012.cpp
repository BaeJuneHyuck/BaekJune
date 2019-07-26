#include <iostream>
#include <cstring>
using namespace std;
int arr[51][51];
int colorarr[51][51];

int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int m, n, k;

void fill(int row, int col, int color) {
	colorarr[row][col] = color;
	for (int i = 0; i < 4; i++) {
		int nextrow = row + dr[i];
		int nextcol = col + dc[i];
		if (nextrow < 0 || nextrow >= n || nextcol < 0 || nextcol >= m)continue;
		if (arr[nextrow][nextcol] == 1 && colorarr[nextrow][nextcol] == 0) fill(nextrow, nextcol, color);
	}
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> m >> n >> k;

		memset(arr, 0, sizeof(arr));
		memset(colorarr, 0, sizeof(colorarr));
		for (int i = 0; i < k; i++) {
			int row, col;
			cin >> row >> col;
			arr[col][row] = 1;
		}

		int total = 0;
		for (int row = 0; row < n; row++) {
			for (int col = 0; col < m; col++) {
				if (arr[row][col] == 1 && colorarr[row][col] == 0) fill(row, col, ++total);
			}
		}
		cout << "´ä:";
		cout << total << endl;
	}

	system("pause");
	return 0;
}