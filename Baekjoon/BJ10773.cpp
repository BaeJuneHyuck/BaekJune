#include <iostream>
#include <stack>

using namespace std;

int main() {
	int T;
	cin >> T;
	stack<int> record;

	while (T--) {
		int temp;
		cin >> temp;
		if (!temp) 	record.pop();
		else record.push(temp);
	}

	int sum = 0;
	while (record.size() != 0) {
		sum+= record.top();
		record.pop();
	}

	cout << sum;

	system("pause");
	return 0;
}