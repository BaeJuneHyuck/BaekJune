//백준 2292번 벌집
// 1= 1
// 2 ~ 7 = 2
// 8 ~ 19  = 3
// 20 ~ 37 = 4
// 차가 6x-1인 차수열
// 입력:첫째 줄에 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.
#include <iostream>

using namespace std;

int main() {
	int N;
	int border = 1;
	int i = 1;
	cin >> N;
	while (N > border) {
		border = border + 6*i;
		cout << "i : " << i << ", border: " << border << endl;
		i++;
	}
	
	cout << i;
	system("pause");
	return 0;
}