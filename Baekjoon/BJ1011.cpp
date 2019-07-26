// 백준 1011, fly me to the alpha centauri
// 세상에 long 붙여주니 시간초과 안되네....
// 이게무슨
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		long int x, y;
		cin >> x >> y;
		long int dist = y - x;
		long int jump = 1; // jump 총 횟수
		long int border = 1;
		while (dist > border*border) {
			cout << "dist > border*border" << border * border << endl;
			border++;
		}
		if (dist > border*(border-1)) {
			jump = border*2 - 1;
		}
		else jump = border*2 - 2;
		cout << jump << endl;
	}
	system("pause");
	return 0;
}