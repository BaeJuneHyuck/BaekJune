#include <stdio.h>
#pragma warning(disable:4996);
using namespace std;

int arr[1000][1000];
int N;
int target;
int targetR, targetC;
int next = 1;
int currentInterval = 1;
int dr[4] = { -1 , 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

void fill(int r, int c, int direction, int jump) {
	arr[r][c] = next;
	if (r == 0 && c == 0)return;
	if (next == target) {
		targetR = r;
		targetC = c;
	}
	next++;

	int nextr = r + dr[direction];
	int nextc = c + dc[direction];

	jump--;
	if (jump == 0) {
		direction = (direction + 1) % 4;
		if (direction == 2 || direction == 0) {
			currentInterval++;
		}
		jump = currentInterval;
	}
	fill(nextr, nextc, direction, jump);
}

int main() {
	scanf("%d %d", &N, &target);
	int mid = N / 2;
	fill(mid, mid, 0, 1);

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			printf("%d ", arr[row][col]);
		}printf("\n");
	}
	
	printf("%d %d", targetR + 1, targetC + 1);
	scanf("%d %d", &N, &target);
	return 0;
}