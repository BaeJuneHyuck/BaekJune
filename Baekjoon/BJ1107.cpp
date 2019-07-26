#include <iostream>
#include <math.h>
using namespace std;

bool broken[10];

int digits(int n) {
	if (!n) return 1;
	int digit = 0;
	while (n) {
		n /= 10;
		digit++;
	}
	return digit;
}

int checkPossible(int n) { // ������ ���ڸ� -1, �Ұ����� ���ڸ� �Ұ����� �ڸ����� ����
	int digit = 0;
	if (!n) {
		if (broken[0])return digit;
	}
	while (n) {
		int d = n % 10;
		if (broken[d])return digit;
		n /= 10;
		digit++;
	}
	return -1;
}

int main() {
	int target,bbroken;
	cin >> target >> bbroken;
	for(int i = 0 ; i< bbroken;i++){
		int temp;
		cin >> temp;
		broken[temp] = true;
	}

	if (target == 100) {
		cout << 0;
	}else if (bbroken == 10) {
		cout << abs(target - 100);
	}else {
		int digit = digits(target);//�ڸ���

		// Ÿ�ٿ� ���� ����� ä�� ���ѵ� �̵����� �����ϱ�
		int min = abs(target - 100); // ��ư���� �̵������� ��� �����Ұ�� Ƚ���� �ּҷ� �����ϰ�
	
		//int maxnum = digit+1 > 6 ?  6 : digit+1; // 1���� (����� �ʴ����� ����� �ִ�(999)����)
		for (int temp = 0; temp <= 1000000; temp++){ 
			int possible = checkPossible(temp);
			if (possible == -1) { // temp�� ��ư�Է��� ������ ����, ���� ��ưȽ��+���� �̵� = distance
				int distance = abs(temp - target);
				distance = distance + digits(temp);
				if (min > distance) {
					min = distance;
				}
			}
			/*
			else {// �Ұ����Ѱ��,  �Ұ����� �ڸ��������ؼ� 1������Ű�� 
				// 2153���� 1�� �Ұ����ϸ� ������ 2253(�� 10^2���ϴϱ�)�� �õ��ؾ���
				temp = temp + pow(10, possible);
			}
			*/
		}
		cout << min << endl;
	}

	system("pause");
	return 0;
}