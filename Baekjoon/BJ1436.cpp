#include <iostream>

using namespace std;

bool check(int num) {
	int temp = num;
	int count6 = 0;
	while (temp) {
		if (temp % 10 == 6) {
			count6++;
			if (count6 == 3) return true;
		}
		else {
			count6 = 0;
		}
		temp /= 10;
	}
	return false;
}

int main() {
	int N;
	cin >> N;
	int number = 665;
	int count = 0;
	while (count < N) {
		number++;
		if (check(number)) {
			count++;
		}
	}
	cout << number;
	system("pause");
	return 0;
}