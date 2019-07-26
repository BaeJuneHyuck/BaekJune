#include <iostream>
#include <string>

#define MAX 100000
using namespace std;

int main() {
	int T;
	cin >> T;
	int stack[MAX];
	int num;
	int front = 0;
	int top = 0;
	while (T--) {
		string cmd;
		cin >> cmd;
		cin.ignore();
		cin.clear();
		if (cmd.compare("push") == 0) {
			cin >> num;
			stack[top] = num;
			top++;
		}
		else if (cmd.compare("pop") == 0) {
			if (top - front == 0) cout << -1 << endl;
			else {
				cout << stack[front] << endl;
				front++;
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << top - front << endl;
		}
		else if (cmd.compare("empty") == 0) {
			if (top - front == 0) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (cmd.compare("front") == 0) {
			if (top - front == 0) cout << -1 << endl;
			else cout << stack[front] << endl;
		}
		else if (cmd.compare("back") == 0) {
			if (top - front == 0) cout << -1 << endl;
			else cout << stack[top-1] << endl;
		}
	}
	return 0;
}