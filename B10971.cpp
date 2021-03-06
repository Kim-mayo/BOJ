#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
vector<vector<int>>city;
int n;
int solve(int s,int x) {
	
	x |= (1 << s);
	if ((1 << n) - 1 == x)return city[s][0];
	int ret = INF;
	for (int i = 0; i < n; i++) {
		if (x & (1 << i))continue;
		if (city[s][i]== INF)continue;
		ret = min(ret, city[s][i] + solve(i, x));
	}
	x &= ~(1 << s);

	return ret;

}
void input() {

	cin >> n;
	city.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a;
			if (a == 0)a = INF;
			city[i].push_back(a);
		}
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve(0, 0);
}