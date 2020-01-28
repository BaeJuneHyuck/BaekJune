#pragma warning(disable:4996)
#include <cstdio>
#include <string.h> //memcpy
int N, M, x, y, K;
int map[21][21];
int command[1001];
int currentFace[] = { 1, 3, 4, 2, 5, 6 }; // top, right ,left up, down, bottom
int dice[] = { 0,0,0,0,0,0 };// 1���� ���� 6������� �� 0���� ����
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };//�����ϳ�

void role(int i) {
	if (map[y][x] != 0) {
		dice[currentFace[5]] = map[y][x]; // �̵��� ĭ�� 0�� �ƴϸ� �ٴڸ鿡 ����, ĭ�� 0����
		map[y][x] = 0;
	}
	else {
		map[y][x] = dice[currentFace[5]]; // �̵��� ĭ�� 0 �̸� �ٴڸ��� ĭ���� ����
	}
	printf("%d\n", dice[currentFace[0]]);
}

int main() {
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &command[i]);// 1,2,3,4 �����ϳ�
	}
	for (int i = 0; i < K; i++) {
						// 0    1      2     3    4    5
		int nextFace[6];// top, right ,left, up, down, bottom
		int c = command[i];
		int nextx = x + dx[c-1]; int nexty = y + dy[c-1];
		if (nextx < 0 || nextx >= M || nexty < 0 || nexty >= N) continue;
		x = nextx; y = nexty;
		switch (c) {
		case 1: {			
			// ��: top -> right, left->top,  bottom -> left  , right->bottom  updown �״��
			nextFace[0] = currentFace[2]; nextFace[1] = currentFace[0];
			nextFace[2] = currentFace[5]; nextFace[3] = currentFace[3];
			nextFace[4] = currentFace[4]; nextFace[5] = currentFace[1];
			memcpy(currentFace, nextFace, sizeof(nextFace));
			role(i);
			break;
		}case 2: {
			// ��: top->left , right->top, bottom->right, left->bottom updown �״��
			nextFace[0] = currentFace[1]; nextFace[1] = currentFace[5];
			nextFace[2] = currentFace[0]; nextFace[3] = currentFace[3];
			nextFace[4] = currentFace[4]; nextFace[5] = currentFace[2];
			memcpy(currentFace, nextFace, sizeof(nextFace));
			role(i);
			break;
		}case 3: {
			// ��: top-> up,  up-> bottom, down-> top, bottom-> down, leftright �״��
			nextFace[0] = currentFace[4]; nextFace[1] = currentFace[1];
			nextFace[2] = currentFace[2]; nextFace[3] = currentFace[0];
			nextFace[4] = currentFace[5]; nextFace[5] = currentFace[3];
			memcpy(currentFace, nextFace, sizeof(nextFace));
			role(i);
			break;
		}case 4: {
			// ��: top-> down, up -> top, down->botom, bottom ->up , leftright�״�� 
			nextFace[0] = currentFace[3]; nextFace[1] = currentFace[1];
			nextFace[2] = currentFace[2]; nextFace[3] = currentFace[5];
			nextFace[4] = currentFace[0]; nextFace[5] = currentFace[4];
			memcpy(currentFace, nextFace, sizeof(nextFace));
			role(i);
			break;
		}
		}// end of switch
	}// end of loop

	return 0;
}