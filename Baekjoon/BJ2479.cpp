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
	cin >> N >> K; //����, ����

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

	// �Ÿ��� 1�� �ڵ���� ������ķ� ����ϱ�
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

	// ���͸� �̿��ؼ� bfs
	// ������ ����������(last code ndex)�� ������ �ٸ� �ڵ���� �߰��س����鼭 bfs
	// ������(to) �� �����ϸ� �����ϰ� ��� ���
	bool check = false;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		int lastcodeindex = here.back();
		int pathlength = here.size();
		for (int i = 0; i < adj[lastcodeindex].size(); i++) {
			int nextcode = adj[lastcodeindex][i];
			if (find(here.begin(), here.end(), nextcode) != here.end()) continue;// ��ο� �ߺ� ����
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

// �̹���� �޸��ʰ��� ���Ҽ������°�
// ���� �����޴�
// ��θ� ã�ư��µ��� �ߺ��� üũ�ϴ°� �Ӹ��ƴ϶�
// ��α��̰� 2�϶� 3����带 �����ϴ°� �����ϴٸ�
// ���̰� 3 �̻��ΰ�� 3����带 ���Խ�ų ������ ����
// 3�� ��尡 �信 ���ԵǾ��ִٸ� 2��° �ڸ��� 3�� ���°� ���� ���̰� ª�����̹Ƿ�
// �̷������� Ž�� ���̸� Ȯ �ٿ���
// �޸�&�ð��ʰ��� �ذ��޴�


