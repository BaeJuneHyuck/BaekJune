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

	// �׸��� �Ұ���
	// ���� ��Ȳ�� ����غ���
	// DP[i][j]�� 1������ i���, 2������ j ����� ó�������� �Ÿ� ��(�ּ�)
	// i != j �̸�, DP[i][j] ������ �ذ��� ����� max(i,j) - 1 ��
	// �׷���...

	// GG �̰� ���� Ǯ���մ� ������ �ƴϴ�
	return 0;
}