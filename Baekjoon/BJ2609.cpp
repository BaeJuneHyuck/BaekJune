#include <iostream>
using namespace std;

int main() {
	int a, b, lcm, gcd;
	cin >> a >> b;
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	for (int temp = 1 ; temp <= b; temp++) {
		if (a % temp == 0 && b % temp == 0) gcd = temp;
	}

	lcm = a * b / gcd;
	cout << gcd << endl << lcm;

	system("pause");
	return 0;
}