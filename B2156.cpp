#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF -1e9
int n;
vector<int>glass;
int dp[10001][3];
int solve(int row, int seq) {

	if (row>=n)return 0;

	if (dp[row][seq] != -1)return dp[row][seq];

	int ret = INF;
	if (seq < 2) {//1,0
		ret = max(ret,glass[row] + solve(row + 1, seq + 1));
	}
	ret = max(ret, solve(row + 1, 0));
	
	return dp[row][seq] = ret;
}
int main() {

	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n;
	glass.resize(n,0);
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		glass[i] = a;
	}
	cout << solve(0, 0);
}