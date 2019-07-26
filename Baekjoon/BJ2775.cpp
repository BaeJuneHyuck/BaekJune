// ¹éÁØ 2775 ºÎ³àÈ¸Àå
/*    1È£  2È£  3È£  4È£  5È£..
 0Ãþ:  1   2    3    4    5   6
 1Ãþ:  1   3    6    10   15  21
 2Ãþ:  1   4    10   20   35  56
 3Ãþ:  1   5    15   35   70  126
 4Ãþ:  1   6    21   56  126  252
*/
#include <iostream>
using namespace std;
int main() {
	int TB;
	int arr[15][15] = {};
	for (int i = 0; i < 15; i++)	arr[0][i] = i; // 0Ãþ ÃÊ±âÈ­
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
		int k, n; //kÃþ nÈ£
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}
	system("pause");
	return 0;
}