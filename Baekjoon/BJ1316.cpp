// 백준 1316번 그룹단어 체커
// aabbcc (o) abca (x)
#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int TB;
	cin >> TB;
	int count = 0;
	while (TB--) {
		char input[101];
		char prev = ' ';
		cin >> input;
		int length = strlen(input);
		bool charArr[27] = { false };
		bool isGroup = true;
		for (int i = 0; i < length; i++) {
			char current = input[i];
			if (i > 0) {
				if (current != prev) {
					if (charArr[current - 'a']) {
						isGroup = false;
						continue;
					}
					charArr[current - 'a'] = true;
				}
			}

			charArr[current - 'a'] = true;
			prev = input[i];
		}
		if (isGroup) count++;
	}
	cout << count;

	system("pause");
	return 0;
}
