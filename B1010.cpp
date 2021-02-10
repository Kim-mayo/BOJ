#include <iostream>
using namespace std;

int dp[31][31];
int solution(int n,int r) {

	if (r == 0) return 1;
	if (n == r) return 1;

	if (dp[n][r] != -1) return dp[n][r];

	dp[n][r] = solution(n - 1, r - 1) + solution(n - 1, r);

	return dp[n][r];
}
int main() {

	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			dp[i][j] = -1;
		}
	}

	int t; cin >> t;
	for (int i = 0; i < t; i++) {

		int a, b; cin >> a >> b;
		
		cout << solution(b,a) << "\n";
	}

}