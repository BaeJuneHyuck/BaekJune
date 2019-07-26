#pragma warning(disable:4996)
#include <stdio.h>
using namespace std;

int arr[1000001];
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		bool find = false;
		for (int j = i + 1; j < N; j++) {
			if (arr[j] > arr[i]) {
				printf("%d ", arr[j]);
				find = true;
				break;
			}
		}
		if (!find) printf("-1 ");
	}

	scanf("%d", &N);
	return 0;
}