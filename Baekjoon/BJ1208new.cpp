// ���� 2108��, �����
/*
2��, 256MB

ù° �ٿ� ���� ���� N(1 �� N �� 500,000)�� �־�����. �� ���� N���� �ٿ��� �������� �־�����.
�ԷµǴ� ������ ������ 4,000�� ���� �ʴ´�.

������ : N���� ������ ���� N���� ���� �� . �Ҽ��� ���� ù° �ڸ����� �ݿø��� ���� ����Ѵ�.
�߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
�ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��/  ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.
���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int hist[8001] = { 0, };
	int sum = 0;
	int N, mid;
	int min = 4001;
	int max = -4001;
	int *arr;
	vector<int> modelist;
	int mode = 0; //current max appear
	cin >> N;
	arr = new int[N+1](); // ()�ϸ� 0���� �ʱ�ȭ�� 
	int input = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;

		sum += input;
		if (input > max) max = input;
		if (input < min) min = input;

		int	index = input + 4000;	// -4000 ~ 4000 ������ bitmap sort ���ؼ� Ƚ�� ���
		hist[index]++;
		if (hist[index] > mode) {
			mode = hist[index];
			modelist.clear();
			modelist.push_back(input);
		}
		else if(hist[index] == mode) {
			modelist.push_back(input);
		}
	}
	
	int arrindex = 0;
	for (int i = min+4000; i <= max+4000; i++) {
		while (hist[i] > 0) {
			hist[i]--;
			arr[arrindex++] = i-4000;
		}
	}
	
	sort(modelist.begin(), modelist.end());


	mid = arr[N / 2];
	float avg = (float)sum / N;

	cout << round((float)sum / N) << '\n';
	cout << mid << '\n';
	if (modelist.size() > 1) {
		cout << modelist.at(1) << '\n';
	}
	else {
		cout << modelist.at(0) << '\n';
	}
	cout << abs(max - min) << '\n';

	//system("pause");
	return 0;
}