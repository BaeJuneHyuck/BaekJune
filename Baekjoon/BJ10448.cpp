#include <iostream>
using namespace std;

int tri[45];

int main() {
	for (int i = 1; i < 45; i++) {
		tri[i] = i * (i + 1) / 2;
	}
	int T,a;
	cin >> T;
	while (T--) {
		int one, two, three;
		bool result = false;
		cin >> a;
		for (int i = 1; i < 45; i++) {
			one = tri[i];
			for (int j = 1; j < 45; j++) {
				two = tri[j];
				for (int k = 1; k < 45; k++) {
					three = tri[k];
					if (one + two + three == a) {
						cout << 1 << endl;
						result = true;
						break;
					}
				}
				if (result)break;
			}
			if (result)break;
		}
		if(!result)cout << 0 << endl;
	}

	return 0;
}