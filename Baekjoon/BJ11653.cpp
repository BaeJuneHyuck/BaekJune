#include <stdio.h>
using namespace std;

int main() {
	int N;
	scanf("%d",&N);
	int a = N;
	int i = 2;
	while (a != 1) {
		if (a % i == 0) {
			printf("%d\n",i);
			a = a / i;
		}
		else {
			i++;
		}
		if (i > N/2 + 1)break;
	}
	return 0;
}