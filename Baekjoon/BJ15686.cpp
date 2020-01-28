#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#pragma warning(disable:4996)
using namespace std;

int N, M;
int map[51][51];
struct point {
	int x, y;
};
vector<point> home;
vector<point> chicken;
int ans = 9876543210;

int calc(point p1, point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) home.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	
	// 조합을 만드는 다른 방법
	// k개를 뽑을때 k개의 1, 전체-k개의 0을 넣은 인덱스 배열을 next_permutation으로 섞어서
	// 1이 있는 위치의 원소만 선택하기

	vector<int> ind;
	int k = M;
	for (int i = 0; i < chicken.size(); i++) {
		if(i<k) ind.push_back(1);
		else ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	do {
		// 가능한 조합에 대해서
		vector<point> selected_chicken;
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				selected_chicken.push_back(chicken[i]);
			}
		}
		
		// 각 집은 가장 가까운 치킨집을 선택하여 거리에 더한다
		int total = 0;
		for (int h = 0; h < home.size(); h++) {
			int d = 9876543210;
			for (int c = 0; c < selected_chicken.size(); c++) {
				d = min(d, calc(home[h], selected_chicken[c]));
			}
			total += d;
		}

		ans = min(ans, total);
	} while (next_permutation(ind.begin(), ind.end()));

	printf("%d", ans);
	return 0;
}