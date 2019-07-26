#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;

int M, N;

void bfs(int current, vector<int> & list, int remain) {
	if (remain == 0) {
		for (auto it = list.begin(); it != list.end(); it++) {
			printf("%d ", *it);
		}
		printf("\n");
	}
	else {
		for (int i = current; i <= M; i++) {
			list.push_back(i);
			bfs(i, list, remain - 1);
			list.pop_back();
		}

	}
}

int main() {
	scanf("%d %d", &M, &N);
	vector<int> list;
	bfs(1, list, N);
	return 0;
}