#pragma warning(disable:4996)
#include <cstdio>
#include <tuple>
#include <math.h>
using namespace std;
int N,W,x,y;
struct point {
	int  x, y;
};
int distance(point p1, point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
point patrol[2];
point problem[1001];
int DP[1001];

int main() {
	scanf("%d", &N); // 5~1000
	scanf("%d", &W); // 1~1000
	
	patrol[0].x = 1;
	patrol[0].y = 1;
	patrol[1].x = N;
	patrol[1].y = N;

	for (int i = 0; i < W; i++) {
		scanf("%d %d", &x, &y);
		problem[i].x = x;
		problem[i].y = y;
	}

	// 그리디 불가능
	// 현재 상황을 기억해보자
	// DP[i][j]는 1번차가 i사건, 2번차가 j 사건을 처리햇을때 거리 합(최소)
	// i != j 이며, DP[i][j] 이전에 해결한 사건은 max(i,j) - 1 임
	// 그러면...

	// GG 이건 내가 풀수잇는 수준이 아니다
	return 0;
}