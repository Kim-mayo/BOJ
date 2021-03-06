#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9
int n, k;
vector<vector<int>>planet;
vector<bool>visited;
vector < vector<bool>>visit;
void Floyd() {

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j)continue;
				if (planet[i][j] > planet[i][k] + planet[k][j]) {
					planet[i][j] = planet[i][k] + planet[k][j];
				}
			}
		}
	}

}
int solve(int s,int x) {

	x |= (1 << s);
	if ((1 << n) - 1 == x)return 0;

	int ret = INF;
	for (int i = 0; i < n; i++) {

		if (x & (1 << i))continue;
		ret = min(ret, planet[s][i]+solve(i, x)); 

	}
	x &= ~(1 << s);
	return ret;

 }
void input() {
	cin >> n >> k;
	planet.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int a; cin >> a; 
			planet[i].push_back(a);
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	Floyd();
	cout << solve(k, 0);
	
}