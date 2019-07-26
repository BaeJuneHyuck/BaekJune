#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		stack<char> pStack;
		string PS;
		cin >> PS;
		bool result = true;
		for (int i = 0; i < PS.length(); i++) {
			if (PS[i] == '(') {
				pStack.push('(');
			}
			else {
				if (pStack.empty()) {
					result = false;
					break;
				}
				pStack.pop();
			}
		}
		if (result && pStack.size() == 0) cout << "YES\n";
		else cout << "NO\n";
	}

	system("pause");
	return 0;
}