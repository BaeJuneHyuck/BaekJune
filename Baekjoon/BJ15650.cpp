//백트랙킹 입문문제
#include <stdio.h>
#include <vector>
#pragma warning (disable:4996);
using namespace std;

int N, M;//1~8 사이, 1부터 N까지 숫자로 M길이의 수열을 모두 출력할것

void pick(int current, vector<int>& currentlist, int remain) {
	if (remain == 0) {
		for (auto it = currentlist.begin(); it != currentlist.end(); it++) {
			printf("%d ", *it);
		}printf("\n");
	}
	else {
		for (int i = current + 1; i <= N; i++) {
			currentlist.push_back(i);
			pick(i, currentlist, remain - 1);
			currentlist.pop_back();							//!! 요것이 포인트
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	vector<int>list;
	vector<int>candidate;
	for (int i = 1; i <= N; i++)candidate.push_back(i);
	pick(0, list, M);

	system("pause");
	return 0;
}