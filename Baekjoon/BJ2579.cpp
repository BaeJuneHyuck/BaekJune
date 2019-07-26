// 백준 2579번 계단오르기
// 마지막 계단을 밟아야하므로 
// 역으로 마지막계단에서부터 최대Cost을 고르는 방법으로 
#include <iostream>

using namespace std;
int sCost[300];
int sCache[300];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int maxScore(int floor) {
	if (sCache[floor]) return sCache[floor];
	// floor - 1번째 계단을 밟은경우 
	int case1 = maxScore(floor - 3) + sCost[floor - 1] + sCost[floor];
	// floor - 1번째 계단을 밟지않은경우
	int case2 = maxScore(floor - 2) + sCost[floor];
	sCache[floor] = max(case1, case2);
	return sCache[floor];
}

int main() {
	int sCount;
	cin >> sCount;
	for (int i = 0; i < sCount; i++) {
		cin >> sCost[i];
	}
	sCache[0] = sCost[0];
	sCache[1] = sCost[0] + sCost[1];
	sCache[2] = max(sCost[0] + sCost[2], sCost[1] + sCost[2]);
	cout << maxScore(sCount-1);
	system("pause");
	return 0;
}