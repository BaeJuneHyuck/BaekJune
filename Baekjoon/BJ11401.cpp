#pragma warning(disable:4996)
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x, y;
	point(int _x, int _y) :x(_x), y(_y) {}
	point(){}
};

bool compX(point& p1, point& p2) {
	return p1.x < p2.x;
}

bool compY(point& p1, point& p2) {
	return p1.y < p2.y;
}

int dist(point& p1, point& p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int min(int a, int b) { return a > b ? b : a; }

int n, x, y;
vector<point> p;

int solve(int l, int n) {// left���� n���� �� ���� ��������
	if (n == 2) { return dist(p[l], p[l+1]); }
	
	if (n <= 3) {
		return min(dist(p[l], p[l + 1]), min(dist(p[l], p[l + 2]), dist(p[l + 1], p[l + 2])));
	}
	
	int mid = n / 2;
	int midx = p[l + mid].x;
	int dl = solve(l, mid);
	int dr = solve(l+mid,n-mid);
	int d = min(dr, dl);

	vector<point> cand;
	// x�� ���� ������ �ĺ� ���ϱ�
	for (int i = l; i < l + n; i++) {
		int diff = midx - p[i].x;
		if (diff * diff < d) cand.push_back(p[i]);
	}
	int size = cand.size();
	// y�� ������ y�� ���� �����ĺ� ���ϱ�
	sort(cand.begin(), cand.end(), compY);
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			int diff = cand[i].y - cand[j].y;
			if (diff * diff < d) d = min(d, dist(cand[i], cand[j]));
			else break; // y�� ���� ������ ���� �ϴµ� ���̰� �ʰ��ϸ� �ڿ��͵��� �� �ʿ����
		}
	}
	return d;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		p.push_back(point(x, y));
	}

	sort(p.begin(), p.end(), compX);
	printf("%d", solve(0, n));
	return 0;
}