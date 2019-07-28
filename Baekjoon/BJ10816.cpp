#include <stdio.h>
#include <algorithm>
#include <map>
#pragma warning(disable:4996);
using namespace std;

int arr[500001];
int target[500001];
map <int, int> result;
int N, M;

int find(int target, int start, int end) {
	if (arr[start] > target || arr[end] < target) return 0; // �����ȿ� ����
	else if (arr[start] == target) {// ���ۺκп��� ã��
		int count = 1;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] == target)count++;
			else break;
		}
		return count;
	}
	else if (arr[end] == target) {// ������ ã��
		int count = 1;
		for (int i = end - 1; i >= start; i--) {
			if (arr[i] == target)count++;
			else break;
		}
		return count;
	}
	else if (start == end) { // ���̻� �� �ɰ�
		if (target == arr[start]) {
			return 1;
		}return 0;
	}
	else { // �̺�Ž��
		int mid = (start + end) / 2;
		return find(target, start, mid) + find(target, mid + 1, end);
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

	sort(arr, arr + N);

	for (int targetindex = 0; targetindex < M; targetindex++) {
		int num = target[targetindex];
		
		auto itr = result.find(num);	
		if (itr != result.end()) { // ���� �ѹ� ���Ѱ� �˾����� �װɷ� ���
			printf("%d ", itr->second);
		}
		else {// ó������ ã�¼��ڸ� ���� ���ϰ� ���
			int r = find(num, 0, N - 1);
			result.insert({num, r});
			printf("%d ", r);
		}
	}
	scanf("%d", &N);
	return 0;
}