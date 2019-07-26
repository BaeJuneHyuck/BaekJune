#include <iostream>
#include <math.h>
using namespace std;

bool broken[10];

int digits(int n) {
	if (!n) return 1;
	int digit = 0;
	while (n) {
		n /= 10;
		digit++;
	}
	return digit;
}

int checkPossible(int n) { // 가능한 숫자면 -1, 불가능한 숫자면 불가능한 자리수를 리턴
	int digit = 0;
	if (!n) {
		if (broken[0])return digit;
	}
	while (n) {
		int d = n % 10;
		if (broken[d])return digit;
		n /= 10;
		digit++;
	}
	return -1;
}

int main() {
	int target,bbroken;
	cin >> target >> bbroken;
	for(int i = 0 ; i< bbroken;i++){
		int temp;
		cin >> temp;
		broken[temp] = true;
	}

	if (target == 100) {
		cout << 0;
	}else if (bbroken == 10) {
		cout << abs(target - 100);
	}else {
		int digit = digits(target);//자릿수

		// 타겟에 가장 가까운 채널 구한뒤 이동으로 접근하기
		int min = abs(target - 100); // 버튼없이 이동만으로 대상에 도착할경우 횟수를 최소로 설정하고
	
		//int maxnum = digit+1 > 6 ?  6 : digit+1; // 1부터 (대상이 십단위면 백단위 최대(999)까지)
		for (int temp = 0; temp <= 1000000; temp++){ 
			int possible = checkPossible(temp);
			if (possible == -1) { // temp는 버튼입력이 가능한 숫자, 따라서 버튼횟수+이후 이동 = distance
				int distance = abs(temp - target);
				distance = distance + digits(temp);
				if (min > distance) {
					min = distance;
				}
			}
			/*
			else {// 불가능한경우,  불가능한 자릿수에대해서 1증가시키자 
				// 2153에서 1이 불가능하면 다음은 2253(즉 10^2더하니까)을 시도해야함
				temp = temp + pow(10, possible);
			}
			*/
		}
		cout << min << endl;
	}

	system("pause");
	return 0;
}