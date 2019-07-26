// 소수찾기
#include <iostream>
using namespace std;

bool eratos[1001];

int main() {
	int T;
	int count = 0;
	cin >> T;

	memset(eratos, true, sizeof(eratos));
	eratos[1] = false;
	for (int i = 2; i*i <= 1000; i++) { // sqrt(1000) == 31.62
		if (eratos[i]) {
			for (int j = i * 2; j <= 1000; j += i) {
				eratos[j] = false;
			}
		}
	}

	while(T--) {
		int temp;
		cin >> temp;
		if (eratos[temp]) {
			count++;
		}
	}
	cout << count;
	system("pause");
	return 0;
}