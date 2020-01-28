#pragma warning(disable:4996)
#include <cstdio>
#include <stdlib.h>

int n, k, l;
char map[101][101];
int ct[101]; // ��� �ð�
char cd[101]; // ��� ���� // L ����90�� , D ������ 90��
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 }; // D�� ++ L�̸� --
int time = 0;


struct body {
	body* next;
	body* back;
	int x, y;
};

class snake{
	body* head;
	body* tail;
public:
	int direction;
	snake(int x, int y) {
		head = new body;
		tail = head;
		head->x = x;
		head->y = y;
		map[x][y] = 1;	
		direction = 2;
	}

	int move() {// �Ӹ��� ��ĭ �ø����� ����� ������ ���� ����
		int nextX = head->x + dx[direction];
		int nextY = head->y + dy[direction];
		// printf("cd = %d next : %d %d\n", direction, nextX, nextY);
		if (nextX > n || nextX <= 0 || nextY > n || nextY <= 0 || map[nextX][nextY] == 1) {
			return -1;// �̵��Ұ�(�浹)
		}
		body *temp = new body;// ��带 �ø���
		temp->back = head;
		head->next = temp;
		head = temp;
		head->x = nextX;
		head->y = nextY;
		
		if (map[nextX][nextY] != 2) {// ��� �ƴϸ� ���� ����(������ next�� �� ����)
			map[tail->x][tail->y] = 0;
			body* temp = tail->next;
			delete(tail);
			tail = temp;
		}
		map[nextX][nextY] = 1;
		return 0;
	}
};


void print() {
	printf("\n-----time =  %d\n", time);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d", map[j][i]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int x, y;				// ��, �� ������ �Է¹���
		scanf("%d %d", &y, &x); // ���� y,x������ �ޱ�
		map[x][y] = 2;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &ct[i], &cd[i]);
	}
	snake s(1,1);
	
	int nextTurn = 0; //�̵� �迭 �ε���
	int nextTime = ct[nextTurn]; // ���� ȸ�� �ð�

	// print();
	while (1) {
		time++;

		if (s.move() == -1)break;
		if (nextTime == time) {
			if (cd[nextTurn] == 'D') s.direction = (s.direction + 1) % 4;
			else s.direction = s.direction - 1;
			if (s.direction < 0) s.direction = 3;
			// printf("turn : %d \n", s.direction);
			nextTurn++;
			nextTime = ct[nextTurn];
		}
		// print();
	}
	printf("%d", time);
	return 0;
}