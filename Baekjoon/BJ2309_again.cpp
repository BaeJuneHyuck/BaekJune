#include <iostream>

using namespace std;

int main() {
	int arr[9], one , two;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9 ; j++){
			if (sum - arr[i] - arr[j] == 100) {
				one = arr[i];
				two = arr[j];
			}
			if (arr[i] > arr[j]) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (arr[i] != one && arr[i] != two) {
			cout << arr[i] << endl;
		}
	}
	system("pause");
	return 0;
}