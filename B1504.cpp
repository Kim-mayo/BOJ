#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, e;
int v1, v2;
vector < vector < pair<int, int>>>adj;
int Dijkstra(int start,int nextvertex) {

	priority_queue<pair<int, int>>pq;
	vector < int > dist(n + 1, 987654321);

	pq.push({ 0,start });
	
	while (!pq.empty()) {

		auto curr = pq.top();
		pq.pop();
		if (dist[curr.second] != 987654321)continue;
		dist[curr.second] = -curr.first;
		

		if (curr.second == nextvertex) return dist[nextvertex];
		

		for (int i = 0; i < adj[curr.second].size(); i++) {

			int next_vertex = adj[curr.second][i].first;
			int weight = adj[curr.second][i].second;

			if (dist[next_vertex] != 987654321)continue;
			pq.push({ curr.first - weight,next_vertex });
		}

	}
	return dist[nextvertex];
}
int main() {

	cin >> n >> e;
	adj.resize(n + 1);
	for (int i = 0; i < e; +i++) {

		int a, b, cost;
		cin >> a >> b >> cost;

		adj[a].push_back({ b,cost });
		adj[b].push_back({ a,cost });

	}
	cin >> v1 >> v2;

	int costv1 = Dijkstra(1, v1);
	int costv2 = Dijkstra(1, v2);
	int costv1v2 = Dijkstra(v1, v2);
	int costv1n = Dijkstra(v1, n);
	int costv2n = Dijkstra(v2, n);

	if (costv1 == 987654321 || costv2 == 987654321 || costv1v2 == 987654321 || costv1n == 987654321 || costv2n == 987654321) cout << "-1";
	else cout << min(costv1 + costv1v2 + costv2n, costv2 + costv1v2 + costv1n);



	


}