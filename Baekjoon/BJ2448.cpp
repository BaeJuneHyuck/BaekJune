/* 백준 2448번, 별찍기 
 그리고자 하는 삼각형의 크기와 위치에 대한 함수를 정의해 재귀적으로 문제를 해결해봅니다

  idea : 
   어쨋든 큰 삼각형 3개로 쪼개짐... 그안에 삼각형3개...그안에 3개..
*/
#include <iostream>
using namespace std;

char arr[3072][6144];

void print(int size,int x,int y) {
	if (size == 3) {
		arr[y][x] = '*';
		arr[y+1][x+1] = '*';
		arr[y+1][x-1] = '*';
		arr[y + 2][x-2] = '*';
		arr[y + 2][x-1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x+1] = '*';
		arr[y + 2][x+2] = '*';
		return;
	}
	print(size / 2, x, y);
	print(size / 2, x - (size/2), y + (size/2));
	print(size / 2, x + (size/2), y + (size/2));
}

int main() {	
	int line;
	cin >> line;
	// array init
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < line * 2; j++) {
			arr[i][j] = ' ';
		}
	}

	print(line,line-1,0);

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < line * 2 - 1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}