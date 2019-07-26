#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> arr(N+1);
	int min = 10000;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	sort(arr.begin(), arr.end());

	int max = 0;
	int n = N;
	for(int i = 1; i<=N;){
		if (max < arr[i] * n) max = arr[i] * n;
		i++;
		n--;
	}
	cout << max;
	//답은 max( N * 최소 , N-1*2번재, N-2 * 3번째...)
	cin >> N;
	return 0;
}