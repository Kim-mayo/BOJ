#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9
vector<vector<pair<int, int>>>adj;
int dist[501];
int main() {

	int tc; cin >> tc;

	while (tc--) {

		int n, m, w; cin >> n >> m >> w;
		for (int i = 0; i < n; i++) dist[i] = INF;
		adj.clear();
		adj.resize(n+1);
		for (int i = 0; i < m; i++) {
			int s, e, t; cin >> s >> e >> t;
			adj[s].push_back({ e,t });
			adj[e].push_back({ s,t });
		}

		for (int i = 0; i < w; i++) {
			int s, e, t; cin >> s >> e >> t;
			adj[s].push_back({ e,-t });
		}
		bool cycle = false;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k < adj[j].size(); k++) {
					int _next = adj[j][k].first;
					int _time = adj[j][k].second;

					if (dist[_next] > dist[j] + _time) {
						if (i == n - 1) cycle = true;
						dist[_next] = dist[j] + _time;
					}
				}
			}
		}

		if (cycle) cout << "YES\n";
		else cout << "NO\n";

	}

}