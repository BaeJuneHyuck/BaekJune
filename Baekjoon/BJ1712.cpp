#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	if (C <= B) {
		cout << -1;
		return 0;
	}
	int i= ceil((double)A / (C - B));
	if (A % (C - B) == 0) i++;
	cout << i;
	system("pause");
	return 0;
}