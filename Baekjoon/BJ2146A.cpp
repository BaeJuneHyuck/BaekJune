#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class node {
public:
	int row;
	int col;
	int move;
	int color;
	node(int _r, int _c, int _m, int _color):row(_r),col(_c),move(_m),color(_color){}
};

queue<node> q;
int arr[101][101];
int colorarr[101][101];
int distant[101][101];
int N;
int color = 0;
int dr[4] = { 0, 1, 0, -1 };
int dc[4] = { 1, 0, -1, 0 };


void fill(int row, int col, int color) {
	colorarr[col][row] = color;

	bool is_edge = true;
	for (int i = 0; i < 4; i++) {
		int nextrow = row + dr[i];
		int nextcol = col + dc[i];
		if (nextrow < 0 || nextrow >= N || nextcol < 0 || nextcol >= N)continue;
		if (arr[nextcol][nextrow] == 1 && colorarr[nextcol][nextrow] == 0) {
			fill(nextrow, nextcol, color);
		}
		if (arr[nextrow][nextcol] == 0) {
			is_edge = true;
		}
	}
	if (is_edge) {
		q.push(node(row, col, 0, color));
		distant[col][row] = 0;
	}
}

int main() {
	memset(colorarr, 0, sizeof(colorarr));

	cin >> N;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> arr[col][row];
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (colorarr[col][row] == 0 && arr[col][row] == 1) fill(row, col, ++color);
		}
	}

	//int currentmove = 0;
	int min = 987654321;
	while (!q.empty()) {
		node here = q.front();
		int row = here.row;
		int col = here.col;
		int color = here.color;
		int move = here.move;
		q.pop();
		/*
		if (currentmove != move) {
			cout << "-----------------" << move << "-----------\n";
			cout << endl;
			for (int row = 0; row < N; row++) {
				for (int col = 0; col < N; col++) {
					cout << colorarr[col][row] << " ";
				}cout << endl;
			}
			currentmove = move;
		}
		*/

		for (int i = 0; i < 4; i++) {
			int nextrow = row + dr[i];
			int nextcol = col + dc[i];
			if (nextrow < 0 || nextrow >= N || nextcol < 0 || nextcol >= N)continue;
			if (colorarr[nextcol][nextrow] == 0) {
				colorarr[nextcol][nextrow] = color;
				q.push(node(nextrow, nextcol, move + 1, color));
				distant[nextcol][nextrow] = move + 1;
			}
			else if (colorarr[nextcol][nextrow] != color) {
				int temp = distant[nextcol][nextrow] + distant[col][row];
				if (temp < min) min = temp;
			}
		}
	}
	cout << min;
	system("pause");
	return 0;
}