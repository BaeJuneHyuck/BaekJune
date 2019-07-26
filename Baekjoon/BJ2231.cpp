
// 자연수 N의 분해합은  N + 각자리수
// 자연수 M의 분해합이 N이 되는경우 M을 N의 생성자라고 한다
// 그럼 생성자는 대상보단 작아야 되겟군
// N을 입력받앗을때 가장작은 생성자를 출력해라 없을경우 0


// 아이디어
/*
  N을 입력받으면 N보다 작은 수 모두다 분해합 구해서 N이 나오는지 확인하자
  작은수부터 시작하면 제일 먼저 나오는애가 가장작은 생성자니까 바로 멈추면 된다
  1부터 바로 할필요없다 1을 분해해봣자 몇백이 나올수없으니
  분해합이 가능한수를 구하자
  각 자리수는 최대 9까지 나오니 10자리수라면 90 + 자기자신 이 최대로 나온다
  그거보다 작은거에 대해서는 시도할 필요가없다
*/

#include <iostream>
#include <math.h>

using namespace std;

int getdigits(int x) {
	for (int i = 0; i < 7; i++) {
		if ((int)(x / (pow(10, i))) == 0) {
			return i;
		}
	}
}

int getsum(int x) {
	int digits = getdigits(x);
	int sum = x + (x % 10);
	for (int i = 1; i < digits; i++) {
		int d = (int)(x / pow(10, i)) % 10;
		sum = sum + d;
	}
	return sum;
}

int main() {
	int N, digits=0;
	cin >> N;

	// 자리수 구해서 후보군 좁히기
	digits = getdigits(N);
	// 자리수 구햇다 N의 분해합 후보가 될수잇는 애들은?
	// ex 세자리수면 333
	// 분해합으로 333이 나올려면 적어도 세자리수여야 겟지
	// M + 3(9) // 최대 9인게 3자리 추가되서 333이 나올려면
	// M은 최소 333-9x3

	int sum;
	for (int i = N - digits * 9; i < N; i++) {
		//cout << "후보:" << i <<" / ";
		for (int j = 0; j < digits; j++) {
			sum = getsum(i);
		}
		//cout << " / sum = " << sum<<endl;
		if (sum == N) {
			cout << i << endl;

			system("pause");
			return 0;
		}
	}
	cout << 0 << endl;
	system("pause");
	return 0;
}