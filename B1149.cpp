#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>home;
int n;
int dp[1001][4];
int solve(int row, int pre) {

	if (row == n)return 0;

	if (dp[row][pre] != -1) return dp[row][pre];
	
	int ret = 987654321;
	for (int i = 1; i < 4; i++) {
		if (i == pre) continue;
		ret = min(ret, solve(row + 1, i) + home[row][i]);
	}
	return dp[row][pre] = ret;
}
int main() {

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 4; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n;
	home.resize(n, vector<int>(4, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= 3; j++) {
			int a; cin >> a;
			home[i][j] = a;
		}
	}

	cout << solve(0, 0);
}