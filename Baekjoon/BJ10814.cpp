#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Person {
public:
	Person() {}
	Person(int _a, char* _n) {
		age = _a;
		strcpy(name, _n);
	}

	Person(const Person& rhs)
	{
		age = rhs.age;
		int len;
		len = strlen(rhs.name);
		strncpy(name, rhs.name, len);

	}

	int age;
	char name[101];	
};

int N;

Person P[100001];
Person sorted[100001];

void merge(Person arr[], int start, int mid, int end) {
	int i = start;// arrÀÇ index
	int j = mid+1;
	int k = start;// sortedÀÇ index
	int l;
	while (i <= mid && j <= end) {
		if (arr[i].age <= arr[j].age) {
			sorted[k++] = arr[i++];
		}
		else {
			sorted[k++] = arr[j++];
		}
	}

	if (i > mid) {
		for (l = j; l <= end; l++) {
			sorted[k++] = arr[l];
		}
	}
	else {
		for (l = i; l <= mid; l++) {
			sorted[k++] = arr[l];
		}
	}

	for (l = start; l <= end; l++) {
		arr[l] = sorted[l];
	}
}

void mergesort(Person arr[], int start, int end) {
	
	if (start< end) {
		int mid = (start + end) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}

int main() {
	scanf("%d",&N);
	for(int i = 0 ; i < N ; i++) {
		scanf("%d %s", &P[i].age, &P[i].name);
 	}
	mergesort(P, 0, N-1);

	for (int i = 0; i < N; i++) {
		printf("%d %s\n", P[i].age, P[i].name);
	}

	system("pause");
	return 0;
}