/* 백준 1005번 ACM craft
 동적 계획법을 이용해 특정 건물을 짓기 위해 걸리는 최단시간을 계산하는 문제

 <입력>
 0:tb
   for tb1 {
	1:건물 갯수 N, 건설규칙 K
	2:건설 시간D (1번 2번 3번 4번...)
	3:건설 순서O (X Y) (K개) ,x를 지어야 y가 가능
	4:지어야하는 건물번호
   }
   for tb2 {
   }....

 <출력>
  각 tb에대해 최단시간

 */

#include<iostream>
#include <cstring>
using namespace std;
int D[1001];			// 건물당 건설시간
int O[1001][1001];		// 선행건물
int cache[1001]; // N번째 건물을 건설하는데 걸리는 가장 큰 코스트(DP)
int N;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int getMaxTime(int target) {
	if (cache[target] != -1) return cache[target];
	int maxTime = 0;
	// target건물의 선행조건을 모두 검색
	for (int i = 1; i < N+1;i++) {
		if (O[i][target]) {// 선행조건이 존재하면
			maxTime = max(maxTime,getMaxTime(i)); // 지금까지 최대시간보다 더 크면 새로 max기억 
		}
	}
	return cache[target]= D[target]+maxTime; // 선행이 없엇으면 max=0이므로 자기자신의 시간만 리턴될것
}

/*
int getMaxTime(int target) {
	if (cache[target] != -1) return cache[target];
	int maxTime = 0;
	for (int i = 1; i < N+1;i++) {
		if (O[i][target]) {
			int current_time = getMaxTime(i);
			if (current_time > maxTime) {
				cache[i] = maxTime = current_time;
			}
		}
	}2
	return D[target]+maxTime;
}
*/

int main() {
	int TB, K,x,y;
	cin >> TB;
	while (TB--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> K;
		for (int i = 1; i < N+1; i++) {
			cin >> D[i];
		}

		memset(O, 0, sizeof(O));
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			O[x][y] = 1;
		}
		int target;
		cin >>target;
		cout << getMaxTime(target) << endl;
	}
	system("pause");
	return 0;
}

