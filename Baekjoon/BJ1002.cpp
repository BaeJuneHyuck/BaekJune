#include <iostream>
using namespace std;
// 두원의 교점?
int main() {
	int T;
	cin >> T;
	while (T--) {
		int  x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (x1 == x2 && y1 == y2) {
			if(r1 != r2) cout << "0" << endl;
			else cout << "-1" << endl;
			continue;
		}
		int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		int rplus = (r1 + r2)* (r1 + r2);
		int rminus = (r2 - r1)* (r2 - r1);
		if (d == rplus || d == rminus)cout << "1" << endl;
		else if (rplus < d || d < rminus)cout << "0" << endl;
		else cout << "2" << endl;
	}
	cin >> T;
	return 0;
}