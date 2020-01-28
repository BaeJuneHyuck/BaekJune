#include <iostream>

/*
��������:https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html
	���� �迭�α���(���� ����Ʈ��)1, 23, 4567
	�ε��� 1���� ���
	index i ����: �����ڽ� = 2 * i, �������ڽ� = 2 * i + 1, �θ�  = i/2;

	����:
	1. �ϴ� ���������ֱ�
	2. �θ� ���� ���Ͽ� �켱���� ������ ��ü-�ݺ�

	����:
	1. ��Ʈ��带 ����
	2. ���� ������ ��带 ��Ʈ�� ������
	3. �ڽĵ��� �� ���� �켱������ �ڽİ� ��ü-�ݺ�
*/


using namespace std;
int N;
class maxHeap {
	int* arr;
	int size;
public:
	maxHeap() {
		arr = new int[100001];
		size = 0;
	}

	void push(int a) {
		arr[++size] = a;// ������ �ڸ��� �ְ�
		for (int i = size; i > 1; i /= 2) {
			if (arr[i / 2] < arr[i]) {// �θ𺸴� ũ�� ��ġ ���� �ݺ�
				int temp = arr[i / 2];
				arr[i / 2] = arr[i];
				arr[i] = temp;
			}
			else {// ���ٲٸ� ����
				break;
			}
		}
	}

	int pop() {// top�� ���� ���� �������� ��������
		if (size == 0) return 0;
		int ret = arr[1];	// �����ϱ����� ���� �ִ밪�� ����ϰ�

		int movingnode = arr[size]; // ���� ��������
		arr[1] = movingnode;// ��Ʈ ����
		size--;

		int i = 1;
		for (; i * 2 <= size;) {
			if (arr[i] > arr[2 * i] && arr[i] > arr[2 * i + 1]) break;
			else if (arr[i * 2] > arr[i * 2 + 1]) {
				int temp = arr[i * 2];
				arr[i * 2] = arr[i];
				arr[i] = temp;
				i = i * 2;
			}
			else {
				int temp = arr[i * 2 + 1];
				arr[i * 2 + 1] = arr[i];
				arr[i] = temp;
				i = i * 2 + 1;
			}
		}

		return ret;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	maxHeap h;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input) { h.push(input); }
		else { cout <<h.pop() << "\n";}
	}
}
