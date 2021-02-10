#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>ele;
vector<int>lis;
int lower_bound(int target, int size) {
	
	int start = 0;
	int end = size;
	int mid = 0;

	while (end > start) {
		mid = (start + end) / 2;

		if (lis[mid] >= target) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
	}
	return end;
}
int main() {

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ele.push_back({ a,b });
	}
	sort(ele.begin(), ele.end());
	lis.push_back(ele[0].second);
	for (int i = 1; i < n; i++) {
		if (ele[i].second > lis.back()) {
			lis.push_back(ele[i].second);
		}
		else {
			int pos = lower_bound(ele[i].second, lis.size());
			lis[pos] = ele[i].second;
		}
	}
	int remove = n - lis.size();
	cout << remove;
}