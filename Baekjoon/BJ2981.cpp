#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<int> num;
vector<int> diff;
int diffmin = 987654321;
/* a = d1 / D + r1
   b = d2 / D + r2
   ... 나머지가 같다 ( r1 == r2 ) 면
   a-b = (d1-d2)/ D
    즉 나머지가 같으면 수의 차이가 D로 나눠 떨어진다

	시간초과, 포기
	*/

int main() {
	cin >> N;
	num = vector<int>(N);
	diff = vector<int>(N);

	cin >> num[0];
	for (int i = 1; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end());
	for (int i = 1; i < N; i++) {
		diff[i] = num[i] - num[i-1];
		if (diff[i] < diffmin) diffmin = diff[i];
		// cout << diff[i] << endl;
	}

	
	for (int M = 2; M <= diffmin; M++) { // 가능한 M 후보들로 나눠지는지 확인
		bool result = true;
		for (int i = 1; i < N; i++) {	// 모든 diff 에 대해서 M이 나눠 떨어지면 M은 나머지가 같은 수
			if (diff[i] % M) { // 하나라도 아니면 탈락
				//cout <<diff[i] <<"=diff[" << i << "] 는 " << M << " 으로 안떨어진다\n";
				result = false;
				break;
			}
		}
		if(result) cout << M << " ";
	}
	
	return 0;
}