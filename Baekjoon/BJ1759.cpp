#include <iostream>
#include <vector>
using namespace std;
// �ּ� �Ѱ��� ����, �ּ� �ΰ��� �������� �̷���� L������ ������ ��ȣ
// �������� ����

bool charlist[26];
int aeiou = 0;
int other = 0;

void pick(int current, vector<char>& picked, int remain) {// �������ĺ�, �����͵�, ��������
	if (remain == 0) {// ��ȣ�ϼ�, ����Ȯ���� ���
		if (aeiou == 0 ||  other <= 1) return;
		for (auto it = picked.begin(); it != picked.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
	else {// ���� �ɶ����� ��밡���� ���ĺ��� �߰�
		for (int i = current; i < 26; i++) {
			if (charlist[i]) {
				picked.push_back('a' + i);
				if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) aeiou++;
				else other++;
				pick(i + 1, picked, remain - 1);
				if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) aeiou--;
				else other--;
				picked.pop_back();
			}
		}
	}
	return;
}

int main() {
	int L, C;
	cin >> L >> C;
	while (C--) {
		char c;
		cin >> c;
		charlist[c - 'a'] = true;
	}
	vector<char>list;
	pick(0 ,list ,L);

	system("pause");
	return 0;
}