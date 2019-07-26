#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int arr[51][51];
int colorarr[51][51];

int room = 0;

// [] 시계방향, 벽잇으면 2. 4 8 1
// 그럼 9시부터 시작해서 1 2 4 8

// 13안에 4가 포함되어잇는가?
// >> 2해서 & 1 하면?

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };

vector<int> colornumber(2500);// color[i] i번째 그룹(방)이 몇칸인지 기억해두기
vector<vector<int>>adj; // i번째 방과 다른 방이 인접 ( 벽으로 막혀잇지만 붙어잇는경우)

void label(int row, int col, int color) {
	colorarr[row][col] = color;
	colornumber[color]++;
	for (int i = 0; i < 4; i++) {
		int nextrow = row + dr[i];
		int nextcol = col + dc[i];
		if (nextrow < 0 || nextrow >= m || nextcol < 0 || nextcol >= n)continue;
		
		if (!((arr[row][col] >> i) & 1) && !((arr[nextrow][nextcol] >> ((i+2)%4)) & 1) && (colorarr[nextrow][nextcol] == 0)) {
			label(nextrow, nextcol, color);
		}
	}
	return;
}

int main() {
	
	memset(colorarr, 0, sizeof(colorarr));

	cin >> n >> m;// col , row
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cin >> arr[row][col];
		}
	}
	
	// 아이디어
	// 인접한방들중 두개 합쳐서 젤 큰거가 벽 하나 제거햇을때 가장 큰 방으로 합쳐질것
	// 라벨링 통해서 방들을 구분지어주면서
	// 그 방의 크기를 기록, 다 끝나서 인접한 방중에 젤 큰거 두개만 선택하면 끝일거야

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			if(colorarr[row][col] == 0 ) label(row, col, ++room);
		}
	}
	
	// 출력1 방의갯수
	cout << room << endl;
	// 출력 2 가장 큰 방
	int max = 0;
	for (auto it = colornumber.begin(); it != colornumber.end() ; it++) {
		if (*it > max) max = *it;
	}
	cout << max << endl;
	// 출력 3 인접한 방들중 가장 합이 큰 두개
	int adjmax = 0;
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			for (int i = 0; i < 4; i++) {
				int nextrow = row + dr[i];
				int nextcol = col + dc[i];
				if (nextrow < 0 || nextrow >= m || nextcol < 0 || nextcol >= n)continue;
				int color1 = colorarr[nextrow][nextcol];
				int color2 = colorarr[row][col];
				if (color1 != color2) {
					if (colornumber[color1] + colornumber[color2] > adjmax) {
						adjmax = colornumber[color1] + colornumber[color2];
					}
				}
			}
		}
	}

	cout << adjmax << endl;

	/* 방 모양 확인
	cout << endl;
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << colorarr[row][col] << " ";
		}cout << endl;
	}*/

	system("pause");
	return 0;
}