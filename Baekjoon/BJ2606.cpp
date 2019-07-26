#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int main() {
	int V, E;
	cin >> V >> E;

	visited = vector<bool>(V+1, false);
	adj = vector <vector<int>>(V + 1);
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//bfs
	vector<int> s;
	s.push_back(1);
	visited[1] = true;
	int count = 0;
	while (!s.empty()) {
		int here = s.back();
//		cout <<"here : "<< here << endl;
		s.pop_back();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i];
//			cout << "there : " << there << endl;
			if (!visited[there]) {
				count++;
				s.push_back(there);
				visited[there] = true;
			}
		}
	}
	
	cout << count;

	system("pause");
	return 0;
}