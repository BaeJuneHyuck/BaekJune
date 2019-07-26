#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class circle {
public:
	int x;
	int y;
	int r;
	circle(int _x, int _y, int _r): x(_x), y(_y), r(_r) {}
	circle() {}
};

int colorarr[3001];
circle list[3001];
int n;
int totalColor = 0;

void dfs(int i, int color) {
	colorarr[i] = color;
	circle a = list[i];

	cout << "color : ";
	for (int i = 0; i < n; i++) {
		cout << colorarr[i] << " ";
	}cout << endl;

	for (int j = 0; j < n; j++) {	
		if (i == j) continue;
		circle b = list[j];
		if (colorarr[j] == 0) {
			if ((a.r + b.r) * (a.r + b.r) >= (a.x - b.x)*(a.x - b.x) + (a.x - a.y)*(a.y - b.y)) {

				cout << i << ":" << a.x << "," << a.y << "," << a.r << endl;
				cout << j << ":" << b.x << "," << b.y << "," << b.r << endl;
				cout << i << " , " << j << " ÀÎÁ¢\n";
				dfs(j, color);
			}
		}
	}

}

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(colorarr, 0, sizeof(colorarr));
		memset(list, 0, sizeof(list));
		totalColor = 0;

		for (int i = 0; i < n; i++) {
			int  x, y, r;
			cin >> x >> y >> r;
			list[i] = circle(x, y, r);
		}

		for (int i = 0; i < n; i++) {
			if (colorarr[i] == 0) {
				dfs(i, ++totalColor);
			}
		}

		cout << totalColor << endl;
	}
	system("pause");
	return 0;
}