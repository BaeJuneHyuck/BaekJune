// ���� 1924�� ,2007��
// 1��1���� ������. 1, 3, 5, 7, 8, 10, 12���� 31�ϱ���, 4, 6, 9, 11���� 30�ϱ���, 2���� 28�ϱ��� �ִ�.
// x�� y���� ���������ΰ� SUN, MON, TUE, WED, THU, FRI, SAT�� �ϳ��� ����Ѵ�.

#include <iostream>
using namespace std;

int main() {
	int m, d;
	cin >> m >> d;
	int total = 0;
	while (m != 1) {
		if (m == 3) { total += 28;}
		else if (m == 5 || m == 7 || m == 10 || m == 12) total += 30;
		else total += 31;
		m--;
	}
	total += d;
	switch (total % 7) {
	case 0:cout << "SUN"; break;
	case 1:cout << "MON"; break;
	case 2:cout << "TUE"; break;
	case 3:cout << "WED"; break;
	case 4:cout << "THU"; break;
	case 5:cout << "FRI"; break;
	case 6:cout << "SAT"; break;
	}
	system("pause");
	return 0;
}

// 	koree9621���� �ڵ�
#include <stdio.h>

int main() {
	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	char date[][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

	int x = 0, y = 0;
	scanf("%d %d", &x, &y);

	int sum = 0;
	for (int i = 0; i < x - 1; i++) sum += day[i];
	sum += y - 1;

	printf("%s\n", date[sum % 7]);
}

