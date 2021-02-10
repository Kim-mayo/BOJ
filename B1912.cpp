#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF -1e9
int n;
vector<int>arr;
int dp[100001];
int solve() {
	
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	int big = INF;
	for (int i = 0; i < n; i++) {
		big = max(big, dp[i]);
	}
	return big;
}
int main() {

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		arr.push_back(a);
	}
	cout << solve();
}