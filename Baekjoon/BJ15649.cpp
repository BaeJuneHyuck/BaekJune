//��Ʈ��ŷ �Թ�����
#include <stdio.h>
#include <vector>
using namespace std;

int N, M;//1~8 ����, 1���� N���� ���ڷ� M������ ������ ��� ����Ұ�

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
			currentlist.pop_back();							//!! ����� ����Ʈ
			candilist.insert(candilist.begin() + i,temp);	//!! ��͵� ����Ʈ
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


/* ����� Ǯ��
����	dy2000

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


