//백준 6064번 카잉달력
#include <iostream>
using namespace std;

int lcm(int n1, int n2) {
	int hcf = n1;
	int temp = n2;

	while (hcf != temp)
	{
		if (hcf > temp)
			hcf -= temp;
		else
			temp -= hcf;
	}
	return (n1 * n2) / hcf;
}

int getMonth(int M, int N, int x, int y) {
	int xi = 1;
	int yi = 1;
	int Lcm = lcm(M, N);
	if (M == x && N == y) {
		return Lcm;
	}
	for (int i = 1; i <= Lcm;) {
		cout <<i<<"."<<xi<< "," << yi << endl;
		if (xi == x && yi == y) {
			return i;
		}
		if (xi == M) {
			xi = 1;
			yi++;
			i++;
		}
		else if (yi == N) {
			xi++;
			yi = 1;
			i++;
		}
		else if (xi == x) {
			yi = (yi + M) % N;
			if (!yi) {
				yi = N;
				//xi++;
			}
			i = i + M;
		}else if (yi == y) {
			xi = (xi + N) % M;
			if (!xi){
				xi = M;
				//yi++;
			}
			i = i + N;
		}
		else {
			i++; 
			xi++;
			yi++;
		}
	}	
	return -1;
}

int main() {
	int TB;
	cin >> TB;
	while (TB--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		cout << getMonth(M, N, x, y)<<endl;
	}
	system("pause");
	return 0;
}