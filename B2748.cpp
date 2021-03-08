#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define INF 1e9
#define ll long long
ll dp[91];
ll solve(int num) {
	if (num == 0) return dp[0] = 0;
	if (num == 1)return dp[1] = 1;
	if (dp[num] != -1) return dp[num];
	return dp[num] = solve(num - 1) + solve(num - 2);
}
void input() {
	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	solve(n);
	cout << dp[n];
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

}