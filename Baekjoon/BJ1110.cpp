// 백준 1110번. 더하기 사이클
#include <iostream>
using namespace std;

int main() {
	int number;
	int cycle = 0;
	cin >> number;
	int temp = number;
	while (1) {
		cycle++;
		int left, right;
		left = number / 10;
		right = number % 10;
		int newnumber = right * 10 + (right + left) % 10;
		//cout << number << " ->" << newnumber<<endl;
		if (newnumber == temp) break;
		else number = newnumber;
	}
	cout << cycle;

	cin >> number;
	return 0;
}