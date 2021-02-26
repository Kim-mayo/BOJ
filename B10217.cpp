#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e15
#define ll long long
int n, m;
vector<vector<pair<int, pair<int, ll>>>>ticket;//다음공항,비용,시간
ll Daijkstra() {

	priority_queue<pair<ll, pair<int, int>>>pq;//소요시간,비용,다음갈공항
	vector<vector<ll>>dist(n + 1, vector<ll>(m + 1, INF));
	dist[1][0] = 0ll;

	pq.push({ 0ll,{0,1} });

	while (!pq.empty()) {

		auto curr = pq.top();
		ll time = curr.first;
		int cost = curr.second.first;
		int airp = curr.second.second;
		pq.pop();
		for (int i = 0; i < ticket[airp].size(); i++) {
			int nairp = ticket[airp][i].first;
			int ncost = ticket[airp][i].second.first;
			ll ntime = ticket[airp][i].second.second;
			if (-cost + ncost > m)continue;
			if (dist[nairp][-cost + ncost] <=ntime - time)continue;
			pq.push({ time - ntime,{cost - ncost,nairp} });
			dist[nairp][-cost + ncost] = ntime - time;
		}

	}
	ll small = INF;
	for (int i = 0; i <= m; i++) {
		small = min(small, dist[n][i]);
	}
	if (small == INF) return -1;
	else return small;
}
void input() {

	int k; cin >> n >> m >> k;
	ticket.resize(n + 1);
	for (int i = 0; i < k; i++) {
		int u, v, c;
		ll d; cin >> u >> v >> c >> d;
		ticket[u].push_back({ v,{c,d} });
	}

}
int main() {

	ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {

		input();
		ll ans = Daijkstra();
		if (ans == -1) {
			cout << "Poor KCM\n";
		}
		else cout << ans << "\n";
		ticket.clear();
		
	}
	
}