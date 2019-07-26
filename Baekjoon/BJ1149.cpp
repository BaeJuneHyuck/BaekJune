// ���� 1149�� RGB�Ÿ�

#include <iostream>
using namespace std;
int cost[1000][3] = { 0 };
int minCost[1000][3] = {0};

int min(int a,int b) {
	if (a < b)return a;
	else return b;
}

// index ��° ���� color�� ĥ�Ҷ� cost
// color�� ������ ������ �� ���� �ּ�cost + �ڱ��ڽ��� cost
int getLeastCost(int index, int color) {
	if (minCost[index][color]) return minCost[index][color];
	if (index == 0) {
		return cost[index][color];
		/*
		switch (color) {
		case 0:
			return min(cost[index][1], cost[index][2]);
		case 1:
			return min(cost[index][0], cost[index][2]);
		case 2:
			return min(cost[index][1], cost[index][0]);
		}*/
	}
	switch(color) {
		case 0:
			 minCost[index][color] = min(getLeastCost(index - 1, 1), getLeastCost(index - 1, 2)) + cost[index][color];
			break;
		case 1:
			minCost[index][color] = min(getLeastCost(index - 1, 0), getLeastCost(index - 1, 2)) + cost[index][color];
			break;
		case 2:
			minCost[index][color] = min(getLeastCost(index - 1, 1), getLeastCost(index - 1, 0)) + cost[index][color];
			break;
	}
	return minCost[index][color];
}

int main() {
	int total;
	cin >> total;

	for (int index = 0; index < total; index++) {
		cin >> cost[index][0] >> cost[index][1]>> cost[index][2];
	}
	cout << min(min(getLeastCost(total-1,0), getLeastCost(total-1, 1)), getLeastCost(total-1, 2)) << endl;

	system("pause");
	return 0;
}
