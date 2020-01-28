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
	
	// ������ ����� �ٸ� ���
	// k���� ������ k���� 1, ��ü-k���� 0�� ���� �ε��� �迭�� next_permutation���� ���
	// 1�� �ִ� ��ġ�� ���Ҹ� �����ϱ�

	vector<int> ind;
	int k = M;
	for (int i = 0; i < chicken.size(); i++) {
		if(i<k) ind.push_back(1);
		else ind.push_back(0);
	}
	sort(ind.begin(), ind.end());
	do {
		// ������ ���տ� ���ؼ�
		vector<point> selected_chicken;
		for (int i = 0; i < ind.size(); i++) {
			if (ind[i] == 1) {
				selected_chicken.push_back(chicken[i]);
			}
		}
		
		// �� ���� ���� ����� ġŲ���� �����Ͽ� �Ÿ��� ���Ѵ�
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