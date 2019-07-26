// 백준 2750번, 수 정렬하기
/*
입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다.
이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

삽입/ 거품정렬
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

	// 버블 소트
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