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

long long int interval(long long int n) {
	// x번째가 521 인걸 안다면 x+1번째는 530인걸 어떻게 수식화 시킬수잇을까
	// 무식한루프말고
	// 사람은 풀수잇잖아
	// 왜?
	// 각 자리수를 보는거야
	// 첫째자리는 앞자리 랑 1밖에 차이나지않아서 못올려
	// 둘째자리는 올릴수잇어
	// 그러면 0~9 사이의 값을 더해주면?
	// 만약에 954야
	// 그러면 둘째자리를 올려야하지, 그러면 10-첫째자리 만큼 더해주는거야
	int digits[25];
	int d = 0;
	long long int temp = n;
	while (temp) {
		digits[d++] = temp % 10;
		temp /= 10;
	}
	bool max = true; //현 자릿수에서 최대 내림수인가, ex 987, 98765
	for (int i = 0; i <= d; i++) {
		if (digits[i + 1] - digits[i] == 1) {
			if (digits[i + 1] == 9) {// 자리수를 올려야함 
				int next = 0;		// 98에서 올리면 210이 최소니까
				for (int j = 0; j <= d; j++) {
					next = next + j * pow(10, j);
				}
				cout << "자리변경필요, 다음수는 :" << next << endl;
				return next - n;
			}
			else return 10 - digits[i];
		}
		else if (digits[i + 1] - digits[i] > 1) {
			return 1 * pow(10, i);
		}
	}
}

long long int solve(long long int n) {
	if (dp[n] != -1) return dp[n];
	else {
		dp[n] = solve(n - 1) + interval(dp[n - 1]);
		return dp[n];
	}
}

int main() {
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= 10; i++) {
		dp[i] = i;
	}
	/*
	int N;
	cin >> N;
	int count = 0;
	long long int num =0;
	for (int i = 0; i <= 10; i++) {
		dp[i] = i;
	}
	solve(N);
	cout << dp[N];
	*/

	solve(100000);

	//for (int i = 0; i < 1000; i++) {
	//	cout << i << " : " << dp[i]<<endl;
	//}

	system("pause");
	return 0;
}