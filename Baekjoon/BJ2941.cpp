//백준 2941번 크로아티아 알파벳
#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char input[101] = {};
	cin >> input;
	int count = 0;
	for (int index = 0; index < strlen(input); index++) {
		char c = input[index];
		if (c == 'c') {
			if (input[index + 1] == '=' || input[index + 1] == '-') index++;
		}else if (c == 'd') {
			if (input[index + 1] == 'z' && input[index + 2] == '=') index +=2;
			if (input[index + 1] == '-') index++;
		}
		else if (c == 'l') {
			if (input[index + 1] == 'j') index++;
		}
		else if (c == 'n') {
			if (input[index + 1] == 'j') index++;
		}else if (c == 's') {
			if (input[index + 1] == '=' ) index++;
		}else if (c == 'z') {
			if (input[index + 1] == '=') index++;
		}
		count++;
	}

	cout << count;
	system("pause");
	return 0;
}