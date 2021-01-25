#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int start, des;
vector <vector < pair <int, int>>> adj;

int Dijkstra(int start) {

	priority_queue<pair<int, int>>pq;
	vector<int>dist(n + 1, 987654321);
	pq.push({ 0,start });

	while (!pq.empty()) {

		auto curr = pq.top();
		pq.pop();

		if (dist[curr.second] != 987654321)continue;
		dist[curr.second] = -curr.first;
		if (curr.second == des) return dist[des];


		for (int i = 0; i < adj[curr.second].size(); i++) {
			int next_vertex = adj[curr.second][i].first;
			int weight = adj[curr.second][i].second;

			if (dist[next_vertex] != 987654321)continue;
			pq.push({ curr.first - weight,next_vertex });

		}
			
	}

	return dist[des];
}

int main() {

	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		adj[s].push_back({ e,cost });
	}
	 cin >> start >> des;

	 int cost = Dijkstra(start);
	if (cost == 987654321) cout << "INF";
	else cout << cost;

	return 0;
	
}