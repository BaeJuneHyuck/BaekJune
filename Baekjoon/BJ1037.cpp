#include <iostream>
using namespace std;

int main() {
	int N;
	int arr[51];
	cin >> N;
	int min = 123456789;
	int max = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	cout << min * max;
	cin >> N;
	return 0;
}