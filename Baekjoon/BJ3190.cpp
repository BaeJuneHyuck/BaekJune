#pragma warning(disable:4996)
#include <cstdio>
#include <stdlib.h>

int n, k, l;
char map[101][101];
int ct[101]; // 명령 시간
char cd[101]; // 명령 종류 // L 왼쪽90도 , D 오른쪽 90도
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 }; // D면 ++ L이면 --
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

	int move() {// 머리를 한칸 늘린다음 사과가 없으면 꼬리 삭제
		int nextX = head->x + dx[direction];
		int nextY = head->y + dy[direction];
		// printf("cd = %d next : %d %d\n", direction, nextX, nextY);
		if (nextX > n || nextX <= 0 || nextY > n || nextY <= 0 || map[nextX][nextY] == 1) {
			return -1;// 이동불가(충돌)
		}
		body *temp = new body;// 헤드를 늘리자
		temp->back = head;
		head->next = temp;
		head = temp;
		head->x = nextX;
		head->y = nextY;
		
		if (map[nextX][nextY] != 2) {// 사과 아니며 꼬리 삭제(꼬리의 next가 새 꼬리)
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
		int x, y;				// 행, 열 순으로 입력받음
		scanf("%d %d", &y, &x); // 따라서 y,x순으로 받기
		map[x][y] = 2;
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &ct[i], &cd[i]);
	}
	snake s(1,1);
	
	int nextTurn = 0; //이동 배열 인덱스
	int nextTime = ct[nextTurn]; // 다음 회전 시간

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