//��Ʈ��ŷ �Թ�����
#include <stdio.h>
#include <vector>
#pragma warning (disable:4996);
using namespace std;

int N, M;//1~8 ����, 1���� N���� ���ڷ� M������ ������ ��� ����Ұ�

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
			currentlist.pop_back();							//!! ����� ����Ʈ
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