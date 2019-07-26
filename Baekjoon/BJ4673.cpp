// 백준 4673 셀프넘버
#include <iostream>

using namespace std;

int getSum(int a) {
	int sum = a;
	int digit;
	while (a >= 10) {
		digit = a % 10;
		a = a / 10;
		sum += digit;
	}
	sum += a;
	return sum;
}

bool isSelf(int a) {
	for (int i = 0; i < a; i++) {
		if (getSum(i) == a) return false;
	}
	return true;
}

int main() {
	for (int i = 1 ;i <= 10000; i++) {
		if(isSelf(i)) cout<<i <<endl;
	}
	system("pause");
	return 0;
}

/* 
 채점번호 11918799, 	woochang4862님의 코드

 #include <stdio.h>

int dn[10001];

int d(int i){
	int res = i;
	for(;i!=0;i/=10){
		res+=(i%10);
	}
	return res;
}

int main(){
	for(int i=1;i<=10000;i++){
		dn[d(i)] = 1;
		if(!dn[i]) printf("%d\n", i);
	}
}
*/