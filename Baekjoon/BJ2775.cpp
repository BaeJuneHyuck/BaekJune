// ���� 2775 �γ�ȸ��
/*    1ȣ  2ȣ  3ȣ  4ȣ  5ȣ..
 0��:  1   2    3    4    5   6
 1��:  1   3    6    10   15  21
 2��:  1   4    10   20   35  56
 3��:  1   5    15   35   70  126
 4��:  1   6    21   56  126  252
*/
#include <iostream>
using namespace std;
int main() {
	int TB;
	int arr[15][15] = {};
	for (int i = 0; i < 15; i++)	arr[0][i] = i; // 0�� �ʱ�ȭ
	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			if (j == 1) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
			}
		}
	}
	
	cin >> TB;
	while (TB--) {
		int k, n; //k�� nȣ
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}
	system("pause");
	return 0;
}