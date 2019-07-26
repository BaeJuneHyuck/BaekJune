// 백준 1152, 단어의 갯수
#include <iostream>
#include <string>
using namespace std;

int main() {
	string in;
	int index = 0;
	int count = 0;

	getline(cin, in);
	bool first = false;
	bool last = false;
	while (index < in.length()) {
		if (in[index] == ' ') {
			if (last && !first) { 
				count++;
			}
			first = true;
		}
		else {
			first = false;
			last = true;
		}
		index++;
	}
	if (first)count--;
	cout << count+1;
	system("pause");
	return 0;
}