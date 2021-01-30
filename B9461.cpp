#include <iostream>
using namespace std;

int main() {

	long long dp[101] = { 1,1,1,2,2 };
	for (int i = 5; i < 101; i++) dp[i] = dp[i - 1] + dp[i - 5];
	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int num; cin >> num;
		cout << dp[num - 1] << "\n";
	}
}