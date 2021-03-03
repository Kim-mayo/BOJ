#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define INF 1e9

vector < vector<pair<int, int>>>edge;
priority_queue<pair<int, int>>pq;//거리,정점
vector<int>visited;
int Daijkstra(int s) {

	visited.resize(edge.size(),INF);
	pq.push({ 0,s });

	while (!pq.empty()) {

		int dis = pq.top().first;
		int curr = pq.top().second;
		pq.pop();
		if (visited[curr] != INF)continue;
		visited[curr] = dis;
		for (int i = 0; i < edge[curr].size(); i++) {
			int next = edge[curr][i].first;
			int nedis = edge[curr][i].second;

			if (visited[next] != INF)continue;
			pq.push({ dis + nedis,next });
		}

	}
	int far = -INF;
	int index;
	for (int i = 1; i < visited.size(); i++) {
		if (far < visited[i]) {
			far = visited[i];
			index = i;
		}
	}
	return index;
}
void input() {

	int v; cin >> v;
	edge.resize(v + 1);
	for (int i = 1; i <= v; i++) {
		int v1; cin >> v1;
		while (1) {
			
			int v2; cin >> v2;
			if (v2 == -1)break;

			int dis; cin >> dis;
			edge[v1].push_back({ v2,dis });	

		}

	}

}
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	
	int i=Daijkstra(1);
	visited.clear();
	int index = Daijkstra(i);
	cout << visited[index];
}