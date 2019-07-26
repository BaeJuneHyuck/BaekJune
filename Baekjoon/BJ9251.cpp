// 9251 LCS
#include<iostream>
#include <string.h>
using namespace std;

char a[1002];
char b[1002];
int DP[1002][1002];

int max(int a, int b) {return a > b ? a : b;}

int main() {
	cin >> a;
	cin >> b;
	int lenA = strlen(a);
	int lenB = strlen(b);
	for (int i = 1; i < lenA+1; i++) {
		for (int j = 1; j < lenB+1; j++) {
			if (a[i - 1] == b[j - 1]) {
				DP[i][j] = max(DP[i - 1][j - 1] + 1, max(DP[i][j - 1], DP[i - 1][j]));
			}
			else {
				DP[i][j] = max(DP[i - 1][j - 1] , max(DP[i][j - 1] , DP[i - 1][j]));
			}
		}
	}

	for (int i = 0; i < lenB + 1; i++) {
		for (int j = 0; j < lenA + 1; j++) {
			cout << DP[j][i] << " ";
		}
		cout << endl;
	}
 	system("pause");
	return 0;
}