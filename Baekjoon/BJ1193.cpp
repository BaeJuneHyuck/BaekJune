//백준 1193번 분수찾기
#include <iostream>
using namespace std;

int main() {
	int x = 1;
	int y = 1;
	int move;
	cin >> move;

	bool prev_was_straight = false;
	bool down = false;
	for(int i= 1; i<=move-1;i++){
		if (x == 1) {
			if (!prev_was_straight) {
				y++;
				prev_was_straight = true;
			}
			else {
				x++;
				y--;
				down = true;
				prev_was_straight = false;
			}
		}
		else if (y == 1) {
			if (!prev_was_straight) {
				x++;
				prev_was_straight = true;
			}
			else {
				x--;
				y++;
				down = false;
				prev_was_straight = false;
			}
		}
		else {
			if (down) {
				x++;
				y--;
			}
			else {
				x--;
				y++;
			}
		}
	}
	cout << x << "/" << y << endl;

	system("pause");
	return 0;
}