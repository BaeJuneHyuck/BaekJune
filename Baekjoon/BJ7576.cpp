// �丶��

#include <iostream>
#include <cstring>

#include <iomanip>

using namespace std;

int box[1003][1003];
int M, N;
int day = 0;

void printbox() {
	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < M + 2; j++) {
			cout << setw(4) << box[i][j];
		}
		cout << endl;
	}
}

int daypass() {
	day++;
	int clear = 2;// 2 �۾� ����(����), 1 �۾� �Ұ���, 0 �۾� ������
	bool allclear = true;
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < M + 1; j++) {
			if (box[i][j] == 0) {
				clear = 0;
				allclear = false;
				if (box[i + 1][j] == -1 && box[i - 1][j] == -1 &&
					box[i][j + 1] == -1 && box[i][j - 1] == -1) {
					// ����Ұ����� �丶�� ����, 
					return 1;
				}
			}
			else if (box[i][j] == 1) {
				if (!box[i + 1][j]) box[i + 1][j] = 2;
				if (!box[i - 1][j]) box[i - 1][j] = 2;
				if (!box[i][j + 1]) box[i][j + 1] = 2;
				if (!box[i][j - 1]) box[i][j - 1] = 2;
			}
		}
	}
	for (int i = 0; i < N+2; i++) {
		for (int j = 0 ; j < M+2; j++) {
			if (box[i][j] == 2) {
				clear = 0;
				box[i][j] = 1;
			}
		}
	}
	if (allclear && clear == 2) day--;
	return clear;
}

int main() {
	cin >> M >> N;
	memset(box, -1, sizeof(box));
	for (int i = 1; i < N+1; i++) {
		for (int j = 1; j < M+1; j++) {
			scanf("%d",&box[i][j]);
		}
	}

	int result = 0;
	while (!result) {
		result = daypass();
	
		//cout << "day : " << day << ", result : " << result << endl;
		//printbox();
		
		if (result == 1) cout << -1;
		if (result == 2) cout << day;
	}

	system("pause");
	return 0;
}