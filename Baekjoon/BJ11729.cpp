#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
vector<tuple<int, int>> totalvec;
vector<tuple<int, int>> subvec[4][4][21];
bool vecbool[4][4][21] = { false, };

vector<tuple<int,int>>&  hanoi(int from, int to, int n) {
	//cout << from << "," << to << "," << n << endl;
	if (vecbool[from][to][n]) {
		cout<<"ÀçÈ°¿ë : " << from << "," << to << "," << n << endl;
		//totalvec.insert(totalvec.end(), subvec[from][to][n].begin(), subvec[from][to][n].end());
		return subvec[from][to][n];
	}

	vecbool[from][to][n] = true;
	if (n == 1) {
		subvec[from][to][n].push_back(make_tuple(from, to));
		return subvec[from][to][n];
	}

	vector<tuple<int, int>> temp1 = hanoi(from, 6 - from - to, n - 1);
	subvec[from][to][n].insert(subvec[from][to][n].end(), temp1.begin(), temp1.end());
	subvec[from][to][n].push_back(make_tuple(from, to));
	vector<tuple<int, int>> temp2 =  hanoi(6 - from - to, to, n - 1);
	subvec[from][to][n].insert(subvec[from][to][n].end(), temp2.begin(), temp2.end());

	return subvec[from][to][n];
}

int main() {
	int N;
	scanf_s("%d", &N);
	totalvec = hanoi(1, 3, N);

	printf("%d\n", totalvec.size());
	for (auto iter = totalvec.begin(); iter < totalvec.end(); iter++) {
		printf("%d %d\n" ,get<0>(*iter), get<1>(*iter));
	}

	system("pause");
	return 0;
}


/*
int hanoi(int from, int to, int n) {
	if (n == 1) {
		vec.push_back(make_tuple(from, to));
		return 0;
	}

	hanoi(from, 6 - from - to, n - 1);
	vec.push_back(make_tuple(from, to));
	hanoi(6 - from - to,to, n - 1);
	return 0;
}

*/
