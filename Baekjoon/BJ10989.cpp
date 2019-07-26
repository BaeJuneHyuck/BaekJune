// 백준 10989번, 수 정렬하기 3
// 카운팅 정렬(Counting Sort) 혹은 기수 정렬(Radix Sort)를 사용해 봅니다

// 카운팅정렬, 메모리초과
// 정직하게 원본배열, 함수호출, 새배열 이렇게 하지말고
// 메인에서 한번에 해버리자

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
	cntarr = new int[10001](); // () 붙이면 0으로 초기화됨 memset 필요없이
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