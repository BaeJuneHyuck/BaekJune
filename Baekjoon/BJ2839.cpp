/*
// ���� 2839�� �������
// 3,5ų�α׷� ���������� ����������� -> ����� ��������
// ���ϸ� ->-1 ���
*/
#include <iostream>
using namespace std;

int getSugar(int suga) {
	int minCup = -1;
	if (suga % 5 == 0) {
		return minCup = suga / 5;
	}else if ((suga % 3) == 0) {
		minCup = suga / 3;
	}
	int sugar5 = 0;
	while (suga > 0) {
		if (suga % 3 == 0) {
			minCup = sugar5 + suga/3;
			cout << " = '5' * " << sugar5 << " + '3' * " << suga/ 3 << endl;
		}
		suga -= 5;
		sugar5++;
	}
	return minCup;
}

int main() {
	int sugar;
	cin >> sugar;
	cout << getSugar(sugar) << endl;
	system("pause");
	return 0;
}