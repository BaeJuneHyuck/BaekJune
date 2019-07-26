#include <iostream>
#include <string>
using namespace std;

int main() {
	string input;
	cin >> input;

	input.insert(input.begin(), '+');
	int sum = 0;
	int start, end;
	bool minus = false;
	for (start = 0; start < input.length(); start++) {
		if (input[start] == '-') {  
			minus = true;
			for (end = start + 1; end < input.length(); end++) {
				if (input[end] == '+' || input[end] == '-')
					break;
			}
			int token = stoi(input.substr(start, end));
			sum = sum + token;
		}
		else if (input[start] == '+') {
			for (end = start + 1; end < input.length(); end++) {
				if (input[end] == '+' || input[end] == '-')
					break;
			}
			int token = stoi(input.substr(start, end));
			if (minus) sum = sum - token;
			else sum = sum + token;
		}
	}
	cout << sum;
	cin >> sum;
	return 0;
}