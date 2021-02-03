#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF -1e9
int n;
vector<int>stair;
int dp[301][3];
int solve(int row, int seq) {

	if (row == n)return stair[row];
	else if (row > n) return INF;

	if (dp[row][seq] != -1) return dp[row][seq];

	int ret = INF;
	if (seq < 2) {
		ret = max(ret, solve(row + 1, seq + 1));
	}
	ret = max(ret, solve(row + 2, 1));
	ret += stair[row];
	return dp[row][seq] = ret;
}
int main() {

	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n;
	stair.resize(n + 1,0);
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		stair[i] = a;
	}
	cout << solve(0, 0);
}