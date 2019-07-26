#include <iostream>
#include <string>
using namespace std;

long long int dp[1000001];// dp[x] = x번째 내림수

bool check(int n) {
	int prev_digit = -1;
	if (n <= 10)return true;
	while (n) {
		int d = n % 10;
		n /= 10;
		if (d <= prev_digit) return false;
		prev_digit = d;
	}
	return true;
}

long long int solve(long long int n) {
	if (dp[n] != -1) return dp[n];
	if (n <= 10) dp[n] = n;
	else {
		dp[n] = solve(n - 1);
	}
	return dp[n];
}

int main() {
	int N;
	cin >> N;
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	int num = 0;
	for (int i = 0; i < 100; ) { // dp[10] = 10 ~ dp[54] == 98 즉 10단위로 94개
			num++;
			if (check(num)) {
				dp[++i] = num;
			}
	}
	if (N < 100) {
		cout << dp[N];
		system("pause");
		return 0;
	}
	for (int i = 100; i < N; i++) {

	}

	system("pause");
	return 0;
}