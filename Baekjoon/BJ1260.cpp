#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<int>> adj;// 인접 리스트
vector<bool> visited;

void dfs(int s) {
	cout << s << " ";
	visited[s] = true;
	for (int i = 0; i < adj[s].size(); i++) {
		int there = adj[s][i];
		if (!visited[ there ] ) {
			dfs( there );
		}
	}
}

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		cout << n << " ";
		for (int i = 0; i < adj[n].size(); i++) {
			int there = adj[n][i];
			if (!visited[there]) {
				q.push(there);
				visited[there] = true;
			}
		}
	}
}

int main() {
	int N, M, V;
	cin >> N >> M >> V;
	adj = vector<vector<int>>(N+1);
	visited = vector<bool>(N + 1);
	
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < N; i++) {
		sort(adj[i].begin(), adj[i].end());
	}
	dfs(V);
	cout << endl;
	visited = vector<bool>(N + 1);
	bfs(V);

	system("pause");
	return 0;
}