// ���� 2750��, �� �����ϱ�
/*
�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����.
�� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.

����/ ��ǰ����
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[1001];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// ���� ��Ʈ
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " " ;
	}

	system("pause");
	return 0;
}