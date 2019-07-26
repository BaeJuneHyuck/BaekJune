// BJ 1931번, interval scheduling maximization problem (ISMP)
// greey solution

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

struct job {
	int s;
	int e;
};

bool compare(job a, job b) {
	if (a.e < b.e) return true;
	else if (a.e == b.e && a.s < b.s) return true;
	else return false;
}

vector<job> jobs;

int main() {
	int N, start, end;
	scanf_s("%d",&N);
	jobs = vector<job>(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d", &start, &end);
		// 쉣;; cin 하면 안되는구나
		jobs[i].s = start;
		jobs[i].e = end;
	}

	sort(jobs.begin(), jobs.end(), compare);
	cout << "------\n";

	int select = 0;
	int current_end = 0;
	for (int i = 0; i < N; i++) {
		cout << jobs[i].s << " " << jobs[i].e << endl;
		if (jobs[i].s >= current_end) {
			current_end = jobs[i].e;
			select++;
		}
	}
	printf("%d",select);
	system("pause");
	return 0;
}