#pragma warning(disable:4996)
#include <cstdio>

int N, M;
int r, c, d;// d , 북동남서 , 즉 왼쪽으로 회전하려면 d-- 해줘야함
int dx[] = {0, 1, 0, -1};
int dy[] = { -1, 0, 1, 0 };
int map[51][51];
int count = 0;

void print() {
	printf("-------------\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (r == i && j == c) printf("* ");
			printf("%d ", map[i][j]);
		}printf("\n");
	}
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	bool reverse = false;
	while (1) {
		if (!reverse) {// 후진해서 들어온경우가 아닐때 청소한다
			map[r][c] = 2;
			count++;
		}

		reverse = false; 
		bool turned = false;
		int nd = d;
		for (int i = 0; i < 4; i++) {
			nd--;
			if (nd < 0) nd = 3;
			int nr = r + dy[nd];	
			int nc = c + dx[nd];
			if (nr<0 || nr >= N || nc < 0 || nc >= M)continue;
			if (map[nr][nc] == 0) {// 청소하지 않은 공간 존재시 회전하고 이동
				d = nd;
				r = nr;
				c = nc;
				turned = true;
				break;
			}
		}
		if (!turned) { // 4방향 모두 이동 불가
			// print();
			int nr = r - dy[d];
			int nc = c - dx[d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M || map[nr][nc] == 1) {// 후진도 할수없을경우 작동 종료
				break;
			} else {// 뒤쪽에 후진할수있음
				r = nr; c = nc;
				reverse = true;
			}
			//print();
		}

	}
	printf("%d", count);
	return 0;
}