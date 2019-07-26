#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visited[100001];

class node {
public:
	int pos;
	int day;
	node(int p, int d) :pos(p), day(d) {}
};

int main() {
	cin >> N >> K;
	queue<node> q;
	q.push(node(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		node here = q.front();
		q.pop();
		int pos = here.pos;
		int day = here.day;
		//cout << day << " : " << pos << endl;
		if (pos == K) {
			cout << day;
			break;
		}
		if (pos + 1 < 100001 && !visited[pos+ 1]) { q.push(node(pos + 1, day + 1)); visited[pos + 1] = true; }
		if (2 * pos < 100001 && !visited[2 * pos]) { q.push(node(2 * pos, day + 1)); visited[2 * pos] = true; }
		if (pos - 1 >= 0 && !visited[pos - 1]) { q.push(node(pos - 1, day + 1)); visited[pos - 1] = true; }
	}

	system("pause");
	return 0;
}