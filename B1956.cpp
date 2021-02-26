#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1e9
int v;
vector<vector<int>>floyd;
void Floyd_washall() {

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
					floyd[i][j] = floyd[i][k] + floyd[k][j];
				}
			}
		}
	}

}
void input() {

	int e; cin >> v >> e;
	floyd.resize(v + 1, vector<int>(v + 1, INF));
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j)floyd[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		floyd[a][b] = c;
	}
	

}
int main() {

	ios_base::sync_with_stdio(false);
	input();
	Floyd_washall();
	int shortest = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (floyd[i][j] == INF || floyd[j][i] == INF)continue;
			if (i == j)continue;
			shortest = min(floyd[i][j] + floyd[j][i], shortest);
		}
	}
	if (shortest == INF)cout << "-1";
	else cout << shortest;
}