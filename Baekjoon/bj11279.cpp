#include <iostream>

/*
개념참고:https://gmlwjd9405.github.io/2018/05/10/data-structure-heap.html
	보통 배열로구현(완전 이진트리)1, 23, 4567
	인덱스 1부터 사용
	index i 기준: 왼쪽자식 = 2 * i, 오른쪽자식 = 2 * i + 1, 부모  = i/2;

	삽입:
	1. 일단 마지막에넣기
	2. 부모 노드와 비교하여 우선순위 높으면 교체-반복

	삭제:
	1. 루트노드를 삭제
	2. 힙의 마지막 노드를 루트로 가져옴
	3. 자식들중 더 높은 우선순위인 자식과 교체-반복
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
		arr[++size] = a;// 마지막 자리에 넣고
		for (int i = size; i > 1; i /= 2) {
			if (arr[i / 2] < arr[i]) {// 부모보다 크면 위치 변경 반복
				int temp = arr[i / 2];
				arr[i / 2] = arr[i];
				arr[i] = temp;
			}
			else {// 못바꾸면 종료
				break;
			}
		}
	}

	int pop() {// top을 빼고 가장 마지막껄 가져오자
		if (size == 0) return 0;
		int ret = arr[1];	// 리턴하기위해 원래 최대값을 기억하고

		int movingnode = arr[size]; // 가장 마지막을
		arr[1] = movingnode;// 루트 노드로
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
