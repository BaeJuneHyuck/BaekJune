#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool strComp(const string a, const string b) {
	if (a.length() == b.length()) return a < b;
	return a.length() < b.length();
}

int main() {
	int N;
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(),strComp);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto iter = v.begin(); iter < v.end(); iter++) {
		cout << *iter<<endl;
	}

	system("pause");
	return 0;
}