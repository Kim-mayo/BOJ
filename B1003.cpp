#include <iostream>
#include <utility>
using namespace std;

pair<long long,long long>dp[50];
pair<long long,long long> solve(int num) {

	if (num == 0) return { 1,0 };
	if (num == 1)return { 0,1 };

	if (dp[num].first != -1) {
		return dp[num];
	}

	pair<long long, long long> ret1 = solve(num - 1);
	pair<long long, long long> ret2 = solve(num - 2);

	return dp[num] = { ret1.first + ret2.first , ret1.second + ret2.second };

}
int main() {

	for (int i = 0; i < 50; i++)dp[i] = { -1, -1 };
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		pair<long long, long long > ret = solve(n);
		cout << ret.first << " " << ret.second << "\n";
	}

}
