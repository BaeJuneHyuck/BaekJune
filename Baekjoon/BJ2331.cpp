#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int A, P;
int getA(int a) {
	int result = 0;
	int temp = a;
	while (temp) {
		int digit = temp % 10;
		temp /= 10;
		result = result + pow(digit, P);
	}
	return result;
}

int main() {
	cin >> A >> P;
	vector<int> arr = vector<int>(12345);
	arr[0] = A;
	int index = 0;
	while (1) {
		index++;
		arr[index] = getA(arr[index-1]);
		//cout << arr[index] << " ";
		int repeat = -1;
		for (int i = 0; i < index; i++) {
			if (arr[i] == arr[index]){
				repeat = i; 
				break;
			}
		}
		if (repeat != -1) {
			cout << repeat<< endl;
			break;
		}
	}
	system("pause");
	return 0;
}