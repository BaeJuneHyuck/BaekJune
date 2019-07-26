#include <iostream>
#include <string>

#define MAX 100000
using namespace std;

int main(){
	int T;
	cin >> T;
	int stack[MAX];
	int num;
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
		}else if (cmd.compare("pop") == 0) {
			if (!top) cout << -1 << endl;
			else {
				cout << stack[top - 1] << endl;
				top--;
			}
		}else if (cmd.compare("size") == 0) {
			cout << top << endl;
		}else if (cmd.compare("empty") == 0) {
			if (!top) cout << 1 << endl;
			else cout << 0 << endl;
		}else if (cmd.compare("top") == 0) {
			if (!top) cout << -1 << endl;
			else cout << stack[top-1] << endl;
		}
	}
	return 0;
}