#include <iostream>

using namespace std;

int arr[129][129];
int white = 0;
int blue = 0;

void check(int x, int y, int n) {
	if (n == 1) {
		if (arr[x][y] == 0) white++;
		else blue++;
		return;
	}
	int count1 = 0;
	int count0 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[x + i][y + j] == 0)count0++;
			else count1++;
		}
	}
	if (count0 == 0) {
		blue++;
		return;
	}
	else if (count1 == 0) {
		white++;
		return;
	}
	else {
		check(x, y, n / 2);
		check(x + n / 2, y, n / 2);
		check(x, y + n / 2, n / 2);
		check(x+ n / 2, y+ n / 2, n / 2);
	}
	return;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	check(0, 0, N);

	cout << white << endl << blue;
	system("pause");
	return 0;
}