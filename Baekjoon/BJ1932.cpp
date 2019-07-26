// ���� 1932�� , ���� �ﰢ��
#include <iostream>
using namespace std;
int a[500][500];
int cache[500][500];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int getMax(int floor) {
	int max = 0;
	for (int index = 0; index < floor; index++) {
		if (cache[floor-1][index] > max)
			max = cache[floor-1][index];
	}
	return max;
}

int calc(int size) {
	int floor;
	cache[0][0] = a[0][0];
	for (int i = 1; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {// �� �� ����
				cache[i][j] = a[i][j] + cache[i - 1][j];
			}
			else if (j == i) {// ���� ������
				cache[i][j] = a[i][j] + cache[i - 1][j-1];
			}
			else { // �ƴҰ�� ���� ������ �� ū���� ����
				cache[i][j] = max(a[i][j] + cache[i-1][j-1], a[i][j] + cache[i-1][j]);
			}
		}
	}
	return getMax(size);
}

int main() {
	int tSize;
	cin >> tSize;
	for (int i = 0; i < tSize; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << calc(tSize);
	system("pause");
	return 0;
}

/* sungahn ���� �ڵ�
// ���� ����-1 ���� �����ؼ� �ö󰡸鼭 �ִ밪������
// ��������� 1���� ����⿡�� �ִ��� ���Ե�...
// �Ϳ�!

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *minimum;
	int *arr;
	int floor;
	int sum = 0;

	scanf("%d", &floor );

	sum = (floor * (floor + 1)) / 2;

	arr = malloc(sizeof(int) * sum);
	minimum = malloc(sizeof(int) * floor);

	for (int i = 0; i < sum; i++) {
		scanf("%d", &arr[i]);
	}
	sum -= floor + 1;

	for(int i = floor - 1; i > 0; i--) {
		for (int j = i; j > 0; j --) {
			arr[sum] += arr[sum + i] < arr[sum + i + 1] ? arr[sum + i + 1] : arr[sum + i];
			sum --;
		}
	}
	printf("%d", arr[0]);

	return 0;
}

*/