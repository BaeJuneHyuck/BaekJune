#include <iostream>
#include <vector>
using namespace std;

int arr[13];
vector<int> list(13);

void pick(int n, vector<int>&picked, int toPick) {
	if (toPick == 0) {
		for (int i = 0; i < picked.size(); i++) {
			printf("%d ", arr[picked[i]]);
		}
		printf("\n");
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n ; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	int k;
	while (cin >> k) {
		if (k == 0)break;
		list.clear();
		for (int i = 0; i < k; i++) {
			cin >> arr[i];
		}
		pick(k, list, 6);
		printf("\n");
	}
	return 0;
}