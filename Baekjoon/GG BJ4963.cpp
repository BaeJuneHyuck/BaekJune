#include <iostream>
#include <cstring>
using namespace std;

int dx[8] = { 0, 1, 1, 1, 0, -1 ,-1, -1};
int dy[8] = { 1, 1, 0, -1, -1, -1, 0 ,1};

int w,h;
int arr[51][51];
int colorarr[51][51];
int color = 0;

void fill(int row, int col, int color) {
	colorarr[row][col] = color;
	for (int i = 0; i < 8; i++) {
		int nextrow = row + dx[i];
		int nextcol = col + dy[i];
		if (nextrow < 0 || nextrow > h || nextcol < 0 || nextcol > w) continue;
		if (arr[nextrow][nextcol] == 1 && colorarr[nextrow][nextcol] == 0) {
			fill(nextrow, nextcol, color);
		}
	}
	return;
}

int main() {
	while (cin >> w >>h) {
		if (w == 0 && h == 0) break;

		memset(colorarr, 0, sizeof(colorarr));
		memset(arr, 0, sizeof(arr));
		for (int row = 0; row < h; row++) {
			for (int col = 0; col < w; col++) {
				cin >> arr[row][col];
			}
		}

		color = 0;
		

		for (int row = 0; row < h; row++) {
			for (int col = 0; col < w; col++) {
				if (arr[row][col] == 1 && colorarr[row][col] == 0) {
					fill(row, col, ++color);
				}
			}
		}
		
		cout << color << endl;
		/*
		for (int row = 0; row < h; row++) {
			for (int col = 0; col < w; col++) {
				cout << colorarr[row][col] << " ";
			}cout << endl;
		}
		*/
	}

	system("pause");
	return 0;
}