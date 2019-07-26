#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int N, K, from, to;
vector<vector<int>> adj;
string list[1002];
int dp[1002];

int main() {
	cin >> N >> K; //갯수, 길이

	for (int i = 1; i <= N; i++) {
		cin >> list[i];
	}

	cin >> from >> to;
	queue<vector<int>> q;
	vector<int> init;
	init.push_back(from);
	q.push(init);
	adj = vector<vector<int>>(N + 2);

	memset(dp, -1, sizeof(dp));
	dp[from] = 0;

	// 거리가 1인 코드들을 인접행렬로 기억하기
	for (int a = 1; a <= N; a++) {
		for (int b = a + 1; b <= N; b++) {
			int result = 0;
			for (int i = 0; i < K; i++) {
				if (list[a][i] != list[b][i])result++;
			}
			if (result == 1) {
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
	}

	// 벡터를 이용해서 bfs
	// 벡터의 마지막원소(last code ndex)와 인접한 다른 코드들을 추가해나가면서 bfs
	// 목적지(to) 에 도착하면 종료하고 경로 출력
	bool check = false;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int lastcodeindex = here.back();
		int pathlength = here.size();
		for (int i = 0; i < adj[lastcodeindex].size(); i++) {
			int nextcode = adj[lastcodeindex][i];
			if (find(here.begin(), here.end(), nextcode) != here.end()) continue;// 경로에 중복 방지
			if (dp[nextcode] != -1 && dp[nextcode] < pathlength)continue;
			if (nextcode == to) {
				check = true;
				for (int j = 0; j < here.size(); j++) {
					cout << here[j] << " ";
				}
				cout << nextcode <<endl;
				break;
			}
			dp[nextcode] = pathlength;
			here.push_back(nextcode);
			q.push(here);
			here.pop_back();
		}
		if (check) break;
	}

	if (!check)cout << "-1";

	system("pause");
	return 0;
}

// 이방법은 메모리초과를 피할수가없는가
// ㄴㄴ 가능햇다
// 경로를 찾아가는도중 중복을 체크하는것 뿐만아니라
// 경로길이가 2일때 3번노드를 포함하는게 가능하다면
// 길이가 3 이상인경우 3번노드를 포함시킬 이유가 없음
// 3번 노드가 답에 포함되어있다면 2번째 자리에 3이 들어가는게 가장 길이가 짧을것이므로
// 이런식으로 탐색 깊이를 확 줄여서
// 메모리&시간초과를 해결햇다


