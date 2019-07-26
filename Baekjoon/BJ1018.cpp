#include <iostream>

using namespace std;

char board[51][51];

int fill(int x, int y) {
	int countW = 0;
	// 왼쪽제일위 w 시작인 체스판을 만들려면
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if ((i + j) % 2 == 0 && board[x + i][y + j] == 'B') countW++;
			if ((i + j) % 2 == 1 && board[x + i][y + j] == 'W') countW++;
		}
	}

	return countW<64-countW? countW: 64 - countW;
}

int main() {
	int N,M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if(temp == 'W')board[i][j] = 'W';
			else board[i][j] = 'B';
		}
	}

	// 8* 8을 고르는 가지수 == (M-8 * N-8)
	// 왼쪽 젤위를 골라서 함수를 돌리자
	int count = 0;
	int min = 987654321;
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int result = fill(i, j);
			if (result < min) min = result;
		}
	}

	cout << min;
	system("pause");
	return 0;
}