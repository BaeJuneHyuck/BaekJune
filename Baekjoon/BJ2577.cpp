//백준 2577 숫자의 갯수
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	long int mul = a * b*c;
	int arr[10] = { 0 };
	while (mul) {
		int digit = mul % 10;
		arr[digit]++;
		mul = mul / 10;
		//cout << "digit =" << digit << ", mul ="<<mul<<endl;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}