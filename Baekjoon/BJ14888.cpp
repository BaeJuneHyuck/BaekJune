#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
vector<int> numbers;
vector<int> selected_operators;
int N;
int operators[4];
int c_max = -1234567890;
int c_min = 1234567890;

void backtracking(int index) {
	if (index == N - 1) {
		int result = numbers[0];

		for (int i = 0; i < N - 1; i++) {
			switch (selected_operators[i]) {
			case(0):
				result += numbers[i+1];
				break;
			case(1):
				result -= numbers[i + 1];
				break;
			case(2):
				result *= numbers[i + 1];
				break;
			case(3):
				result /= numbers[i + 1];
				break;
			}
		}
		
		if (result > c_max) c_max = result;
		if (result < c_min)c_min = result;

		return;
	}

	for (int i = 0; i < 4; i++) {
		if (operators[i] > 0) {
			operators[i]--;
			selected_operators.push_back(i);
			backtracking(index+1);
			selected_operators.pop_back();
			operators[i]++;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		numbers.push_back(temp);
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i];
	}

	backtracking(0);
	cout << c_max << endl << c_min;
	
	system("pause");
	return 0;
}