//백트랙킹 입문문제
#include <stdio.h>
#include <vector>
using namespace std;

int N, M;//1~8 사이, 1부터 N까지 숫자로 M길이의 수열을 모두 출력할것

void pick(vector<int>& candilist, vector<int>& currentlist, int remain) {
	if (remain == 0) {
		for (auto it = currentlist.begin(); it != currentlist.end(); it++) {
			printf("%d ", *it);
		}printf("\n");
	}
	else {
		for (int i = 0; i < candilist.size(); i++) {
			int temp = candilist.at(i);
			currentlist.push_back(temp);
			candilist.erase(candilist.begin() + i);
			pick(candilist, currentlist, remain - 1);
			currentlist.pop_back();							//!! 요것이 포인트
			candilist.insert(candilist.begin() + i,temp);	//!! 요것도 포인트
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	vector<int>list;
	vector<int>candidate;
	for (int i = 1; i <= N; i++)candidate.push_back(i);
	pick(candidate, list, M);

	system("pause");
	return 0;
}


/* 기똥찬 풀이
백준	dy2000

#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m, ans[10], ck[10];
void dfs(int cur) {
	if (m <= cur) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		puts("");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!ck[i]) {
			ck[i] = true;
			ans[cur] = i;
			dfs(cur + 1);
			ck[i] = false;
		}
	}
}
int main(void){
	scanf("%d %d", &n, &m);
	dfs(0);
}

*/


