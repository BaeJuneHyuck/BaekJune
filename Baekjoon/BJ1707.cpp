#include <stdio.h>
#include <vector>
#pragma warning(disable:4996);
using namespace std;

vector<vector<int>> adj;
vector<int> color; // 0 == not visited

void dfs(int start, int c) {
	color[start] = c;
	for (int i = 0; i < adj[start].size(); i++) {
			int there = adj[start][i];
			if (!color[there]) {
				dfs(there, 3 - c);
			}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int V, E;
		scanf("%d %d", &V, &E);
		adj = vector<vector<int>> (V+1);
		color = vector<int>(V + 1, 0);

		for (int i = 0; i < E; i++) {
			int v1, v2;
			//cin >> v1 >> v2;
			scanf("%d %d", &v1, &v2);
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
	
		for (int i = 1; i <= V; i++) {
			if (!color[i]) {
				dfs(i,1);
			}
		}

		bool result = true;
		for (int i = 1; i <= V; i++) {
			for (int j = 0; j < adj[i].size(); j++) {
				if (color[i] == color[adj[i][j]]) {
					result = false;
					break;
				}
			}
			if (!result) break;
		}
		if (result) printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}