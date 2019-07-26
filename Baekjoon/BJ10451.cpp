#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

vector<bool>current_visited; 
vector<bool>total_visited;

bool innerdfs(int start) {
	bool cycle = false;
	for (int i = 0; i < adj[start].size(); i++) {
		int there = adj[start][i];
		if (!total_visited[there]) {
			total_visited[there] = true;
			current_visited[there] = true;
			innerdfs(there);
		}
		if (current_visited[there]) {
			cycle = true;
		}
	}
	return cycle;
}

bool dfs(int start) {
	bool result = false;;
	for (int i = 0; i < adj[start].size(); i++) {
		int there = adj[start][i];
		if (!total_visited[there]) {
			total_visited[there] = true;
			current_visited[there] = true;
			result = innerdfs(there);
		}
	}
	return result;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		int cycle = 0;
		int N;
		cin >> N;
		adj = vector<vector<int>> (N + 1);
		total_visited= vector<bool>(N + 1, false);
		for (int i = 1; i <= N; i++) {
			int a;
			cin >> a;
			adj[i].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			current_visited = vector<bool>(N + 1, false);
			if (!total_visited[i]) {
				if (dfs(i)) {
					cycle++;
				}
			}
		}
		cout << cycle << endl;
	}

	system("pause");
	return 0;
}