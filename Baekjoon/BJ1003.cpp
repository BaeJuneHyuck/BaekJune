// 백준 1003번 피보나치
#include <iostream>

using namespace std;

int cache0[41] = { 0 };
int cache1[41] = { 0 };
int get0(int a) {
	if (a == 0) return 1;
	if (a == 1) return 0;
	if (cache0[a]) return cache0[a];
	cache0[a] = get0(a - 1) + get0(a - 2);
	return cache0[a];
}

int get1(int a) {
	if (a == 1) return 1;
	if (a == 0) return 0;
	if (cache1[a]) return cache1[a];
	cache1[a] = get1(a - 1) + get1(a - 2);
	return cache1[a];
}

int main() {
	int TC;
	cache0[0] = 1;
	cache0[1] = 0;
	cache1[0] = 0;
	cache1[1] = 1;
	cin >> TC;
	while (TC--) {
		int a;
		cin>> a;
		cout << get0(a) <<" "<< get1(a) << endl;
	}
	system("pause");
	return 0;
}