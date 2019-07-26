// 백준 5622번 다이얼
// ABC 2, DEF3... PQRS 7 TuV8 WXYZ 9
#include<iostream>
#include<string.h>
using namespace std;

int main() {
	char input[16];
	cin >> input;
	int sum = 0;
	for (int i = 0; i < strlen(input); i++) {
		char a = input[i];
		if (a <= 'C') sum += 3;
		else if (a <= 'F')sum += 4;
		else if (a <= 'I') sum += 5;
		else if (a <= 'L') sum += 6;
		else if (a <= 'O') sum += 7;
		else if (a <= 'S') sum += 8;
		else if (a <= 'V') sum += 9;
		else sum += 10;
	}

	cout << sum;
	system("pause");
	return 0;
}