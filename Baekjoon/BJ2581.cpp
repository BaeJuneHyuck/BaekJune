// 소수찾기
#include <iostream>
#include <cstring>
using namespace std;
bool eratos[1000001];

int main() {
	int M, N;
	cin >> M >> N;

	for (int i = 0; i <= N; i++) {
		eratos[i] = true;
	}

	eratos[0] = false;
	eratos[1] = false;

	for (int i = 2; i*i <= N; i++) { // sqrt(1000) == 31.62
		if (eratos[i]) {
			for (int j = i * 2; j <= N; j += i) {
				eratos[j] = false;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (eratos[i]) {
			printf("%d\n", i);
			//cout << i << endl;
		}
	}
	system("pause");
	return 0;
}