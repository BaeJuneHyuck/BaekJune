#include <iostream>
#include <string>
using namespace std;

long long int dp[1000001];// dp[x] = x��° ������

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
	// x��°�� 521 �ΰ� �ȴٸ� x+1��°�� 530�ΰ� ��� ����ȭ ��ų��������
	// �����ѷ�������
	// ����� Ǯ�����ݾ�
	// ��?
	// �� �ڸ����� ���°ž�
	// ù°�ڸ��� ���ڸ� �� 1�ۿ� ���̳����ʾƼ� ���÷�
	// ��°�ڸ��� �ø����վ�
	// �׷��� 0~9 ������ ���� �����ָ�?
	// ���࿡ 954��
	// �׷��� ��°�ڸ��� �÷�������, �׷��� 10-ù°�ڸ� ��ŭ �����ִ°ž�
	int digits[25];
	int d = 0;
	long long int temp = n;
	while (temp) {
		digits[d++] = temp % 10;
		temp /= 10;
	}
	bool max = true; //�� �ڸ������� �ִ� �������ΰ�, ex 987, 98765
	for (int i = 0; i <= d; i++) {
		if (digits[i + 1] - digits[i] == 1) {
			if (digits[i + 1] == 9) {// �ڸ����� �÷����� 
				int next = 0;		// 98���� �ø��� 210�� �ּҴϱ�
				for (int j = 0; j <= d; j++) {
					next = next + j * pow(10, j);
				}
				cout << "�ڸ������ʿ�, �������� :" << next << endl;
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