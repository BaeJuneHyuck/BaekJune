// 백준 2108번, 통계학
/*
2초, 256MB

첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 그 다음 N개의 줄에는 정수들이 주어진다.
입력되는 정수의 절댓값은 4,000을 넘지 않는다.

산술평균 : N개의 수들의 합을 N으로 나눈 값 . 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값/  여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
범위 : N개의 수들 중 최댓값과 최솟값의 차이
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
	arr = new int[N+1](); // ()하면 0으로 초기화됨 
	int input = 0;
	for (int i = 0; i < N; i++) {
		cin >> input;

		sum += input;
		if (input > max) max = input;
		if (input < min) min = input;

		int	index = input + 4000;	// -4000 ~ 4000 까지의 bitmap sort 위해서 횟수 기록
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