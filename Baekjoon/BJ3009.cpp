#include <iostream>

using namespace std;

int main() {
	int x[3];
	int y[3];
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	int ansx, ansy;
	ansx = (x[0] == x[1]) ? x[2] : (x[2] == x[1]) ? x[0] : x[1];
	ansy = (y[0] == y[1]) ? y[2] : (y[2] == y[1]) ? y[0] : y[1];
	cout << ansx << " " << ansy;
	cin >> ansx;
	return 0;
}