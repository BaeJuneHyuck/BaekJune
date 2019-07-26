#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[21][21];
int N;
int min = 1234567890;
vector<int> team1;
vector<int> team2;

void solve(int current, vector<int>team,  int remain) {
	if (remain == N/2) {
		int p1 = 0;
		int p2 = 0;
		vector<int> team2;
		bool player[21] = { false, };
		for (auto it = team.begin(); it != team.end(); it++) {
			player[*it] = true;
			for (auto it2 = team.begin(); it2 != team.end(); it2++) {
				if (it == it2) continue;
				p1 += arr[*it][*it2];
			}
		}
		for (int i = 0; i < N; i++) {
			if (!player[i])team2.push_back(i);
		}
		for (auto it = team2.begin(); it != team2.end(); it++) {
			for (auto it2 = team2.begin(); it2 != team2.end(); it2++) {
				if (it == it2) continue;
				p2 += arr[*it][*it2];
			}
		}
		if (abs(p1 - p2) < min) min = abs(p1 - p2);
	}
	else {
		for (int i = current + 1; i < N; i++) {
			team.push_back(i);
			solve(i, team, remain - 1);
			team.pop_back();
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	solve(0, team1, N);
	cout << min;
	system("pause");
	return 0;
}