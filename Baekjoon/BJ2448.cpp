/* ���� 2448��, ����� 
 �׸����� �ϴ� �ﰢ���� ũ��� ��ġ�� ���� �Լ��� ������ ��������� ������ �ذ��غ��ϴ�

  idea : 
   ��¶�� ū �ﰢ�� 3���� �ɰ���... �׾ȿ� �ﰢ��3��...�׾ȿ� 3��..
*/
#include <iostream>
using namespace std;

char arr[3072][6144];

void print(int size,int x,int y) {
	if (size == 3) {
		arr[y][x] = '*';
		arr[y+1][x+1] = '*';
		arr[y+1][x-1] = '*';
		arr[y + 2][x-2] = '*';
		arr[y + 2][x-1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x+1] = '*';
		arr[y + 2][x+2] = '*';
		return;
	}
	print(size / 2, x, y);
	print(size / 2, x - (size/2), y + (size/2));
	print(size / 2, x + (size/2), y + (size/2));
}

int main() {	
	int line;
	cin >> line;
	// array init
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < line * 2; j++) {
			arr[i][j] = ' ';
		}
	}

	print(line,line-1,0);

	for (int i = 0; i < line; i++) {
		for (int j = 0; j < line * 2 - 1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}