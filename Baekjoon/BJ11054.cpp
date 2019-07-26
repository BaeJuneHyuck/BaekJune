#include <iostream>
#include <vector>

using namespace std;
int arr[1001];
int DP[1001];
int DPR[1001];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	DP[0] = 1;
	cout << "1 ";
	for (int i = 1; i < N; i++) {
		int temp = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				temp = temp > (DP[j] + 1) ? temp : (DP[j] + 1);
			}
		}
		DP[i] = temp;
		cout << DP[i] << " ";
	}
	cout << endl;

	DPR[0] = 1;
	for (int i = 1; i < N; i++) {
		int temp = 1;
		for (int j = 0; j < i; j++) {
			if (arr[N- j] < arr[N- i]) {
				temp = temp > (DPR[N-j] + 1) ? temp : (DPR[N-j] + 1);
			}
		}
		DPR[N - i] = temp;
	}

	for (int i = 0; i < N; i++) {
		cout << DPR[i] << " ";
	}
	cout << endl;

	int max_length = 0;
	for (int i = 0; i < N; i++) {

		if (max_length < DPR[i] + DP[i]) max_length = DPR[i] + DP[i];
	}

	cout << max_length - 1;
	system("pause");
	return 0;
}