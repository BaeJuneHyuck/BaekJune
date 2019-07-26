// ���� 10989��, �� �����ϱ� 3
// ī���� ����(Counting Sort) Ȥ�� ��� ����(Radix Sort)�� ����� ���ϴ�

// ī��������, �޸��ʰ�
// �����ϰ� �����迭, �Լ�ȣ��, ���迭 �̷��� ��������
// ���ο��� �ѹ��� �ع�����

#include <iostream>
using namespace std;

/*
	int *histogram, *rank;
	histogram = new int[max + 1]();
	for (int i = 0; i < size; i++) {
		histogram[arr[i]]++;
	}
	for (int i = 1; i < size; i++) {
		histogram[i] = histogram[i - 1] + histogram[i];
	}

	int *sorted = new int[size];
	
	for (int i = 0; i < size; i++) {
		sorted[--histogram[arr[i]]] = arr[i];
	}

	for (int i = 0; i < size; i++) {
		arr[i] = sorted[i];
	}
	delete[]sorted;
	delete[]histogram;
*/

int main() {
	int N,input;
	cin >> N;
	int *cntarr;
	cntarr = new int[10001](); // () ���̸� 0���� �ʱ�ȭ�� memset �ʿ����
	for (int i = 0; i < N; i++) {
		cin >> input;
		cntarr[input]++;
	}
	for (int i = 1; i < 10001; i++) {
		cntarr[i] += cntarr[i - 1];
	}
	for(int i = 1 ; i< 10001;i++){
		int cnt = cntarr[i] - cntarr[i-1];
		while (cnt--) {
			printf("%d\n", i);
		}
	}

	system("pause");
	return 0;
}