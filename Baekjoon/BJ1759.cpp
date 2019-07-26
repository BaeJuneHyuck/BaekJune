#include <iostream>
#include <vector>
using namespace std;
// 최소 한개의 모음, 최소 두개의 자음으로 이루어진 L길이의 가능한 암호
// 오름차순 정렬

bool charlist[26];
int aeiou = 0;
int other = 0;

void pick(int current, vector<char>& picked, int remain) {// 이전알파벳, 뽑힌것들, 남은갯수
	if (remain == 0) {// 암호완성, 조건확인후 출력
		if (aeiou == 0 ||  other <= 1) return;
		for (auto it = picked.begin(); it != picked.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
	else {// 길이 될때까지 사용가능한 알파벳을 추가
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