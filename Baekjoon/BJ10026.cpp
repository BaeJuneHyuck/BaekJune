#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int N;
char arr[101][101];
char color2[101][101];
char color3[101][101];
int c2 = 0;
int c3 = 0;

int dr[4] = { 1, 0 ,-1,0 };
int dc[4] = { 0, 1, 0, -1 };

void fill2(int row, int col, char color) {
	color2[row][col] = color;
	for (int i = 0; i < 4; i++) {
		int nextrow = row + dr[i];
		int nextcol = col + dc[i];
		if (nextrow < 0 || nextrow >= N || nextcol < 0 || nextcol >= N)continue;
		if (color2[nextrow][nextcol] == ' ') {
			if (arr[nextrow][nextcol] == color) fill2(nextrow, nextcol, color);
			else if (arr[nextrow][nextcol] == 'R' && color == 'G') fill2(nextrow, nextcol, color);
			else if (arr[nextrow][nextcol] == 'G' && color == 'R') fill2(nextrow, nextcol, color);
		}
	}
}

void fill3(int row, int col, char color) {
	color3[row][col] = color;
	for (int i = 0; i < 4; i++) {
		int nextrow = row + dr[i];
		int nextcol = col + dc[i];
		if (nextrow < 0 || nextrow >= N || nextcol < 0 || nextcol >= N)continue;
		if (arr[nextrow][nextcol] == color && color3[nextrow][nextcol] == ' ') fill3(nextrow, nextcol, color);
	}
}

int main() {
	cin >> N;
	string line;
	memset(color2, ' ', sizeof(color2));
	memset(color3, ' ', sizeof(color3));
	
	for (int row = 0; row < N; row++) {
		cin >> line;
		for (int col = 0; col < N; col++) {
			arr[row][col] = line[col];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (color2[row][col] == ' ') {
				c2++;
				fill2(row, col, arr[row][col]);
			}
			if (color3[row][col] == ' ') {
				c3++;
				fill3(row, col, arr[row][col]);
			}
		}
	}

	cout << c3 << " " << c2;
	system("pause");
	return 0;
}