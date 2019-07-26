#include <iostream>
#include <vector>

using namespace std;

int connected = 0;
int N, M;
vector<vector<int>> adj;
vector<bool> visited;

void bfs(int start) {
	if (visited[start])return;
	connected++;
	vector<int> stack;
	stack.push_back(start);
	visited.at(start) = true;
	while (!stack.empty()) {
		int here = stack.back();
		stack.pop_back();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
			if (!visited[there]) {
				visited[there] = true;
				stack.push_back(there);
			}
		}
	}
}

int main() {
	cin >> N >> M;
	adj = vector<vector<int>>(N + 1);
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	visited = vector<bool>(N + 1, false);
	for (int i = 1; i <= N; i++) {
		bfs(i);
	}

	cout << connected;
	system("pause");
	return 0;
}