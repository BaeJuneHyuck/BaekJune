// ���� 1011, fly me to the alpha centauri
// ���� long �ٿ��ִ� �ð��ʰ� �ȵǳ�....
// �̰Թ���
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
		long int jump = 1; // jump �� Ƚ��
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