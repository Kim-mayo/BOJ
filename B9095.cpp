#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define INF 1e9
int dp[12];
int solve(int num) {
	if (num == 1)return dp[1]=1;
	if (num == 2)return dp[2]=2;
	if (num == 3) return dp[3]=4;

	if (dp[num] != -1)return dp[num];
	return dp[num] = solve(num-1)+solve(num-2)+solve(num-3);

}
void input() {
	memset(dp, -1, sizeof(dp));
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int	n; cin >> n;
		solve(n);
		cout << dp[n]<<"\n";
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

}