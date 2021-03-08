#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define mod %10007
int dp[1001];
int solve(int num) {

	if (num == 1)return dp[1] = 1;
	if (num == 2) return dp[2] = 2;

	if (dp[num] != -1)return dp[num];
	return dp[num] = (solve(num - 1) + solve(num - 2))mod;
}
void input() {

	memset(dp, -1, sizeof(dp));
	int n; cin >> n;
	solve(n);
	cout << (dp[n])mod;
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();

}