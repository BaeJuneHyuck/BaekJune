//��Ʈ��ŷ �Թ�����
#include <stdio.h>
#include <vector>
#pragma warning(disable:4996);
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
			//candilist.erase(candilist.begin() + i);
			pick(candilist, currentlist, remain - 1);
			currentlist.pop_back();							//!! ����� ����Ʈ
			//candilist.insert(candilist.begin() + i, temp);	//!! ��͵� ����Ʈ
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