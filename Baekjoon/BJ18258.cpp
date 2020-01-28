#include <iostream>
#include <string>

// 명령수가 늘어남 전역변수로 옮김

int stack[2000000]; 
using namespace std;
int T, num;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
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
			if (top - front == 0) cout << -1 << "\n";
			else {
				cout << stack[front] << "\n";
				front++;
			}
		}
		else if (cmd.compare("size") == 0) {
			cout << top - front << "\n";
		}
		else if (cmd.compare("empty") == 0) {
			if (top - front == 0) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (cmd.compare("front") == 0) {
			if (top - front == 0) cout << -1 << "\n";
			else cout << stack[front] << "\n";
		}
		else if (cmd.compare("back") == 0) {
			if (top - front == 0) cout << -1 << "\n";
			else cout << stack[top - 1] << "\n";
		}
	}
	return 0;
}