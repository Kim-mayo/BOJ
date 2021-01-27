#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>>pos;
int main() {

	int n; cin >> n;
	pos.resize(n);
	for (int i = 0; i < n; i++) {

		int x, y; cin >> x >> y;
		pos[i] = { y,x };

	}
	sort(pos.begin(), pos.end());

	for (int i = 0; i < n; i++) {

		cout << pos[i].second << " " << pos[i].first << "\n";

	}

}