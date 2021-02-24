#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1e9
int n;
long long floyd[101][101];
void Floyd_washall() {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
					floyd[i][j] = floyd[i][k] + floyd[k][j];
				}

			}
		}
	}

}
void input() {

	int m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j){
				floyd[i][j] = 0;
				continue;
		    }
			floyd[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		long long w; cin >> u >> v >> w;
		floyd[u][v] = min(w, floyd[u][v]);
	}

}
int main() {

	input();
	Floyd_washall();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (floyd[i][j] == INF) cout << "0 ";
			else cout << floyd[i][j] << " ";
		}
		cout << "\n";
	}

}