#include <iostream>
using namespace std;

typedef long long ll;

int A, B, C;
// point 1: (X*Y)%M  == (X%M * Y%M)%M
// point 2: Àç±ÍÈ°¿ë log·Î ÂÉ°³±â
ll solve(ll a, ll b) {
	if (b == 0) return 1;
	ll temp = solve(a, b / 2);
	temp = (temp * temp) % C;
	if (b % 2) {
		return (temp * a) % C;
	}
	return temp;
}

int main() {
	cin >> A >> B >> C;
	cout << solve(A, B);

	return 0;
}