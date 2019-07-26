// 백준 1065번		한수
#include <iostream>

using namespace std;

bool isHansoo(int a) {
	if (a < 100) return true;
	int dig0 = a / 100;
	int dig1 = (a / 10) % 10;
	int dig2 = a % 10;
	if (dig0 - dig1 == dig1 - dig2) return true;
	return false;
}

int main() {
	int a = 0;
	int input;
	cin >> input;
	for (int i = 1; i <= input; i++)
	{
		if (isHansoo(i)) a++;	
	}

	cout << a <<endl;
	system("pause");
	return 0;
}