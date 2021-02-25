#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9;
int n, x;
int floyd[1001][1001];
void Floyd_washall() {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
					floyd[i][j] = floyd[i][k] + floyd[k][j];
				}
			}
		}
	}

}
void input() {

	int m; cin >> n >> m >> x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)floyd[i][j] = 0;
			else floyd[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		floyd[a][b] = c;
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	Floyd_washall();
	int dis = -1;
	for (int i = 1; i <= n; i++) {
		if (i == x)continue;
		dis = max(dis, floyd[i][x] + floyd[x][i]);
	}
	cout << dis;

}