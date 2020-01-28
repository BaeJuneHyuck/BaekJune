#include <iostream>
#include <string>
using namespace std;

int N;
int fin = 0;
string target;
string word[101];

void solve(string remain) {
	if (fin) return;
	int result = 0;
	int rlen = remain.length();
	//cout << "남은문장 : " << remain << endl;
	for (int i = 0; i < N; i++) {
		int len = word[i].length();
		//cout << "비교단어: "<<  word[i] << endl;
		//cout << "잘린문장: "<<remain.substr(0, len) << endl;
		if (len > rlen) continue;
		if (word[i].compare(remain.substr(0, len)) == 0) {
			if (rlen == len) {
				result = 1; fin = 1;
			}
			else solve(remain.substr(len , rlen-len));
		}
	}
}

int main() {
	
	cin >> target;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}
	solve(target);
	cout << fin;
	return 0;
}