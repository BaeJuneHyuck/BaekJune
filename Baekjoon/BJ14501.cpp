#include <iostream>

using namespace std;
int N;
int profit[16];
int time[16];
int ans;
void dfs(int n, bool use, int total) {
	if (n > N)return;
	if (use) {
		if (n + time[n] <= N + 1) {
			total += profit[n];
			if (total > ans) ans = total;
			dfs(n + time[n], true, total);
			dfs(n + time[n], false, total);
		}
	}
	else {
		dfs(n + 1, true, total);
		dfs(n + 1, false, total);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> profit[i];
	}
	dfs(1, true, 0);
	dfs(1, false, 0);
	cout << ans;
}