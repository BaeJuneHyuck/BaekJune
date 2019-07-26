#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int A, B, V;
	int day = 0;
	cin >> A >> B >> V;
	
	day += ceil((double)(V-B) / (A - B));

	cout << day;

	system("pause");
	return 0;
}
