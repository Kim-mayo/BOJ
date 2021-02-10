#include <iostream>
using namespace std;

int dp[1001][1001];
int Solution(int n, int r) {

	if (r == 0) return 1;
	if (n == r) return 1;
	if (dp[n][r] != -1) return dp[n][r];

	dp[n][r] = Solution(n - 1, r - 1) + Solution(n - 1, r);
	dp[n][r] %= 10007;
	return dp[n][r];
}
int main() {

	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	int a, b; cin >> a >> b;
	cout << Solution(a, b) % 10007;

}