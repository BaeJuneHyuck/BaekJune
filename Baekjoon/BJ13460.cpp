// Ʋ��

#include <iostream>
#include <queue>
using namespace std;
char map[11][11];
bool visit[11][11][11][11]; // rx,ry,bx,by;
int N,M,rx,ry,bx,by,gx,gy;
int test;
class status {
public:
	int rx, ry, bx, by, count;
	char command;
	status(
		int rx, int ry, int bx, int by, int count, char c):
		rx(rx), ry(ry), bx(bx), by(by), count(count), command(c) {}
};

queue<status> q;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') { rx = j, ry = i; }
			if (map[i][j] == 'B') { bx = j, by = i; }
			if (map[i][j] == 'O') { gx = j, gy = i; }
		}
	}
	visit[rx][ry][bx][by] = true;
	q.push(status(rx, ry, bx, by, 1, 'u'));
	q.push(status(rx, ry, bx, by, 1, 'd'));
	q.push(status(rx, ry, bx, by, 1, 'r'));
	q.push(status(rx, ry, bx, by, 1, 'l'));
	while (!q.empty()) {
		status f = q.front();
		q.pop();
		//cout << "��Ȳ:[" << f.rx << "," << f.ry << "][" << f.bx << "," << f.by << "]/" 
		//	<< f.count <<" ���:"<<f.command<< endl;
		if (f.count == 11) {
			cout << "-1";
			break;
		}
		int prevRx = f.rx, prevRy = f.ry, prevBx = f.bx, prevBy = f.by;
		int nextRx = f.rx, nextRy = f.ry, nextBx = f.bx, nextBy = f.by;
		bool Rout = false, Bout = false;
		while (1) {
			// ���̻� �������� ���������� �ش�������� �̵�
		//	cout << "\t" <<nextRx<<","<<nextRy<<","<<nextBx<<","<<nextBy<<endl;
			switch (f.command) {
			case'd':
				// �̵��� ������ ���� �ƴϰ�, ������ ��ġ�� ������ �̵�����
				if (map[prevRy + 1][prevRx] != '#' && !(prevRy+1 == prevBy && prevRx == prevBx) ) {
					nextRy = prevRy + 1; nextRx = prevRx;
				}
				if (map[prevBy + 1][prevBx] != '#' && !(prevRy== prevBy + 1 && prevRx == prevBx)) {
					nextBy = prevBy + 1; nextBx = prevBx;
				}
				break;
			case'u':
				if (map[prevRy - 1][prevRx] != '#' && !(prevRy - 1 == prevBy && prevRx == prevBx)) {
					nextRy = prevRy - 1; nextRx = prevRx;
				}
				if (map[prevBy - 1][prevBx] != '#' && !(prevRy== prevBy-1 && prevRx == prevBx)) {
					nextBy = prevBy - 1; nextBx = prevBx;
				}
				break;
			case'r':
				if (map[prevRy][prevRx+1] != '#' && !(prevRy == prevBy && prevRx+1 == prevBx)) {
					nextRy = prevRy; nextRx = prevRx + 1;
				}
				if (map[prevBy][prevBx + 1] != '#' && !(prevRy == prevBy && prevRx == prevBx+1)) {
					nextBy = prevBy; nextBx = prevBx + 1;
				}
				break;
			case'l':
				if (map[prevRy][prevRx - 1] != '#' && !(prevRy == prevBy && prevRx - 1 == prevBx)) {
					nextRy = prevRy; nextRx = prevRx - 1;
				}
				if (map[prevBy][prevBx - 1] != '#' && !(prevRy == prevBy && prevRx == prevBx - 1)) {
					nextBy = prevBy; nextBx = prevBx - 1;
				}
				break;
			}
			// �̵��� ���� �������ִ°�� out�� true, �������� �����°�쿩�� ���ᰡ��
			if (nextRx == gx && nextRy == gy) {
				Rout = true; //cout << "����Ż�Ⱑ��\n";
			}
			if (nextBx == gx && nextBy == gy) {
				Bout = true; //cout << "�İ� Ż�Ⱑ��\n";
			}
			// ���̻� ��ȭ�� ������� �̵� ����
			if (prevRx == nextRx && prevRy == nextRy && prevBx == nextBx && prevBy == nextBy) break;
			prevRx = nextRx;
			prevRy = nextRy;
			prevBx = nextBx;
			prevBy = nextBy;
		}// �̵� ����

		if (Rout && !Bout) { cout << f.count; break; }
		//else if (Bout){}
		else {
			if (!visit[nextRx][nextRy][nextBx][nextBy]) {
				visit[nextRx][nextRy][nextBx][nextBy] = true;
				if (f.command == 'u' || f.command == 'd') {
					q.push(status(nextRx, nextRy, nextBx, nextBy, f.count + 1, 'r'));
					q.push(status(nextRx, nextRy, nextBx, nextBy, f.count + 1, 'l'));
				}
				else {
					q.push(status(nextRx, nextRy, nextBx, nextBy, f.count + 1, 'u'));
					q.push(status(nextRx, nextRy, nextBx, nextBy, f.count + 1, 'd'));
				}
			}
		}
	}
	return 0;
}