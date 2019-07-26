#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, S;
	int arr[20];
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int count = 0;
	int bit = 1;

	// 2**n번 계산해보기
	for (; bit < pow(2, N); bit++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if( (bit >> i) & 1) sum += arr[i];
		}
		if (sum == S) count++;
	}
	cout << count;
	system("pause");
	return 0;
}