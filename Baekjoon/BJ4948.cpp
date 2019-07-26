// 소수찾기
#include <iostream>
#include <cstring>
#define MAX 246913
using namespace std;

bool eratos[MAX];

int main() {

	for (int i = 0; i <= MAX; i++) {
		eratos[i] = true;
	}

	eratos[0] = false;
	eratos[1] = false;

	for (int i = 2; i*i <= MAX; i++) { // sqrt(1000) == 31.62
		if (eratos[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				eratos[j] = false;
			}
		}
	}
	
	int n;
	while (cin >> n) {
		if (n == 0) break;
		int count = 0;

		for (int i = n+1; i <= 2*n; i++) {
			if (eratos[i]) {
				count++;
			}
		}
		printf("%d\n", count);
	}

	return 0;
}