#include <iostream>
#include <vector>
using namespace std;
vector<int>set;
vector<int>dp;
int main() {
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	set.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		set[i] = a;
	}

	for (int i = 0; i < N; i++) {
		int curr = set[i];
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (set[j] < curr) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
		}
	}
	int big = -1;
	for (int i = 0; i < N; i++) {
		if (dp[i] > big) big = dp[i];
	}
	cout << big;
}