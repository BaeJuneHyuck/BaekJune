#pragma warning(disable:4996)
#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;
ll N, M, ans;// 나무갯수, 원하는 길이, 답
vector<int> wood;
ll right=0, left = 0, mid;
int main() {
	scanf("%d %d", &N, &M);
	wood.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d",&wood[i]);
		if (right < wood[i])right = wood[i];
	}

	sort(wood.begin(), wood.end());
	while (left <= right) {
		mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			if (wood[i] - mid > 0) sum += wood[i] - mid;
		}
		if (sum >= M) {
			ans = ans > mid ? ans : mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}