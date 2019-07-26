#include<iostream>
#include <fstream>
using namespace std;

char arr[6562][6562]; // 3**7 = 2187
void recursive_star(int x, int y, int N) { // N*N  start from (x,y)
	int inter = N / 3;
	if (N <= 3) {
		//종료조건
		arr[x + 0][y + 0] = '*';
		arr[x + 0][y + 1] = '*';
		arr[x + 0][y + 2] = '*';
		arr[x + 1][y + 0] = '*';
		arr[x + 1][y + 1] = ' ';
		arr[x + 1][y + 2] = '*';
		arr[x + 2][y + 0] = '*';
		arr[x + 2][y + 1] = '*';
		arr[x + 2][y + 2] = '*';
		return;
	}
	// 재귀 9 등분해서, 중간 빼고 8번
	recursive_star(x, y, inter);
	recursive_star(x + inter, y, inter);
	recursive_star(x + 2* inter, y, inter);
	recursive_star(x, y + inter, inter);
	//recursive_star(x + inter, y + inter, inter);
	recursive_star(x + 2 * inter, y + inter, inter);
	recursive_star(x, y+2*inter, inter);
	recursive_star(x + inter, y + 2*inter, inter);
	recursive_star(x + 2 * inter,  y + 2*inter, inter);
}

int main() {
	int T;
	cin >> T;
	recursive_star(0,0,T);

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < T; j++) {

			// 이런 개 씨
			//
			//	cout << arr[i][j];
			// 이거 그대로 출력하면 답이 안되는데?;;; 얼탱이 없네
			if (arr[i][j] == '*')cout << '*';
			else cout << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}