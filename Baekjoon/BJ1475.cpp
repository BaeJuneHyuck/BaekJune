//백준 1475번 방 번호
#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int roomNo;
	int minset = 0;
	int arr[10] = { 0 };
	cin >> roomNo;
	if (!roomNo) { cout << "1" << endl; return 0; }
	while (roomNo) {
		int digit = roomNo % 10;
		arr[digit]++;
		roomNo /= 10;
	}
	minset = (arr[6] + arr[9]) / 2;
	if ((arr[6] + arr[9]) % 2)minset++;
	for (int digit = 0; digit < 9; digit++) {
		if (digit != 6 && minset < arr[digit]) minset = arr[digit];
	}
	cout << minset;
	system("pause");
	return 0;
}