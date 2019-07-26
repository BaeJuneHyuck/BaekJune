#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int arr[51][51];
int colorarr[51][51];

int room = 0;

// [] �ð����, �������� 2. 4 8 1
// �׷� 9�ú��� �����ؼ� 1 2 4 8

// 13�ȿ� 4�� ���ԵǾ��մ°�?
// >> 2�ؼ� & 1 �ϸ�?

int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { -1, 0, 1, 0 };

vector<int> colornumber(2500);// color[i] i��° �׷�(��)�� ��ĭ���� ����صα�
vector<vector<int>>adj; // i��° ��� �ٸ� ���� ���� ( ������ ���������� �پ��մ°��)

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
	
	// ���̵��
	// �����ѹ���� �ΰ� ���ļ� �� ū�Ű� �� �ϳ� ���������� ���� ū ������ ��������
	// �󺧸� ���ؼ� ����� ���������ָ鼭
	// �� ���� ũ�⸦ ���, �� ������ ������ ���߿� �� ū�� �ΰ��� �����ϸ� ���ϰž�

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			if(colorarr[row][col] == 0 ) label(row, col, ++room);
		}
	}
	
	// ���1 ���ǰ���
	cout << room << endl;
	// ��� 2 ���� ū ��
	int max = 0;
	for (auto it = colornumber.begin(); it != colornumber.end() ; it++) {
		if (*it > max) max = *it;
	}
	cout << max << endl;
	// ��� 3 ������ ����� ���� ���� ū �ΰ�
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

	/* �� ��� Ȯ��
	cout << endl;
	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			cout << colorarr[row][col] << " ";
		}cout << endl;
	}*/

	system("pause");
	return 0;
}