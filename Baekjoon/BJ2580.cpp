#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
bool finish = false;
vector<vector<vector<int>>> permutations;
vector<vector<int>> zero;
int input[9][9];
int total = 0;

void dfs(int arr[9][9], int row) {
	if (finish) return;
	if (row == 9) {
		
		// üũ���� , ����ϰ� ����������
		finish = true;// �ٸ� �Լ��������
		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				cout<<arr[row][col]<<" ";
			}cout << endl;
		}
		return;
	}

	for (int p = 0; p < permutations[row].size(); p++) {
		vector<int> permutation = permutations[row][p];// row�� �������մ� �ĺ� �ϳ�
		for (int j = 0; j < permutation.size(); j++) {
			int position = zero[row][j];
			arr[row][position] = permutation[j];
		}

		// ���� Ȯ��
		for (int c = 0; c < 9; c++) {
			bool numlist[10] = { false, };
			for (int r = 0; r < row; r++) {
				if (numlist[arr[r][c]] == true) return;
				else numlist[arr[r][c]] = true;
			}
		}
		// 3x3 üũ
		for (int x = 0; x + 3 < row; x += 3) {
			for (int y = 0; y + 3 < row; y += 3) {
				// �� 3x3�� ���� ������ ����
				bool numlist[10] = { false, };
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						if (numlist[arr[x + i][y + j]] == true) return;
						else numlist[arr[x + i][y + j]] = true;
					}
				}
			}
		}

		dfs(arr, row + 1);
	}
}


int main() {
	zero = vector<vector<int>>(10);
	permutations = vector<vector < vector<int>>>(10);
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			cin >> input[row][col];
		}
	}

	// ���ٸ��� ������ ������ ���� ����
	// ���������� ������ dfs �ϱ⵵ ���� ��û���� �����ɸ�
	for (int row = 0; row < 9; row++) {
		bool numlist[10] = { false, };
		vector<int> available;
		for (int col = 0; col < 9; col++) {
			if (input[row][col] != 0) numlist[input[row][col]] = true;
			else zero[row].push_back(col);// ���� 0�� col�� ��ġ�� ��Ͽ� ����
		}
		for (int number = 1; number < 10; number++) {// ��밡���� ���� ��� �ۼ�
			if (numlist[number] == false) available.push_back(number);
		}
		do {
			permutations[row].push_back(available);
		} while (next_permutation(available.begin(), available.end()));
	}

	cout << "dfs ����\n";
	dfs(input, 0);

	system("pause");
	return 0;
}