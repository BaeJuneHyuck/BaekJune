#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

	while (1) {
		stack<char> pStack1;
		stack<char> pStack2;
		stack<char> openstack;
		string PS;
		getline(cin, PS);
		if (PS.compare(".") == 0)break;
		bool result = true;
		for (int i = 0; i < PS.length(); i++) {
			if (PS[i] == '(') {
				pStack1.push('(');
				openstack.push('(');
			}
			else if (PS[i] == ')') {
				if (pStack1.empty()) {
					result = false;
					break;
				}
				if (openstack.top() == '[') {
					result = false;
					break;
				}
				pStack1.pop();
				openstack.pop();
			}
			if (PS[i] == '[') {
				pStack2.push('[');
				openstack.push('[');
			}
			else if (PS[i] == ']') {
				if (pStack2.empty()) {
					result = false;
					break;
				}
				if (openstack.top() == '(') {
					result = false;
					break;
				}

				pStack2.pop();
				openstack.pop();
			}
		}
		if (result && pStack1.size() == 0 && pStack2.size() == 0) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}