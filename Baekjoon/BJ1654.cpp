#pragma warning(disable:4996)
#include <cstdio>
typedef long long ll;
using namespace std;

int k, n;// �̹� �������ִ� ����, ���ϴ� ����
int len[10001];
ll right=1, left=1, mid;// �� ������ int�������� ���Ұ��...
int ans = 0;

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
		if (len[i] > right) right = len[i];
	}

	/*
		�䱸: �ִ���̷� n���� �޼��ϱ�
		�̹� �����ϴ°͵��� �߶� n���� ����� , ���̰� �ִ밡 �Ǿ����
		�ڸ��� ���̸� ������ �����鼭 ���� �´��� Ȯ��
		���� mid�� ���� �����Ұ�� ������ ����
	*/

	while (left<=right) {
		mid = (right + left) / 2;
		// mid�� �ڸ��� n�� �� ������ִ°�
		ll cut = 0;
		for (int i = 0; i < k; i++) {
			cut = cut + len[i] / mid;
		}

		if (cut >= n) { // n�� ����������� ���̸� �� ª�� �غ����մ�
			ans = mid>ans? mid : ans;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}