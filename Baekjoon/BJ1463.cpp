/* 백준 1463번 1로 만들기
 /3, /2, -1 을 사용하여 1로 만드는 횟수가 가장적은것 출력 
  52644kb , 44ms
*/
#include <iostream>
using namespace std;
int cache[1000000];

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int toZero(int num) {
	if (cache[num]) return cache[num];
	if (num == 1) return 0;
	int case1 = toZero(num - 1) + 1;
	int case2 = 9999999;
	if (num % 2 == 0) case2 = toZero(num / 2) + 1;
	int case3 = 9999999;
	if (num % 3 == 0) case3 = toZero(num / 3) + 1;
	cache[num] = min(case1, min(case2, case3));
	return cache[num];
}

int main() {
	int number;
	cin >> number;
	cache[1] = 0;
	cache[2] = 1;
	cache[3] = 1;
	cout << toZero(number);
	system("pause");
	return 0;
}

// 백준 codemoon님의 코드
// 5888kb, 4ms
/*

#include <iostream>
using namespace std;
int d[1000001];
int main() {
	int n;
	cin >> n;
	d[1] = 0;
	for (int i=2; i<=n; i++) {
		d[i] = d[i-1] + 1;
		if (i%2 == 0 && d[i] > d[i/2] + 1) {
			d[i] = d[i/2] + 1;
		}
		if (i%3 == 0 && d[i] > d[i/3] + 1) {
			d[i] = d[i/3] + 1;
		}
	}
	cout << d[n] << '\n';
	return 0;
}

*/