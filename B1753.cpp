#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int,int>>> adj;
int v, e;
priority_queue <pair<int, int>>pq;

void Dijkstra(int start) {

	vector<int>dist(v + 1, 987654321);
	pq.push({ 0,start });

	while (!pq.empty()) {

		auto curr = pq.top();
		pq.pop();

		if (dist[curr.second] != 987654321)continue;
		dist[curr.second] = -curr.first;

		for (int i = 0; i < adj[curr.second].size(); i++) {
			int next_vertex = adj[curr.second][i].first;
			int weight = adj[curr.second][i].second;

			if (dist[next_vertex] != 987654321) continue;
			pq.push({ curr.first - weight,next_vertex });
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == 987654321) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

}

int main() {

	cin >> v >> e;
	int start; cin >> start;
	adj.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	Dijkstra(start);

	return 0;

}