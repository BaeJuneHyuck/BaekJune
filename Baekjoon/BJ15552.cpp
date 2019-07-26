// 백준 15552번 빠른 A+B
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int TB;
	cin >> TB;
	while (TB--) {
		int a, b;
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}