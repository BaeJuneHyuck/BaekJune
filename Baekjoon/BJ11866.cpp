#include <iostream>
using namespace std;

bool circQueue[1002];

int main() {
	int N, K;
	cin >> N >> K;

	int front = 1;
	int current = front;
	
	cout << "<";
	for (int i = 0; i < N; i++) {
		circQueue[current] = true;
		cout << current;
		current += K;
		while (!circQueue[current]) {
			current++;
			if (current == N)current = 1;
		}
		if(i != N-1) cout << ", ";
	}
	cout << ">";
	
	system("pause");
	return 0;
}