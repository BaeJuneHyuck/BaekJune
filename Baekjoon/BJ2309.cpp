#include<iostream>

using namespace std;

int main() {
	int height[9], sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
		sum += height[i];
	}

	int i, j;
	bool find = false;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (i == j) continue;
			if (sum - height[i] - height[j] == 100) {
				i = height[i];
				j = height[j];
				find = true;
				break;
			}
		}
		if (find) break;
	}

	for (int x = 0; x < 9;  x++) {
		if (height[x] == i || height[x] ==j ) continue;
		int min = height[x], index = x;
		for (int y = x; y < 9;  y++) {
			if (height[y] == i || height[y] == j) continue;
			if (height[y] < min) {
				min = height[y];
				index = y;
			}
		}
		height[index] = height[x];
		height[x] = min;
		cout << height[x]<<endl;
	}

	system("pause");
	return 0;
}