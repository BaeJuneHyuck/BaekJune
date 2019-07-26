#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
vector<tuple<int, int>> v;

bool compare(tuple<int, int> a, tuple<int, int> b) {
	if (get<0>(a) < get<0>(b)) return true;
	else if (get<0>(a) == get<0>(b) && (get<1>(a) < get<1>(b))) return true;
	else return false;
}

int main() {
	int N, a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v.push_back(make_tuple(a, b));
	}

	sort(v.begin(), v.end(), compare);
	
	int DP[101];
	int max = 1;
	DP[0] = 1;
	for (int i = 1; i < N; i++) {
		int temp = 1;
		int right = get<1>(v[i]);
		for (int j = 0; j < i; j++) {
			int left = get<1>(v[j]);
			if (left < right) {
				temp = temp > (DP[j]+1) ? temp : (DP[j] + 1);
			}
		}
		DP[i] = temp;
		if (max < temp) max = temp;
	}
	cout << (N - max);
	system("pause");
	return 0;
}