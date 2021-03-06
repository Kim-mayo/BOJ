#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<int>pre;
void solve(int l, int r) {
	if (l > r)return;

	int root = pre[l];
	int lindex = -1;
	int rindex = -1;
	for (int i = l + 1; i <= r; i++) {
		if (pre[i] > root) {
			if (rindex == -1) {
				rindex = i; break;
			}
		}
		if (pre[i] < root) {
			lindex = i;
		}
	}
	if (lindex != -1) {
		solve(l + 1, lindex);
	}
	if (rindex != -1) {
		solve(rindex, r);
	}
	cout << root << "\n";
	return;
}
void input() {

	while (1) {
		int a; cin >> a;
		if (cin.eof())break;
		pre.push_back(a);
	}
	/*int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		pre.push_back(a);
	}*/
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve(0, pre.size() - 1);

}