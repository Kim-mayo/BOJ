#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, c;
vector<int>home;
void binary_search(int lo,int hi) {
	int result = 0;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int before = home[0];
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (home[i] - before >= mid) {
				before = home[i];
				cnt++;
			}
		}

		if (cnt < c) hi = mid;
		else {
			result = mid;
			lo = mid + 1;
		}
	}
	cout << result;
	return;
}
int main() {

	cin >> n >> c;
	home.resize(n);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		home[i] = a;
	}
	sort(home.begin(), home.end());

	binary_search(0, 1000000000);

}