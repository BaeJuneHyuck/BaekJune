//백준 10250번, ACM호텔
#include <iostream>

using namespace std;

int getRoom(int H, int W, int N) {
	int h = N % H;
	if (!h) h = H;
	int w = N / H + 1;
	if (N % H == 0) w--;
	return h*100+w;
}

int main() {
	int TB;
	cin >> TB;
	while (TB--) {
		int H, W, N;
		cin >> H >> W >> N;
		cout << getRoom(H, W, N) <<endl;
	}
	system("pause");
	return 0;
}