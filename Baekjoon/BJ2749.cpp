// 2749번 피보나치 수
// 피보나치 수를 행렬 곱셈을 이용하여 빠르게 계산해봅니다

#include <iostream>
using namespace std;
const int period = 1500000;
long long int arr[period] = {0,1};

int main() {
	long long int n;
	cin >> n;
	for (int i = 2; i < period; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		arr[i] %= 1000000;
	}
	cout << arr[n%period];
	system("pause");
	return 0;
}