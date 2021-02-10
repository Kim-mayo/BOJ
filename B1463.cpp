#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9
int dp[1000001];
int solve(int num) {

	if (num == 1)return 0;

	if (dp[num] != -1)return dp[num];

	int ret = INF;
	ret = min(ret, solve(num - 1) + 1);
	if (num % 2 == 0) {
		ret = min(ret, solve(num / 2) + 1);
	}
	if (num % 3 == 0) {
		ret = min(ret, solve(num / 3) + 1);
	}
	return dp[num] = ret;
}
int main() {
	
	for (int i = 0; i < 1000001; i++)dp[i] = -1;
	int n; cin >> n;
	cout << solve(n);

}