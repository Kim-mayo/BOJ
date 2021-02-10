#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	int n; cin >> n;
	vector<pair<int, int>>meet;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		meet.push_back({ b,a });
	}
	sort(meet.begin(), meet.end());
	
	int end = -1;
	int cnt = 0;
	for (int i = 0; i < meet.size(); i++) {

		if (meet[i].second >= end) {
			end = meet[i].first;
			cnt++;
		}

	}
	cout << cnt;

}