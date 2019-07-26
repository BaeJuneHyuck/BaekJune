#include<iostream>
#include <stack>
#include <string>
#include <stdio.h>
using namespace std;

int main() {
	stack<int> s;
	string output;
	int T;
	cin >> T;
	int current_num = 0;
	int prev_num = T+1;
	bool botom_hit = false;
	int index = 0;
	for(int i = 0; i<T; i++) {
		int temp;
		cin >> temp;
		if (botom_hit) {
			if (temp > prev_num) {
				printf("NO");
				return 0;
			}
		}
		if (temp == T) botom_hit = true;
		if (temp > current_num) {
			do {
				s.push(current_num+1);
				output.append("+\n");
				current_num++;
			} while (temp > current_num);
			s.pop();
			output.append("-\n");
		}
		else if (temp < current_num) {
			if (s.top() == temp) {
				s.pop();
				output.append("-\n");
			}
			else {
				printf("NO");
				return 0;
			}
		}
		prev_num = temp;
	}
	cout << output << endl;
	return 0;
}