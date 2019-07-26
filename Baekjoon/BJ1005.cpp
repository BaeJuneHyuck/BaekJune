/* ���� 1005�� ACM craft
 ���� ��ȹ���� �̿��� Ư�� �ǹ��� ���� ���� �ɸ��� �ִܽð��� ����ϴ� ����

 <�Է�>
 0:tb
   for tb1 {
	1:�ǹ� ���� N, �Ǽ���Ģ K
	2:�Ǽ� �ð�D (1�� 2�� 3�� 4��...)
	3:�Ǽ� ����O (X Y) (K��) ,x�� ����� y�� ����
	4:������ϴ� �ǹ���ȣ
   }
   for tb2 {
   }....

 <���>
  �� tb������ �ִܽð�

 */

#include<iostream>
#include <cstring>
using namespace std;
int D[1001];			// �ǹ��� �Ǽ��ð�
int O[1001][1001];		// ����ǹ�
int cache[1001]; // N��° �ǹ��� �Ǽ��ϴµ� �ɸ��� ���� ū �ڽ�Ʈ(DP)
int N;

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int getMaxTime(int target) {
	if (cache[target] != -1) return cache[target];
	int maxTime = 0;
	// target�ǹ��� ���������� ��� �˻�
	for (int i = 1; i < N+1;i++) {
		if (O[i][target]) {// ���������� �����ϸ�
			maxTime = max(maxTime,getMaxTime(i)); // ���ݱ��� �ִ�ð����� �� ũ�� ���� max��� 
		}
	}
	return cache[target]= D[target]+maxTime; // ������ �������� max=0�̹Ƿ� �ڱ��ڽ��� �ð��� ���ϵɰ�
}

/*
int getMaxTime(int target) {
	if (cache[target] != -1) return cache[target];
	int maxTime = 0;
	for (int i = 1; i < N+1;i++) {
		if (O[i][target]) {
			int current_time = getMaxTime(i);
			if (current_time > maxTime) {
				cache[i] = maxTime = current_time;
			}
		}
	}2
	return D[target]+maxTime;
}
*/

int main() {
	int TB, K,x,y;
	cin >> TB;
	while (TB--) {
		memset(cache, -1, sizeof(cache));
		cin >> N >> K;
		for (int i = 1; i < N+1; i++) {
			cin >> D[i];
		}

		memset(O, 0, sizeof(O));
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			O[x][y] = 1;
		}
		int target;
		cin >>target;
		cout << getMaxTime(target) << endl;
	}
	system("pause");
	return 0;
}

