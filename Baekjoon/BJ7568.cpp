#include <iostream>
#include <vector>
#include <tuple>
using namespace std;


int main() {
	int N;
	cin >> N;
	int rank[51];
	tuple<int, int> person[51];

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		person[i] = make_tuple(x, y);
		rank[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if ( (get<0>(person[i]) < get<0>(person[j])) && (get<1>(person[i]) < get<1>(person[j]) )) {
				rank[i]++;
			}
		}
		cout << rank[i] + 1 << endl;
	}

	system("pause");
	return 0;
}