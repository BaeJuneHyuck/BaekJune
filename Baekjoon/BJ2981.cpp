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
   ... �������� ���� ( r1 == r2 ) ��
   a-b = (d1-d2)/ D
    �� �������� ������ ���� ���̰� D�� ���� ��������

	�ð��ʰ�, ����
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

	
	for (int M = 2; M <= diffmin; M++) { // ������ M �ĺ���� ���������� Ȯ��
		bool result = true;
		for (int i = 1; i < N; i++) {	// ��� diff �� ���ؼ� M�� ���� �������� M�� �������� ���� ��
			if (diff[i] % M) { // �ϳ��� �ƴϸ� Ż��
				//cout <<diff[i] <<"=diff[" << i << "] �� " << M << " ���� �ȶ�������\n";
				result = false;
				break;
			}
		}
		if(result) cout << M << " ";
	}
	
	return 0;
}