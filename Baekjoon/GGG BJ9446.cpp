#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

vector<vector<tuple<int, int>>> recipe;

long int cost[10001];
long int dp[10001];
int n, m;

long int make(int item) {
	if (dp[item] != -1) return dp[item];
	long int min = dp[item] = cost[item];

	for (int i = 0; i < recipe[item].size(); i++) {
		tuple<int, int> ingredi = recipe[item][i];
		long int temp = make(get<0>(ingredi)) + make(get<1>(ingredi));
		if (temp < min) min = temp;
	}
	
	return dp[item] = min;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	memset(dp, -1, sizeof(dp));
	recipe = vector<vector<tuple<int, int>>> (n + 1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		recipe[a].push_back(make_tuple(b, c));
	}

	cout << make(1);

	system("pause");
	return 0;
}