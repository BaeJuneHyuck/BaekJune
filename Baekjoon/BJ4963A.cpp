#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int w, h;
int arr[51][51];
int colorarr[51][51];

int main() {
	while (cin >> w >> h) {
		if (w == 0 && h == 0)break;
		int color = 1;
		vector<tuple<int, int>> queue;
		memset(arr, 0, sizeof(colorarr));
		
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 1) {
					queue.push_back(make_tuple(i, j));
				}
			}
		}
		while (!queue.empty()) {
			tuple<int, int > here = queue.back();
			queue.pop_back();
			int x = get<0>(here);
			int y = get<1>(here);
			int nextx, nexty;
			int dx[8] = { 0, 1, 1, 1, 0, -1, -1 ,-1 };
			int dy[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

			colorarr[x][y] = color;

			bool color = true;
			for (int i = 0; i < 8; i++) {
				nextx = x + dx[i];
				nexty = y + dy[i];
				if (colorarr[nextx][nexty] != 0)continue;
				if (nextx < 0 || nextx >= w || nexty < 0 || nexty >= h) continue;
				queue.push_back(make_tuple(nextx, nexty));
				color = false;
			}
			if (!false) color++;
		}

		cout << color << endl;
	}


	system("pause");
	return 0;
}