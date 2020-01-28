#include <iostream>
using namespace std;
int N;
int arr[2188][2188];
int ans_z = 0;
int ans_p = 0;
int ans_n = 0;

void prove(int r, int c, int N ) {
	int prev = arr[r][c];
	bool result = true;
	for (int row = r; row < r + N; row++) {
		for (int col = c; col < c + N; col++) {
			if (prev != arr[row][col]) {
				result = false;
				break;
			}
		}
		if (!result) break;
	}
	
	if (!result) {
		prove(r, c, N / 3);
		prove(r + N / 3, c, N / 3);
		prove(r + N * 2 / 3, c, N / 3);

		prove(r, c + N / 3, N / 3);
		prove(r + N/ 3, c + N / 3, N / 3);
		prove(r + N*2 /3, c + N/3, N / 3);

		prove(r, c + N * 2 / 3, N / 3);
		prove(r + N / 3, c + N * 2 / 3, N / 3);
		prove(r + N * 2 / 3, c + N * 2 / 3, N / 3);
	}
	else {
		switch (prev) {
		case -1: ans_n++; break;
		case 0: ans_z++; break;
		case 1: ans_p++; break;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			cin >> arr[row][col];
		}
	}
	
	prove(0, 0, N);

	cout << ans_n << endl;
	cout << ans_z << endl;
	cout << ans_p << endl;

	return 0;
}