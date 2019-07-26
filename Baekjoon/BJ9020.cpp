//������ ����

#include <iostream>
#include <vector>

using namespace std;
bool eratos[10001];
int prime[3000];

int main() {
	// make prime list under 10,000
	for (int i = 0; i <= 10000; i++) {
		eratos[i] = true;
	}
	eratos[0] = false;
	eratos[1] = false;
	for (int i = 2; i*i <= 10000; i++) {
		if (eratos[i]) {
			for (int j = i * 2; j <= 10000; j += i) {
				eratos[j] = false;
			}
		}
	}
	int total = 0;
	for (int i = 2; i <= 10000; i++) {
		if (eratos[i]) {
			prime[total] = i;
			total++;
		}
	}// 1229��

	int  T;
	scanf("%d", &T);
	while (T--) {
		int target;
		scanf("%d", &target);
		// find best
		int left_index = 0;
		int right_index = 1228;
		int answ_left = 0, answ_right = 987654321;
		int left, right;
		int right_max = 0;
		for (int i = 0; i < total; i++) {
			if (prime[i] < target) right_max = i;
			else break;
		}
		while (1) {
			left = prime[left_index];
			right = prime[right_index];
			//cout << left << "/" << right << "[" << left_index << "/" << right_index << "]\n";
			if (left_index > right_max) break;
			if (right_index < left_index) {
				left_index++;
				right_index = right_max;
			}
			else {// ���� ����, ������ �̵����� ��ã��, ������ ���°� ����ϱ�
				if (left + right == target) {
					if (right - left < answ_right - answ_left) {//���ο� �ּҽ�,�߰��� ����ϰ� �������
						answ_right = right;
						answ_left = left;
						right_index--;
					}
				}else if (left + right > target) {// �� �ٿ����Ѵ�
					right_index--;
				}else {// �̹� ���� ���ü������� -> ����������Ű�� �ٽ�
					left_index++;
					right_index = right_max;
				}
			}
		}
		printf("%d %d\n", answ_left, answ_right);
	}
	
	system("pause");
	return 0;
}