#include <iostream>
#include <math.h>
using namespace std;

long long int DP[101];

bool check(int n) {
	int nob = 0;
	int prev = -1;
	bool result = true;
	while(n) {
		nob++;
		if (prev == -1) prev = n % 10;
		else {
			int temp = n % 10;
			if (temp - 1 != prev && temp + 1 != prev) {
				return false;
			}
			prev = temp;
		}
		n /= 10;
	}
	DP[nob]++;
	return true;
}

int main() {
	int sum = 0;

	for (int j = 1; j < 10; j++) {
		int x = 0;
		//cout << "-sum : "<<sum <<endl;
		for (int i = j * 10; i < (j + 1) * 10; i++) {
			if (check(i)) {
				//cout << i << endl;
				sum++; x++;
			}
		}
		cout << j * 10 << " x:" << x << endl;
	}
	cout << "두자리 sum =" << sum << endl;
	sum = 0;
	for (int j = 1; j < 10; j++) {
		int x = 0;
		//cout << "-sum : "<<sum <<endl;
		for (int i = j*100; i < (j+1)*100; i++) {
			if (check(i)) {
				//cout << i << endl;
				sum++; x++;
			}
		}
		cout <<j*100<<" x:"<< x << endl;
	}
	cout << "세자리 sum =" << sum << endl;
	
	sum = 0;
	for (int j = 1; j < 10; j++) {
		int x = 0;
		//cout << "-sum : "<<sum <<endl;
		for (int i = j * 1000; i < (j + 1) * 1000; i++) {
			if (check(i)) {
				//cout << i << endl;
				sum++; x++;
			}
		}
		cout << j * 1000 << " x:" << x << endl;
	}
	cout << "네자리 sum =" << sum << endl;

	cout<<DP[4]<<endl;
	system("pause");
	return 0;
}
