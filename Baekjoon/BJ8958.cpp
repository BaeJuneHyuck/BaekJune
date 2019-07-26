// 백준 8958번 OX퀴즈
#include <iostream>
using namespace std;

int main() {
	int TB;
	cin >> TB;
	while (TB--) {
		char arr[81] = {};
		int score = 0;
		int c_score = 0;
		cin >> arr;

		int index = 0; 
		while (arr[index]) {
			if (arr[index] == 'O') {
				c_score++;
				score += c_score;
			}
			else if (arr[index] == 'X') c_score = 0;
			index++;
		}
		cout << score<<endl;
	}
	system("pause");
	return 0;
}