#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9
typedef long long ll;
vector<vector<pair<int, ll>>>adj;
int dist[501];

int main() {

	int n, m; cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int s, e; ll t; cin >> s >> e >> t;
		adj[s].push_back({ e,t });
	}
	//dist[1] = 0;
	bool cycle = false;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[j] == INF)continue;
			for (int k = 0; k < adj[j].size(); k++) {
				int _next = adj[j][k].first;
				ll _time = adj[j][k].second;

				if (dist[_next] > dist[j] + _time) {
					dist[_next] = dist[j] + _time;
					if (i == n - 1) cycle = true;
				}
			}
		}
	}

	if (cycle == true) cout << "-1";
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF) cout << "-1\n";
			else cout << dist[i] << "\n";
		}
	}

}