//���� 2292�� ����
// 1= 1
// 2 ~ 7 = 2
// 8 ~ 19  = 3
// 20 ~ 37 = 4
// ���� 6x-1�� ������
// �Է�:ù° �ٿ� N(1 �� N �� 1,000,000,000)�� �־�����.
#include <iostream>

using namespace std;

int main() {
	int N;
	int border = 1;
	int i = 1;
	cin >> N;
	while (N > border) {
		border = border + 6*i;
		cout << "i : " << i << ", border: " << border << endl;
		i++;
	}
	
	cout << i;
	system("pause");
	return 0;
}