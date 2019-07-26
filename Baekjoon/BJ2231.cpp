
// �ڿ��� N�� ��������  N + ���ڸ���
// �ڿ��� M�� �������� N�� �Ǵ°�� M�� N�� �����ڶ�� �Ѵ�
// �׷� �����ڴ� ��󺸴� �۾ƾ� �ǰٱ�
// N�� �Է¹޾����� �������� �����ڸ� ����ض� ������� 0


// ���̵��
/*
  N�� �Է¹����� N���� ���� �� ��δ� ������ ���ؼ� N�� �������� Ȯ������
  ���������� �����ϸ� ���� ���� �����¾ְ� �������� �����ڴϱ� �ٷ� ���߸� �ȴ�
  1���� �ٷ� ���ʿ���� 1�� �����ؔf�� ����� ���ü�������
  �������� �����Ѽ��� ������
  �� �ڸ����� �ִ� 9���� ������ 10�ڸ������ 90 + �ڱ��ڽ� �� �ִ�� ���´�
  �װź��� �����ſ� ���ؼ��� �õ��� �ʿ䰡����
*/

#include <iostream>
#include <math.h>

using namespace std;

int getdigits(int x) {
	for (int i = 0; i < 7; i++) {
		if ((int)(x / (pow(10, i))) == 0) {
			return i;
		}
	}
}

int getsum(int x) {
	int digits = getdigits(x);
	int sum = x + (x % 10);
	for (int i = 1; i < digits; i++) {
		int d = (int)(x / pow(10, i)) % 10;
		sum = sum + d;
	}
	return sum;
}

int main() {
	int N, digits=0;
	cin >> N;

	// �ڸ��� ���ؼ� �ĺ��� ������
	digits = getdigits(N);
	// �ڸ��� ���޴� N�� ������ �ĺ��� �ɼ��մ� �ֵ���?
	// ex ���ڸ����� 333
	// ���������� 333�� ���÷��� ��� ���ڸ������� ����
	// M + 3(9) // �ִ� 9�ΰ� 3�ڸ� �߰��Ǽ� 333�� ���÷���
	// M�� �ּ� 333-9x3

	int sum;
	for (int i = N - digits * 9; i < N; i++) {
		//cout << "�ĺ�:" << i <<" / ";
		for (int j = 0; j < digits; j++) {
			sum = getsum(i);
		}
		//cout << " / sum = " << sum<<endl;
		if (sum == N) {
			cout << i << endl;

			system("pause");
			return 0;
		}
	}
	cout << 0 << endl;
	system("pause");
	return 0;
}