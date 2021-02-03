#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,sum,sumax;
vector<vector<int>>tri;
int dp[501][501];
int solve(int row, int col) {
	if (row == n)return 0;

	if (dp[row][col] != -1) { return dp[row][col]; }

	int ret = 0;
	ret = max(solve(row + 1, col), solve(row + 1, col + 1));
	ret += tri[row][col];
	return dp[row][col] = ret;
}
int main() {

	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n;
	tri.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			int num; cin >> num;
			tri[i].push_back(num);
		}
	}
	cout << solve(0, 0);
}