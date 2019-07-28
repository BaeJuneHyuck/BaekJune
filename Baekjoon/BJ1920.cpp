#include <stdio.h>
#include <algorithm>
#pragma warning(disable:4996);
using namespace std;

int arr[100001];
int target[100001];
int N, M;

bool find(int target, int start, int end) {
	if (arr[start] > target || arr[end] < target) return false;
	if (start == end) {
		if (target == arr[start]) {
			return true;
		}return false;
	}
	else {
		int mid = (start + end) / 2;
		return find(target, start, mid) || find(target, mid + 1, end);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &target[i]);
	}

	sort(arr, arr+N);
	
	int arrindex = 0;
	int targetindex = 0;
	for (targetindex = 0; targetindex < M; targetindex++) {
		if(find(target[targetindex], 0 , N - 1))printf("1\n");
		else printf("0\n");
	}

	
	scanf("%d", &N);
	return 0;
}