#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>>work;//걸리는 일수, 비용
int dp[16]; //그날 가장큰값
int solution(int day) {

	if (day == n+1) return 0;
	
	if (dp[day] != -1)return dp[day];
	int ret = 0;
	if (work[day - 1].first <= n - day+1) {
		ret = max(ret,solution(day+work[day-1].first)+ work[day - 1].second);

	}
	ret = max(ret, solution(day+1));
	return dp[day] = ret;
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) dp[i] = -1;
	
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		work.push_back({ a,b });
	}
	cout << solution(1);
}