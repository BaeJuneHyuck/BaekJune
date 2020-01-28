#pragma warning(disable:4996)
#include <cstdio>

int N, B, C;
int arr[1000001];
int main() {
	//printf("hello\n");
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		arr[i] -= B;
		sum++;	// 총감독관 한명이 B명 처리
		if (arr[i] > 0) {
			sum += arr[i] / C;
			if (arr[i] % C != 0)sum++;
		}
	}
	printf("%lld", sum);
	return 0;
}