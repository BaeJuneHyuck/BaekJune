#include <iostream>
using namespace std;
int main() {
	int a, b, x, y;
	cin >> a >> b >> x >> y;

	int min = a<b? a: b;
	int d1 = x - a;
	int d2 = y - b;
	min = min < d1 ? min : d1;
	min = min < d2 ? min : d2;
	cout << min;

	system("pause");
	return 0;
}