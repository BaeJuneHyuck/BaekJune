#include <iostream>
#include <string>
using namespace std;

char arr[65][65];
string result;

void check(int x, int y, int n) {

	if (n == '1') {
		if (arr[x][y] == '0') result.append("0");
		else result.append("1");
		return;
	}
	int count1 = 0;
	int count0 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[x + i][y + j] == '0')count0++;
			else count1++;
		}
	}
	if (count0 == 0) {
		result.append("1");
		return;
	}
	else if (count1 == 0) {
		result.append("0");
		return;
	}
	else {
		result.append("(");
		check(x, y, n / 2);
		check(x, y + n / 2, n / 2);
		check(x + n / 2, y, n / 2);
		check(x + n / 2, y + n / 2, n / 2);
		result.append(")");
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

	cout << result;
	system("pause");
	return 0;
}