#include <iostream>

using namespace std;
int main() {
	
	int hist[10] = { 0, };
	int input;
	cin >> input;

	while (input) {
		hist[input % 10]++;
		input = input / 10;
	}

	for (int i = 9; i >= 0; i--) {
		while (hist[i] > 0) {
			hist[i]--;
			cout << i;
		}
	}

	system("pause");
	return 0;
}