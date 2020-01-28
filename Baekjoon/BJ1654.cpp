#pragma warning(disable:4996)
#include <cstdio>
typedef long long ll;
using namespace std;

int k, n;// 이미 가지고있는 랜선, 원하는 갯수
int len[10001];
ll right=1, left=1, mid;// 각 랜선은 int이하지만 합할경우...
int ans = 0;

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
		if (len[i] > right) right = len[i];
	}

	/*
		요구: 최대길이로 n개를 달성하기
		이미 존재하는것들을 잘라서 n개를 만들되 , 길이가 최대가 되어야함
		자르는 길이를 수정해 나가면서 조건 맞는지 확인
		현재 mid가 조건 가능할경우 범위를 수정
	*/

	while (left<=right) {
		mid = (right + left) / 2;
		// mid로 자를때 n개 를 만들수있는가
		ll cut = 0;
		for (int i = 0; i < k; i++) {
			cut = cut + len[i] / mid;
		}

		if (cut >= n) { // n개 만들수있으면 길이를 더 짧게 해볼수잇다
			ans = mid>ans? mid : ans;
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}