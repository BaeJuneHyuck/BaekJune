#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int arr[9][9];
int rowCheck[9][10]{ false, };
int colCheck[9][10]{ false, };
int cellCheck[9][10]{ false, };
vector<tuple<int,int>>zero;
int noz = 0;//number of zero
bool solved = false;

void solve(int zeroindex) {
	// 마지막 호출, 출력하고 종료
	if (solved) return;
	if (zeroindex == noz) {
		solved = true;
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				cout << arr[row][col] << " ";
			}cout << endl;
		}
		return;
	}
	
	// 백트랙킹
	int r = get<0>(zero[zeroindex]);
	int c = get<1>(zero[zeroindex]);
	int cell = 3 * (r / 3) + c / 3;
	for (int num = 1; num <= 9; num++) {
		if (!rowCheck[r][num] && !colCheck[c][num] && !cellCheck[cell][num]) {
			rowCheck[r][num] = colCheck[c][num] = cellCheck[cell][num] = true;
				arr[r][c] = num;
				solve(zeroindex + 1);
				arr[r][c] = 0;
				rowCheck[r][num] = colCheck[c][num] = cellCheck[cell][num] = false;
		}
	}
}

int main() {
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			int value;
			cin >> value;
			arr[row][col] = value;
			if (value == 0) {
				zero.push_back(make_tuple(row,col));
				noz++;
			} else{
				rowCheck[row][value] = true;
				colCheck[col][value] = true;
				cellCheck[3 * (row / 3) + col / 3][value] = true;
			}
		}cout << endl;
	}

	solve(0);
	system("pause");
	return 0;
}