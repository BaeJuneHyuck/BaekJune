#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N; 
char arr[26][26];
int colorarr[26][26];
int color = 0;
vector<int> result;

void fill(int x, int y, int color) {
	cout << x<<", "<<y<<" : "<<color << endl;
	
	colorarr[x][y] = color;
	result[color]++;

	for (int i = 0; i < 4; i++) {
		int nextx = x + dx[i];
		int nexty = y + dy[i];
		if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N) continue;
		if (arr[nextx][nexty] == '1' && colorarr[nextx][nexty] == 0)fill(nextx, nexty, color);
	}
	return;
}

int main() {
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string temp;
		getline(cin, temp);
		for (int j = 0; j < temp.size(); j++) {
			arr[i][j] = temp[j];
		}
	}

	for (int i = 0; i < N; i++) {
		cout << i << " : ";
		for (int j = 0; j <= N; j++) {
			cout<< arr[i][j];
		}cout << endl;
	}

	result = vector<int>(N*N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == '1' && colorarr[i][j] == 0) fill(i, j, ++color);
		}
	}
	
	cout << color <<endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		if (result[i] != 0) cout << result[i] << endl;
	}

	system("pause");
	return 0;
}